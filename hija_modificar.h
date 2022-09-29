#ifndef HIJA_MODIFICAR_H
#define HIJA_MODIFICAR_H
#include "wxfb_project.h"
#include "Sistema.h"
#include <wx/grid.h>
#include "string_conv.h"
#include <wx/msgdlg.h>
#include <vector>

class hija_modificar : public ventana_modificar {
	
private:
	
protected:
	void btn_editar_guardar( wxCommandEvent& event )  override;
	void btn_editar_cancelar( wxCommandEvent& event )  override;
	Sistema *m_sistema;
	wxGrid* m_grilla_stock;
	const std::vector <int> m_pos_b;
public:
	hija_modificar(wxWindow *parent,Sistema *sistema, wxGrid* grilla_stock, const std::vector <int> &pos_b);
};

#endif

