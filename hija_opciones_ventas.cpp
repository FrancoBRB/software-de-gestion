#include "hija_opciones_ventas.h"
#include "hija_vender.h"
#include "hija_ventas.h"
#include "hija_ranking.h"
#include <wx/msgdlg.h>
#include <wx/window.h>
#include <wx/icon.h>
#include "iconoventas.xpm"

hija_opciones_ventas::hija_opciones_ventas(wxWindow *parent, Sistema *sistema) : ventana_opciones_ventas(parent), m_sistema(sistema) {
	SetIcon(wxIcon(iconoventas_xpm));
}

void hija_opciones_ventas::btn_vender( wxCommandEvent& event )  {
	hija_vender win_vender(this, m_sistema);
	win_vender.ShowModal();
//	if (win_vender.ShowModal() == 1) {
//		wxMessageBox("Venta realizada", "¡Operación exitosa!" , wxOK | wxICON_INFORMATION);
//	}
}

void hija_opciones_ventas::btn_ranking( wxCommandEvent& event )  {
	if (m_sistema -> VerVentas().VentaTam() == 0) {
		wxMessageBox("No es posible realizar esta accion. No hay registros disponibles", "¡Aviso!", wxOK | wxICON_INFORMATION);
	} else {
		hija_ranking win_ranking(this, m_sistema);
		win_ranking.ShowModal();
	}
}

void hija_opciones_ventas::btn_ver_ventas( wxCommandEvent& event )  {
	if (m_sistema -> VerVentas().VentaTam() == 0) {
		wxMessageBox("No es posible realizar esta accion. No hay registros disponibles", "¡Aviso!", wxOK | wxICON_INFORMATION);
	} else {
		hija_ventas win_ventas(this, m_sistema);
		win_ventas.ShowModal();
	}
}


