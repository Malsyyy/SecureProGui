#pragma once

namespace SecureProGui {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	public ref class createAccount : public System::Windows::Forms::Form
	{
	public:
		createAccount(void)
		{
			InitializeComponent();

		}

	protected:

		~createAccount()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ passwordLabel;
	protected:
	private: System::Windows::Forms::Label^ usernameLabel;
	private: System::Windows::Forms::RichTextBox^ richTextBox2;
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::Label^ createAccBanner;
	private: System::Windows::Forms::Button^ createAccBtn;



	private:

		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->passwordLabel = (gcnew System::Windows::Forms::Label());
			this->usernameLabel = (gcnew System::Windows::Forms::Label());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->createAccBanner = (gcnew System::Windows::Forms::Label());
			this->createAccBtn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// passwordLabel
			// 
			this->passwordLabel->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->passwordLabel->ForeColor = System::Drawing::SystemColors::Control;
			this->passwordLabel->Location = System::Drawing::Point(143, 226);
			this->passwordLabel->Name = L"passwordLabel";
			this->passwordLabel->Padding = System::Windows::Forms::Padding(15);
			this->passwordLabel->Size = System::Drawing::Size(156, 47);
			this->passwordLabel->TabIndex = 7;
			this->passwordLabel->Text = L"Password";
			this->passwordLabel->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// usernameLabel
			// 
			this->usernameLabel->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->usernameLabel->ForeColor = System::Drawing::SystemColors::Control;
			this->usernameLabel->Location = System::Drawing::Point(143, 162);
			this->usernameLabel->Name = L"usernameLabel";
			this->usernameLabel->Padding = System::Windows::Forms::Padding(15);
			this->usernameLabel->Size = System::Drawing::Size(156, 47);
			this->usernameLabel->TabIndex = 6;
			this->usernameLabel->Text = L"Username";
			this->usernameLabel->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// richTextBox2
			// 
			this->richTextBox2->Location = System::Drawing::Point(305, 226);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->Size = System::Drawing::Size(334, 47);
			this->richTextBox2->TabIndex = 5;
			this->richTextBox2->Text = L"";
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(305, 162);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(334, 47);
			this->richTextBox1->TabIndex = 4;
			this->richTextBox1->Text = L"";
			// 
			// createAccBanner
			// 
			this->createAccBanner->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->createAccBanner->ForeColor = System::Drawing::SystemColors::Control;
			this->createAccBanner->Location = System::Drawing::Point(202, 9);
			this->createAccBanner->Name = L"createAccBanner";
			this->createAccBanner->Padding = System::Windows::Forms::Padding(15);
			this->createAccBanner->Size = System::Drawing::Size(392, 47);
			this->createAccBanner->TabIndex = 8;
			this->createAccBanner->Text = L"Create An Account";
			this->createAccBanner->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// createAccBtn
			// 
			this->createAccBtn->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->createAccBtn->ForeColor = System::Drawing::SystemColors::Control;
			this->createAccBtn->Location = System::Drawing::Point(305, 340);
			this->createAccBtn->Name = L"createAccBtn";
			this->createAccBtn->Size = System::Drawing::Size(173, 45);
			this->createAccBtn->TabIndex = 9;
			this->createAccBtn->Text = L"Create Account";
			this->createAccBtn->UseVisualStyleBackColor = false;
			// 
			// createAccount
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(823, 640);
			this->Controls->Add(this->createAccBtn);
			this->Controls->Add(this->createAccBanner);
			this->Controls->Add(this->passwordLabel);
			this->Controls->Add(this->usernameLabel);
			this->Controls->Add(this->richTextBox2);
			this->Controls->Add(this->richTextBox1);
			this->Name = L"createAccount";
			this->Text = L"createAccount";
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
