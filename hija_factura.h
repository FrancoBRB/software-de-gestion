#ifndef HIJA_FACTURA_H
#define HIJA_FACTURA_H
#include "wxfb_project.h"
#include "Sistema.h"

class hija_factura : public ventana_factura {
	
private:
	
protected:
	void cerrar_ventana_factura( wxMouseEvent& event )  override;
	int m_nro_factura;
	Sistema *m_sistema;
public:
	hija_factura(wxWindow *parent,Sistema *sistema,long nro_factura);
};

#endif

