#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    // Project3 — назва вашого проекту за замовчуванням
    Project3::MyForm^ form = gcnew Project3::MyForm();
    Application::Run(form);
    return 0;
}