#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace WindowsForm;

[STAThreadAttribute]
int main(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    Application::Run(gcnew MyForm());
    WindowsForm::decryptMenu form;
    Application::Run(% form);
    return 0;
}


