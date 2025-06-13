#pragma once

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


#include "encryptMenu.h"
#include "decryptMenu.h"

namespace WindowsForm {

	public ref class mainMenu : public System::Windows::Forms::Form
	{
	public:
		mainMenu(void)
		{
			InitializeComponent();
		}

	protected:
		~mainMenu()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		System::ComponentModel::Container^ components;
		System::Windows::Forms::Button^ encryptMenuBtn;
		System::Windows::Forms::Button^ decryptMenuBtn;
		System::Windows::Forms::Button^ exitApplicationButton;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->encryptMenuBtn = (gcnew System::Windows::Forms::Button());
			this->decryptMenuBtn = (gcnew System::Windows::Forms::Button());
			this->exitApplicationButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			//
			// openEncryptMenuButton
			//
			this->encryptMenuBtn->Location = System::Drawing::Point(100, 50);
			this->encryptMenuBtn->Name = L"openEncryptMenuButton";
			this->encryptMenuBtn->Size = System::Drawing::Size(150, 40);
			this->encryptMenuBtn->Text = L"Open Encrypt Menu";
			this->encryptMenuBtn->Click += gcnew System::EventHandler(this, &mainMenu::encryptMenuBtn_Click);
			//
			//  Decrypt Menu
			//
			this->decryptMenuBtn->Location = System::Drawing::Point(100, 120);
			this->decryptMenuBtn->Name = L"decryptMenuBtn";
			this->decryptMenuBtn->Size = System::Drawing::Size(150, 40);
			this->decryptMenuBtn->Text = L"Open Decrypt Menu";
			this->decryptMenuBtn->Click += gcnew System::EventHandler(this, &mainMenu::encryptMenuBtn_Click);

			//
			// exitApplicationButton
			//
			this->exitApplicationButton->Location = System::Drawing::Point(100, 190);
			this->exitApplicationButton->Name = L"exitApplicationButton";
			this->exitApplicationButton->Size = System::Drawing::Size(150, 40);
			this->exitApplicationButton->Text = L"Exit";
			this->exitApplicationButton->Click += gcnew System::EventHandler(this, &mainMenu::exitApplicationButton_Click);
			//
			// mainMenu
			//
			this->ClientSize = System::Drawing::Size(347, 336);
			this->Controls->Add(this->encryptMenuBtn);
			this->Controls->Add(this->decryptMenuBtn);
			this->Controls->Add(this->exitApplicationButton);
			this->Name = L"mainMenu";
			this->Text = L"Main Menu";
			this->ResumeLayout(false);
		}
#pragma endregion

	private: System::Void encryptMenuBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		
		encryptMenu^ encryptForm = gcnew encryptMenu(); 
		encryptForm->ShowDialog(); 
	}

	private: System::Void decryptMenuBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	
		decryptMenu^ decryptForm = gcnew decryptMenu();
		decryptForm->ShowDialog();
	}

	private: System::Void exitApplicationButton_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}
	};
}

