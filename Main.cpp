<<<<<<< Updated upstream
#include "mainMenu.h"
=======
<<<<<<< HEAD
#include "headers/MyForm.h"
=======
#include "mainMenu.h"
>>>>>>> 36e48936a4672d94f707032d315fdf145d89a21f
>>>>>>> Stashed changes

using namespace System;
using namespace System::Windows::Forms;
using namespace WindowsForm;

[STAThreadAttribute]
int main(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    Application::Run(gcnew mainMenu());
    return 0;
}


