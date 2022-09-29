#include "hija_principal.h"
#include "hija_stock.h"
#include "hija_opciones_ventas.h"
#include <wx/icon.h>
#include "icono.xpm"

hija_principal::hija_principal() : ventana_principal(nullptr) {
	SetIcon(wxIcon(icono_xpm));
	m_sistema =new Sistema("Stock.dat","Ventas.dat");
}

void hija_principal::clickAbrirStock( wxCommandEvent& event )  {
	hija_stock win(this, m_sistema);
	win.ShowModal();
}

void hija_principal::clickAbrirVentas( wxCommandEvent& event )  {
	hija_opciones_ventas *win = new hija_opciones_ventas(this, m_sistema);
	win -> Show();
}

