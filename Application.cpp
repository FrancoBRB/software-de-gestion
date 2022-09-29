#include "Application.h"
#include "hija_principal.h"

IMPLEMENT_APP(Application)

bool Application::OnInit() {
	hija_principal *win = new hija_principal();
	win->Show();
	return true;
}


