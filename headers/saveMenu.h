#pragma once

namespace WindowsForm {

	using namespace System;
	using namespace System::Windows::Forms;

	public ref class saveMenu : public Form
	{
	public:
		saveMenu(void)
		{
			InitializeComponent();
		}

	protected:
		~saveMenu()
		{
			if (components)
				delete components;
		}

	private:
		Label^ label;
		System::ComponentModel::Container^ components;

		void InitializeComponent(void)
		{
			this->label = gcnew Label();
			this->label->Text = L"Save Menu";
			this->label->Location = Drawing::Point(30, 30);
			this->Controls->Add(this->label);
			this->ClientSize = Drawing::Size(200, 100);
			this->Text = L"Save Menu";
		}
	};
}
