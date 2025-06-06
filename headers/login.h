#pragma once

namespace SecureProGui {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	public ref class login : public System::Windows::Forms::Form
	{
	public:
		login(void)
		{
			InitializeComponent();

		}

	protected:

		~login()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	protected:
	private: System::Windows::Forms::RichTextBox^ richTextBox2;
	private: System::Windows::Forms::Label^ usernameLabel;
	private: System::Windows::Forms::Label^ passwordLabel;
	private: System::Windows::Forms::Button^ loginBtn;
	private: System::Windows::Forms::Button^ logoutBtn;
	private: System::Windows::Forms::Button^ createaccountBtn;


	private:

		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->usernameLabel = (gcnew System::Windows::Forms::Label());
			this->passwordLabel = (gcnew System::Windows::Forms::Label());
			this->loginBtn = (gcnew System::Windows::Forms::Button());
			this->logoutBtn = (gcnew System::Windows::Forms::Button());
			this->createaccountBtn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(187, 54);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(334, 47);
			this->richTextBox1->TabIndex = 0;
			this->richTextBox1->Text = L"";
			// 
			// richTextBox2
			// 
			this->richTextBox2->Location = System::Drawing::Point(187, 118);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->Size = System::Drawing::Size(334, 47);
			this->richTextBox2->TabIndex = 1;
			this->richTextBox2->Text = L"";
			// 
			// usernameLabel
			// 
			this->usernameLabel->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->usernameLabel->ForeColor = System::Drawing::SystemColors::Control;
			this->usernameLabel->Location = System::Drawing::Point(25, 54);
			this->usernameLabel->Name = L"usernameLabel";
			this->usernameLabel->Padding = System::Windows::Forms::Padding(15);
			this->usernameLabel->Size = System::Drawing::Size(156, 47);
			this->usernameLabel->TabIndex = 2;
			this->usernameLabel->Text = L"Username";
			this->usernameLabel->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->usernameLabel->Click += gcnew System::EventHandler(this, &login::label1_Click);
			// 
			// passwordLabel
			// 
			this->passwordLabel->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->passwordLabel->ForeColor = System::Drawing::SystemColors::Control;
			this->passwordLabel->Location = System::Drawing::Point(25, 118);
			this->passwordLabel->Name = L"passwordLabel";
			this->passwordLabel->Padding = System::Windows::Forms::Padding(15);
			this->passwordLabel->Size = System::Drawing::Size(156, 47);
			this->passwordLabel->TabIndex = 3;
			this->passwordLabel->Text = L"Password";
			this->passwordLabel->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// loginBtn
			// 
			this->loginBtn->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->loginBtn->ForeColor = System::Drawing::SystemColors::Control;
			this->loginBtn->Location = System::Drawing::Point(202, 203);
			this->loginBtn->Name = L"loginBtn";
			this->loginBtn->Size = System::Drawing::Size(173, 45);
			this->loginBtn->TabIndex = 4;
			this->loginBtn->Text = L"login Button";
			this->loginBtn->UseVisualStyleBackColor = false;
			// 
			// logoutBtn
			// 
			this->logoutBtn->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->logoutBtn->ForeColor = System::Drawing::SystemColors::Control;
			this->logoutBtn->Location = System::Drawing::Point(202, 254);
			this->logoutBtn->Name = L"logoutBtn";
			this->logoutBtn->Size = System::Drawing::Size(173, 45);
			this->logoutBtn->TabIndex = 5;
			this->logoutBtn->Text = L"logout Button";
			this->logoutBtn->UseVisualStyleBackColor = false;
			// 
			// createaccountBtn
			// 
			this->createaccountBtn->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->createaccountBtn->ForeColor = System::Drawing::SystemColors::Control;
			this->createaccountBtn->Location = System::Drawing::Point(171, 305);
			this->createaccountBtn->Name = L"createaccountBtn";
			this->createaccountBtn->Size = System::Drawing::Size(238, 45);
			this->createaccountBtn->TabIndex = 6;
			this->createaccountBtn->Text = L"Create Button";
			this->createaccountBtn->UseVisualStyleBackColor = false;
			// 
			// login
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(626, 383);
			this->Controls->Add(this->createaccountBtn);
			this->Controls->Add(this->logoutBtn);
			this->Controls->Add(this->loginBtn);
			this->Controls->Add(this->passwordLabel);
			this->Controls->Add(this->usernameLabel);
			this->Controls->Add(this->richTextBox2);
			this->Controls->Add(this->richTextBox1);
			this->Name = L"login";
			this->Text = L"login";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
