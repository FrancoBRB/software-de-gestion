#ifndef HIJA_VENTAS_H
#define HIJA_VENTAS_H
#include "wxfb_project.h"
#include "Sistema.h"

class hija_ventas : public ventana_ventas {
	
private:
	
protected:
	void AbrirFacturaDCizq( wxGridEvent& event )  override;
	void ClickGrillaVentasIzq( wxGridEvent& event )  override;
	void ClickGrillaVentasDer( wxGridEvent& event )  override;
	void SelectGrillaVentCizq( wxGridEvent& event )  override;
	void btn_ver_factura( wxCommandEvent& event )  override;
	void btn_busqueda_avanzada_ventas( wxCommandEvent& event ) override;
	Sistema *m_sistema;
public:
	hija_ventas(wxWindow *parent, Sistema *sistema);
	void refrescar_grilla_ventas();
	~hija_ventas();
};

#endif

