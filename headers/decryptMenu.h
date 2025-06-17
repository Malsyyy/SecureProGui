#pragma once
using namespace System;
using namespace System::IO;
using namespace System::Windows::Forms;
using namespace System::Runtime::InteropServices;

#include <openssl/evp.h>
#include <openssl/rand.h>
#include <openssl/err.h>
#pragma comment(lib, "libcrypto.lib")

namespace WindowsForm {

	public ref class decryptMenu : public System::Windows::Forms::Form
	{
	public:
		decryptMenu(void)
		{
			InitializeComponent();
		}

	protected:
		~decryptMenu()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		Button^ browseBtn;
		Button^ decryptBtn;
		Button^ logoutBtn;
		Button^ exitBtn;
		RichTextBox^ fileBox;
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->browseBtn = gcnew Button();
			this->decryptBtn = gcnew Button();
			this->logoutBtn = gcnew Button();
			this->exitBtn = gcnew Button();
			this->fileBox = gcnew RichTextBox();
			this->SuspendLayout();

			// browseBtn
			this->browseBtn->Location = System::Drawing::Point(30, 30);
			this->browseBtn->Size = System::Drawing::Size(75, 23);
			this->browseBtn->Text = L"Browse";
			this->browseBtn->Click += gcnew EventHandler(this, &decryptMenu::browseBtn_Click);

			// decryptBtn
			this->decryptBtn->Location = System::Drawing::Point(30, 70);
			this->decryptBtn->Size = System::Drawing::Size(75, 23);
			this->decryptBtn->Text = L"Decrypt";
			this->decryptBtn->Click += gcnew EventHandler(this, &decryptMenu::decryptBtn_Click);

			// logoutBtn
			this->logoutBtn->Location = System::Drawing::Point(30, 110);
			this->logoutBtn->Size = System::Drawing::Size(75, 23);
			this->logoutBtn->Text = L"Logout";

			// exitBtn
			this->exitBtn->Location = System::Drawing::Point(30, 150);
			this->exitBtn->Size = System::Drawing::Size(75, 23);
			this->exitBtn->Text = L"Exit";
			this->exitBtn->Click += gcnew EventHandler(this, &decryptMenu::exitBtn_Click);

			// fileBox
			this->fileBox->Location = System::Drawing::Point(120, 30);
			this->fileBox->Size = System::Drawing::Size(300, 23);
			this->fileBox->ReadOnly = true;

			// decryptMenu Form
			this->ClientSize = System::Drawing::Size(450, 220);
			this->Controls->Add(this->browseBtn);
			this->Controls->Add(this->decryptBtn);
			this->Controls->Add(this->logoutBtn);
			this->Controls->Add(this->exitBtn);
			this->Controls->Add(this->fileBox);
			this->Text = L"Decrypt File";
			this->ResumeLayout(false);
		}
#pragma endregion

	private: System::Void browseBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();
		openFileDialog->Title = "Select Encrypted File";
		openFileDialog->Filter = "Encrypted Files (*.enc)|*.enc|All Files (*.*)|*.*";

		if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			fileBox->Text = openFileDialog->FileName;
		}
	}

	private: System::Void decryptBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ filePath = fileBox->Text;

		if (String::IsNullOrWhiteSpace(filePath)) {
			MessageBox::Show("Please select a file to decrypt.");
			return;
		}

		try {
			// Read encrypted file
			array<Byte>^ encryptedData = File::ReadAllBytes(filePath);
			int encLen = encryptedData->Length;

			pin_ptr<Byte> encPtr = &encryptedData[0];
			unsigned char* encBytes = encPtr;

			// Same static key/IV used in encryption
			unsigned char key[32] = {
				'0','1','2','3','4','5','6','7',
				'8','9','0','1','2','3','4','5',
				'6','7','8','9','0','1','2','3',
				'4','5','6','7','8','9','0','1'
			};

			unsigned char iv[16] = {
				'0','1','2','3','4','5','6','7',
				'8','9','0','1','2','3','4','5'
			};

			int maxOutputLen = encLen; // decrypted output will be <= encrypted
			unsigned char* decrypted = new unsigned char[maxOutputLen];
			int outLen1 = 0, outLen2 = 0;

			EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
			if (!ctx) throw gcnew Exception("Failed to create cipher context.");

			if (1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
				throw gcnew Exception("EVP_DecryptInit_ex failed");

			if (1 != EVP_DecryptUpdate(ctx, decrypted, &outLen1, encBytes, encLen))
				throw gcnew Exception("EVP_DecryptUpdate failed");

			if (1 != EVP_DecryptFinal_ex(ctx, decrypted + outLen1, &outLen2))
				throw gcnew Exception("EVP_DecryptFinal_ex failed");

			EVP_CIPHER_CTX_free(ctx);

			// Save decrypted file
			SaveFileDialog^ saveDialog = gcnew SaveFileDialog();
			saveDialog->Title = "Save Decrypted File";
			saveDialog->Filter = "Text Files (*.txt)|*.txt|All Files (*.*)|*.*";
			saveDialog->FileName = Path::GetFileNameWithoutExtension(filePath) + "_decrypted.txt";

			if (saveDialog->ShowDialog() != System::Windows::Forms::DialogResult::OK) {
				delete[] decrypted;
				MessageBox::Show("Save cancelled.");
				return;
			}

			String^ outputPath = saveDialog->FileName;
			array<Byte>^ outputData = gcnew array<Byte>(outLen1 + outLen2);
			Marshal::Copy(IntPtr(decrypted), outputData, 0, outLen1 + outLen2);
			File::WriteAllBytes(outputPath, outputData);
			delete[] decrypted;

			MessageBox::Show("Decryption successful! File saved to:\n" + outputPath);
		}
		catch (Exception^ ex) {
			MessageBox::Show("Decryption error: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	private: System::Void exitBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}
	};
}
