#pragma once

#include <openssl/evp.h>
#include <openssl/err.h>
#include <msclr/marshal_cppstd.h>
#include <fstream>

using namespace System;
using namespace System::IO;
using namespace System::Windows::Forms;

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
		System::ComponentModel::Container^ components;
		System::Windows::Forms::Label^ welcomeMsg;
		System::Windows::Forms::Button^ browseBtn;
		System::Windows::Forms::Button^ decryptBtn;
		System::Windows::Forms::Button^ logoutBtn;
		System::Windows::Forms::Button^ exitBtn;
		System::Windows::Forms::RichTextBox^ fileBox;
		System::Windows::Forms::OpenFileDialog^ openFileDialog;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->welcomeMsg = (gcnew System::Windows::Forms::Label());
			this->browseBtn = (gcnew System::Windows::Forms::Button());
			this->decryptBtn = (gcnew System::Windows::Forms::Button());
			this->logoutBtn = (gcnew System::Windows::Forms::Button());
			this->exitBtn = (gcnew System::Windows::Forms::Button());
			this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->fileBox = (gcnew System::Windows::Forms::RichTextBox());
			this->SuspendLayout();
			// 
			// welcomeMsg
			// 
			this->welcomeMsg->Location = System::Drawing::Point(58, 220);
			this->welcomeMsg->Name = L"welcomeMsg";
			this->welcomeMsg->Size = System::Drawing::Size(0, 100);
			this->welcomeMsg->TabIndex = 4;
			// 
			// browseBtn
			// 
			this->browseBtn->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->browseBtn->Location = System::Drawing::Point(472, 188);
			this->browseBtn->Name = L"browseBtn";
			this->browseBtn->Size = System::Drawing::Size(164, 49);
			this->browseBtn->TabIndex = 5;
			this->browseBtn->Text = L"Browse For A File";
			this->browseBtn->Click += gcnew System::EventHandler(this, &decryptMenu::browseBtn_Click);
			// 
			// decryptBtn
			// 
			this->decryptBtn->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->decryptBtn->Location = System::Drawing::Point(250, 275);
			this->decryptBtn->Name = L"decryptBtn";
			this->decryptBtn->Size = System::Drawing::Size(164, 49);
			this->decryptBtn->TabIndex = 6;
			this->decryptBtn->Text = L"Upload File";
			this->decryptBtn->Click += gcnew System::EventHandler(this, &decryptMenu::decryptBtn_Click);
			// 
			// logoutBtn
			// 
			this->logoutBtn->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->logoutBtn->Location = System::Drawing::Point(169, 475);
			this->logoutBtn->Name = L"logoutBtn";
			this->logoutBtn->Size = System::Drawing::Size(169, 49);
			this->logoutBtn->TabIndex = 7;
			this->logoutBtn->Text = L"Logout";
			// 
			// exitBtn
			// 
			this->exitBtn->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->exitBtn->Location = System::Drawing::Point(369, 475);
			this->exitBtn->Name = L"exitBtn";
			this->exitBtn->Size = System::Drawing::Size(169, 49);
			this->exitBtn->TabIndex = 8;
			this->exitBtn->Text = L"Exit";
			// 
			// fileBox
			// 
			this->fileBox->Location = System::Drawing::Point(169, 192);
			this->fileBox->Name = L"fileBox";
			this->fileBox->ReadOnly = true;
			this->fileBox->Size = System::Drawing::Size(297, 45);
			this->fileBox->TabIndex = 9;
			this->fileBox->Text = L"";
			// 
			// decryptMenu
			// 
			this->ClientSize = System::Drawing::Size(807, 589);
			this->Controls->Add(this->fileBox);
			this->Controls->Add(this->welcomeMsg);
			this->Controls->Add(this->browseBtn);
			this->Controls->Add(this->decryptBtn);
			this->Controls->Add(this->logoutBtn);
			this->Controls->Add(this->exitBtn);
			this->Name = L"decryptMenu";
			this->Text = L"Decrypt Menu";
			this->ResumeLayout(false);
		}
#pragma endregion

	private: System::Void browseBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		openFileDialog->Title = "Select a file to upload";
		openFileDialog->Filter = "All Files (*.*)|*.*";

		if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			System::String^ filePath = openFileDialog->FileName;
			fileBox->Text = filePath;
		}
	}

	private: System::Void decryptBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ filePath = fileBox->Text;

		if (String::IsNullOrWhiteSpace(filePath)) {
			MessageBox::Show("Please select a file to decrypt.");
			return;
		}

		try {
			array<Byte>^ encryptedData = File::ReadAllBytes(filePath);
			int inputLen = encryptedData->Length;

			pin_ptr<Byte> inputPtr = &encryptedData[0];
			unsigned char* encrypted = inputPtr;

			// Same key and IV used in encryption
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

			int maxOutputLen = inputLen;
			unsigned char* decrypted = new unsigned char[maxOutputLen];
			int outLen1 = 0, outLen2 = 0;

			EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
			if (!ctx) throw gcnew Exception("Failed to create cipher context.");

			if (1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
				throw gcnew Exception("EVP_DecryptInit_ex failed");

			if (1 != EVP_DecryptUpdate(ctx, decrypted, &outLen1, encrypted, inputLen))
				throw gcnew Exception("EVP_DecryptUpdate failed");

			if (1 != EVP_DecryptFinal_ex(ctx, decrypted + outLen1, &outLen2))
				throw gcnew Exception("EVP_DecryptFinal_ex failed");

			EVP_CIPHER_CTX_free(ctx);

			int totalLen = outLen1 + outLen2;
			array<Byte>^ decryptedData = gcnew array<Byte>(totalLen);
			System::Runtime::InteropServices::Marshal::Copy(IntPtr(decrypted), decryptedData, 0, totalLen);

			delete[] decrypted;

			SaveFileDialog^ saveDialog = gcnew SaveFileDialog();
			saveDialog->Title = "Save Decrypted File As";
			saveDialog->Filter = "Text Files (*.txt)|*.txt|All Files (*.*)|*.*";
			saveDialog->FileName = System::IO::Path::GetFileNameWithoutExtension(filePath) + "_decrypted.txt";

			if (saveDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				File::WriteAllBytes(saveDialog->FileName, decryptedData);
				MessageBox::Show("File decrypted and saved successfully.", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			else {
				MessageBox::Show("Decryption cancelled: no save location chosen.");
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error during decryption:\n" + ex->Message,
				"Decryption Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	};
}
