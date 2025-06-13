#pragma once

// PREVENT WINDOWS HEADER CONFLICTS
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#define NOUSER
#define NOGDI
#define NOCRYPT

using namespace System;
using namespace System::IO;
using namespace System::Windows::Forms;

#include <openssl/evp.h>
#include <openssl/rand.h>
#include <openssl/err.h>

#include <msclr/marshal.h>
#include <msclr/marshal_cppstd.h>

namespace WindowsForm {

	public ref class encryptMenu : public System::Windows::Forms::Form
	{
	public:
		encryptMenu(void)
		{
			InitializeComponent();
		}

	protected:
		~encryptMenu()
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
		System::Windows::Forms::Button^ encryptBtn;
		System::Windows::Forms::Button^ logoutBtn;
		System::Windows::Forms::Button^ exitBtn;
		System::Windows::Forms::RichTextBox^ fileBox;
		System::Windows::Forms::RichTextBox^ fileContents;
		System::Windows::Forms::OpenFileDialog^ openFileDialog;
		System::Windows::Forms::SaveFileDialog^ saveFileDialog;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->welcomeMsg = (gcnew System::Windows::Forms::Label());
			this->browseBtn = (gcnew System::Windows::Forms::Button());
			this->encryptBtn = (gcnew System::Windows::Forms::Button());
			this->logoutBtn = (gcnew System::Windows::Forms::Button());
			this->exitBtn = (gcnew System::Windows::Forms::Button());
			this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->fileBox = (gcnew System::Windows::Forms::RichTextBox());
			this->fileContents = (gcnew System::Windows::Forms::RichTextBox());
			this->saveFileDialog = (gcnew System::Windows::Forms::SaveFileDialog());
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
			this->browseBtn->Text = L"Browse For A file:";
			this->browseBtn->Click += gcnew System::EventHandler(this, &encryptMenu::browseBtn_Click);
			// 
			// encryptBtn
			// 
			this->encryptBtn->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->encryptBtn->Location = System::Drawing::Point(250, 350);
			this->encryptBtn->Name = L"encryptBtn";
			this->encryptBtn->Size = System::Drawing::Size(164, 49);
			this->encryptBtn->TabIndex = 6;
			this->encryptBtn->Text = L"Encrypt File";
			this->encryptBtn->Click += gcnew System::EventHandler(this, &encryptMenu::encryptBtn_Click);
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
			this->fileBox->Size = System::Drawing::Size(297, 45);
			this->fileBox->TabIndex = 9;
			this->fileBox->Text = L"";
			this->fileBox->ReadOnly = true;
			// 
			// fileContents
			// 
			this->fileContents->Location = System::Drawing::Point(169, 250);
			this->fileContents->Name = L"fileContents";
			this->fileContents->Text = L"Contents of file will be shown here";
			this->fileContents->Size = System::Drawing::Size(467, 100);
			this->fileContents->TabIndex = 10;
			this->fileContents->ReadOnly = true;
			// 
			// openFileDialog filter setup
			// 
			this->openFileDialog->Filter = "Text Files (*.txt)|*.txt|JSON Files (*.json)|*.json|CSV Files (*.csv)|*.csv";

			// 
			// encryptMenu
			// 
			this->ClientSize = System::Drawing::Size(807, 589);
			this->Controls->Add(this->fileBox);
			this->Controls->Add(this->fileContents);
			this->Controls->Add(this->welcomeMsg);
			this->Controls->Add(this->browseBtn);
			this->Controls->Add(this->encryptBtn);
			this->Controls->Add(this->logoutBtn);
			this->Controls->Add(this->exitBtn);
			this->Name = L"encryptMenu";
			this->Text = L"Encrypt Menu";
			this->ResumeLayout(false);
		}
#pragma endregion

	private: System::Void browseBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		openFileDialog->Filter = "Text Files (*.txt)|*.txt|JSON Files (*.json)|*.json|CSV Files (*.csv)|*.csv";
		if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			String^ filePath = openFileDialog->FileName;
			fileBox->Text = filePath;

			try {
				fileContents->Text = File::ReadAllText(filePath);
			}
			catch (Exception^ ex) {
				MessageBox::Show("Failed to read file contents:\n" + ex->Message,
					"Read Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
	}

	private: System::Void encryptBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ filePath = fileBox->Text;

		if (String::IsNullOrWhiteSpace(filePath)) {
			MessageBox::Show("Please select a file to encrypt");
			return;
		}

		try {
			array<Byte>^ fileData = File::ReadAllBytes(filePath);
			int inputLen = fileData->Length;

			pin_ptr<Byte> inputPtr = &fileData[0];
			unsigned char* inputData = inputPtr;

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

			int maxOutputLen = inputLen + EVP_MAX_BLOCK_LENGTH;
			unsigned char* encrypted = new unsigned char[maxOutputLen];
			int outLen1 = 0, outLen2 = 0;

			EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
			if (!ctx) throw gcnew Exception("Failed to create cipher context.");

			if (1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
				throw gcnew Exception("EVP_EncryptInit_ex failed");

			if (1 != EVP_EncryptUpdate(ctx, encrypted, &outLen1, inputData, inputLen))
				throw gcnew Exception("EVP_EncryptUpdate failed");

			if (1 != EVP_EncryptFinal_ex(ctx, encrypted + outLen1, &outLen2))
				throw gcnew Exception("EVP_EncryptFinal_ex failed");

			EVP_CIPHER_CTX_free(ctx);

			// Prompt user to save the encrypted file
			saveFileDialog->Title = "Save Encrypted File As";
			saveFileDialog->Filter = "Encrypted Files (*.enc)|*.enc|All Files (*.*)|*.*";
			saveFileDialog->FileName = Path::GetFileNameWithoutExtension(filePath) + ".enc";

			if (saveFileDialog->ShowDialog() != System::Windows::Forms::DialogResult::OK) {
				MessageBox::Show("Encryption Cancelled: No save location chosen");
				delete[] encrypted;
				return;
			}

			String^ encryptedFilePath = saveFileDialog->FileName;

			// Write encrypted data to file
			array<Byte>^ encryptedData = gcnew array<Byte>(outLen1 + outLen2);
			System::Runtime::InteropServices::Marshal::Copy(IntPtr(encrypted), encryptedData, 0, outLen1 + outLen2);
			File::WriteAllBytes(encryptedFilePath, encryptedData);

			delete[] encrypted;

			MessageBox::Show("File encrypted and saved successfully.", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error during encryption:\n" + ex->Message,
				"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	};
}
