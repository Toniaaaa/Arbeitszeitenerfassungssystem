#include "LogInFenster.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void Main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Zeiterfassungssystem::LoginFenster form;
	form.Show();
	Application::Run();
}
