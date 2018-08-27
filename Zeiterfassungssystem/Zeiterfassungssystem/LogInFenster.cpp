#include "LogInFenster.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void Main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Zeiterfassungssystem::loginFenster form;
	Application::Run(%form);
}