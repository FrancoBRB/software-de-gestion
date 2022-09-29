#ifndef HIJA_BUSQUEDA_H
#define HIJA_BUSQUEDA_H
#include "wxfb_project.h"
#include "Sistema.h"
#include <wx/grid.h>

class hija_busqueda : public ventana_busqueda {
	
private:
	
protected:
	Sistema *m_sistema;
	wxGrid *m_grilla_historial_ventas;
	void btn_aceptar_busqueda( wxCommandEvent& event )  override;
	void btn_cancelar_busqueda( wxCommandEvent& event )  override;
public:
	hija_busqueda(wxWindow *parent,Sistema *sistema,wxGrid *grilla_historial_ventas);
};

#endif

