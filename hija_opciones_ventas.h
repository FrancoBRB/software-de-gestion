#ifndef HIJA_OPCIONES_VENTAS_H
#define HIJA_OPCIONES_VENTAS_H
#include "wxfb_project.h"
#include "Sistema.h"

class hija_opciones_ventas : public ventana_opciones_ventas {
	
private:
	
protected:
	void btn_ver_ventas( wxCommandEvent& event )  override;
	void btn_vender( wxCommandEvent& event )  override;
	void btn_ranking( wxCommandEvent& event )  override;
	Sistema *m_sistema;
public:
	hija_opciones_ventas(wxWindow *parent, Sistema *sistema);
};

#endif

