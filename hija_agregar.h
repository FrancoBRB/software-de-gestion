#ifndef HIJA_AGREGAR_H
#define HIJA_AGREGAR_H
#include "wxfb_project.h"
#include "Sistema.h"

class hija_agregar : public ventana_agregar {
	
private:
	
protected:
	void btn_agregar_producto( wxCommandEvent& event )  override;
	void btn_producto_cancelar( wxCommandEvent& event )  override;
	Sistema *m_sistema;
public:
	hija_agregar(wxWindow *parent,Sistema *sistema);
};

#endif

