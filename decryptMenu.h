#pragma once

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

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->welcomeMsg = (gcnew System::Windows::Forms::Label());
			this->browseBtn = (gcnew System::Windows::Forms::Button());
			this->decryptBtn = (gcnew System::Windows::Forms::Button());
			this->logoutBtn = (gcnew System::Windows::Forms::Button());
			this->exitBtn = (gcnew System::Windows::Forms::Button());

			this->SuspendLayout();

			// 
			// welcome Message
			// 

			this->welcomeMsg->Location = System::Drawing::Point(58, 20);
			this->welcomeMsg->Name = L"welcomeMsg";
			this->welcomeMsg->Size = System::Drawing::Size(300, 30);
			this->welcomeMsg->TabIndex = 0;
			this->welcomeMsg->Text = L"Welcome to the Decrypt Menu";

			// 
			// browse Button
			// 
			this->browseBtn->Location = System::Drawing::Point(472, 188);
			this->browseBtn->Name = L"browseBtn";
			this->browseBtn->Size = System::Drawing::Size(164, 49);
			this->browseBtn->TabIndex = 1;
			this->browseBtn->Text = L"Browse For A File";
			this->browseBtn->UseVisualStyleBackColor = true;

			// 
			// decrypt Button
			// 
			this->decryptBtn->Location = System::Drawing::Point(250, 275);
			this->decryptBtn->Name = L"decryptBtn";
			this->decryptBtn->Size = System::Drawing::Size(164, 49);
			this->decryptBtn->TabIndex = 2;
			this->decryptBtn->Text = L"Decrypt File";
			this->decryptBtn->UseVisualStyleBackColor = true;

			// 
			// logout Button
			// 
			this->logoutBtn->Location = System::Drawing::Point(169, 475);
			this->logoutBtn->Name = L"logoutBtn";
			this->logoutBtn->Size = System::Drawing::Size(169, 49);
			this->logoutBtn->TabIndex = 3;
			this->logoutBtn->Text = L"Logout";
			this->logoutBtn->UseVisualStyleBackColor = true;

			// 
			// exit Button
			// 
			this->exitBtn->Location = System::Drawing::Point(369, 475);
			this->exitBtn->Name = L"exitBtn"; // ✅ Fixed from "logoutBtn"
			this->exitBtn->Size = System::Drawing::Size(169, 49);
			this->exitBtn->TabIndex = 4;
			this->exitBtn->Text = L"Exit";
			this->exitBtn->UseVisualStyleBackColor = true;

			// 
			// decryptMenu 
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(807, 589);
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

	};
}
