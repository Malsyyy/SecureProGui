#pragma once

<<<<<<< HEAD
#include "headers/encryptMenu.h"
#include "headers/decryptMenu.h"
#include "headers/saveMenu.h"
=======
#include "encryptMenu.h"
#include "decryptMenu.h"
<<<<<<< Updated upstream
<<<<<<< Updated upstream
=======
>>>>>>> 36e48936a4672d94f707032d315fdf145d89a21f
>>>>>>> Stashed changes
=======
>>>>>>> 36e48936a4672d94f707032d315fdf145d89a21f
>>>>>>> Stashed changes


namespace WindowsForm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

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

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ EncryptBtn;
	private: System::Windows::Forms::Button^ decryptBtn;
	private: System::Windows::Forms::Button^ SaveBtn;
	private: System::Windows::Forms::Button^ LogoutBtn;
	private: System::Windows::Forms::Button^ exitBtn;





	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->label3 =     (gcnew System::Windows::Forms::Label());
			this->EncryptBtn = (gcnew System::Windows::Forms::Button());
			this->decryptBtn = (gcnew System::Windows::Forms::Button());
			this->SaveBtn =    (gcnew System::Windows::Forms::Button());
			this->LogoutBtn =  (gcnew System::Windows::Forms::Button());
			this->exitBtn =    (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(58, 220);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(0, 13);
			this->label3->TabIndex = 4;
			// 
			// EncryptBtn
			// 
			this->EncryptBtn->Location = System::Drawing::Point(172, 58);
			this->EncryptBtn->Name = L"EncryptBtn";
			this->EncryptBtn->Size = System::Drawing::Size(164, 49);
			this->EncryptBtn->TabIndex = 5;
			this->EncryptBtn->Text = L"Encrypt";
			this->EncryptBtn->UseVisualStyleBackColor = true;
			this->EncryptBtn->Click += gcnew System::EventHandler(this, &mainMenu::EncryptBtn_Click);
			// 
			// DecryptBtn
			// 
			this->decryptBtn->Location = System::Drawing::Point(172, 127);
			this->decryptBtn->Name = L"DecryptBtn";
			this->decryptBtn->Size = System::Drawing::Size(164, 49);
			this->decryptBtn->TabIndex = 6;
			this->decryptBtn->Text = L"Decrypt";
			this->decryptBtn->UseVisualStyleBackColor = true;
			this->decryptBtn->Click += gcnew System::EventHandler(this, &mainMenu::DecryptBtn_Click);
			// 
			// SaveBtn
			// 
			this->SaveBtn->Location = System::Drawing::Point(172, 202);
			this->SaveBtn->Name = L"SaveBtn";
			this->SaveBtn->Size = System::Drawing::Size(164, 49);
			this->SaveBtn->TabIndex = 7;
			this->SaveBtn->Text = L"Save File";
			this->SaveBtn->UseVisualStyleBackColor = true;
			this->SaveBtn->Click += gcnew System::EventHandler(this, &mainMenu::SaveBtn_Click);
			// 
			// LogoutBtn
			// 
			this->LogoutBtn->Location = System::Drawing::Point(172, 281);
			this->LogoutBtn->Name = L"LogoutBtn";
			this->LogoutBtn->Size = System::Drawing::Size(164, 49);
			this->LogoutBtn->TabIndex = 8;
			this->LogoutBtn->Text = L"Logout";
			this->LogoutBtn->UseVisualStyleBackColor = true;
			this->LogoutBtn->Click += gcnew System ::EventHandler(this, &mainMenu::LogoutBtn_Click);
			// 
			// ExitBtn
			// 
			this->exitBtn->Location = System::Drawing::Point(172, 352);
			this->exitBtn->Name = L"ExitBtn";
			this->exitBtn->Size = System::Drawing::Size(164, 49);
			this->exitBtn->TabIndex = 9;
			this->exitBtn->Text = L"Exit";
			this->exitBtn->UseVisualStyleBackColor = true;
			this->exitBtn->Click += gcnew System ::EventHandler(this, &mainMenu::ExitBtn_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(537, 436);
			this->Controls->Add(this->exitBtn);
			this->Controls->Add(this->LogoutBtn);
			this->Controls->Add(this->SaveBtn);
			this->Controls->Add(this->decryptBtn);
			this->Controls->Add(this->EncryptBtn);
			this->Controls->Add(this->label3);
			this->MinimumSize = System::Drawing::Size(553, 475);
			this->Name = L"Main Menu";
			this->Text = L"mainMenu";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion	

	private: System::Void EncryptBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		WindowsForm::encryptMenu^ menu = gcnew WindowsForm::encryptMenu();
		menu->ShowDialog();
	}
	private: System::Void DecryptBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		WindowsForm::decryptMenu^ menu = gcnew WindowsForm::decryptMenu();
		menu->ShowDialog();
	}

	private: System::Void SaveBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		WindowsForm::saveMenu^ menu = gcnew WindowsForm::saveMenu();
		MessageBox::Show("Save button pressed");
	}
	private: System::Void LogoutBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		MessageBox::Show("Logout Button Pressed");
	}
	private: System::Void ExitBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		MessageBox::Show("Exit Button Pressed");
	}


};
}


