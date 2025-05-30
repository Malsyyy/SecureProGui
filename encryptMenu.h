#pragma once

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
		System::Windows::Forms::Button^ uploadBtn;
		System::Windows::Forms::Button^ logoutBtn;
		System::Windows::Forms::Button^ exitBtn;
		System::Windows::Forms::OpenFileDialog^ openFileDialog;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->SuspendLayout();
			this->ClientSize = System::Drawing::Size(300, 200);
			this->Name = L"encryptMenu";
			this->Text = L"Encrypt Menu";
			this->ResumeLayout(false);
			this->welcomeMsg = (gcnew System::Windows::Forms::Label());
			this->browseBtn =  (gcnew System::Windows::Forms::Button());
			this->uploadBtn =  (gcnew System::Windows::Forms::Button());
			this->logoutBtn =  (gcnew System::Windows::Forms::Button());
			this->exitBtn =    (gcnew System::Windows::Forms::Button());
			this->openFileDialog = gcnew System::Windows::Forms::OpenFileDialog();
			this->uploadBtn->Click += gcnew System::EventHandler(this, &encryptMenu::uploadBtn_Click);


			//
			// Welcome message
			//

			this->welcomeMsg->Location = System::Drawing::Point(58, 220);
			this->welcomeMsg->Name = L"welcomeMsg";
			this->welcomeMsg->Size = System::Drawing::Size(0, 100);
			this->welcomeMsg->TabIndex = 4;

			//
			// Browse Button
			//

			this->browseBtn->Location = System::Drawing::Point(472,188) ;
			this->browseBtn->Name = L"browseBtn";
			this->browseBtn->Size = System::Drawing::Size(164, 49);
			this->browseBtn->Text = L"Browse For A file:";
			this->browseBtn->Anchor = System::Windows::Forms::AnchorStyles::Top;

			//
			// Upload Button
			//

			this->uploadBtn->Location = System::Drawing::Point(250, 275);
			this->uploadBtn->Name = L"uploadBtn";
			this->uploadBtn->Text = L"Upload File";
			this->uploadBtn->Size = System::Drawing::Size(164,49);
			this->uploadBtn-> Anchor = System::Windows::Forms::AnchorStyles::Top;

			//
			// Logout Button
			//
	
			this->logoutBtn->Location = System::Drawing::Point(169 ,475 );
			this->logoutBtn->Name = L"logoutBtn";
			this->logoutBtn->Text = L"Logout";
			this->logoutBtn->Size = System::Drawing::Size(169,49);
			this->logoutBtn->Anchor = System::Windows::Forms::AnchorStyles::Top;


			//
			// Exit Button
			//

			this->exitBtn->Location = System::Drawing::Point(369, 475);
			this->exitBtn->Name = L"logoutBtn";
			this->exitBtn->Text = L"Exit";
			this->exitBtn->Size = System::Drawing::Size(169, 49);
			this->exitBtn->Anchor = System::Windows::Forms::AnchorStyles::Top;

			//
			// Encrypt Menu Controls
			//

			this->ClientSize = System::Drawing::Size(807,589);
			this->Controls->Add(this->welcomeMsg);
			this->Controls->Add(this->browseBtn);
			this->Controls->Add(this->uploadBtn);
			this->Controls->Add(this->logoutBtn);
			this->Controls->Add(this->exitBtn);
			this->Name = L"EncryptMenu";
			this->Text = L"Encrypt Menu";



				;
		}
#pragma endregion

private: System::Void uploadBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	openFileDialog->Title = "Select a file to upload";
	openFileDialog->Filter = "All Files (*.*)|*.*";

	if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		System::String^ filePath = openFileDialog->FileName;
		System::Windows::Forms::MessageBox::Show("Selected file: " + filePath);
	}
}


};
}
