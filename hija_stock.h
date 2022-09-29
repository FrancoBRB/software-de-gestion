#ifndef HIJA_STOCK_H
#define HIJA_STOCK_H
#include "wxfb_project.h"
#include "Sistema.h"
#include <vector>

class hija_stock : public ventana_stock {
	
private:
	
protected:
	void btn_recargar_stock( wxCommandEvent& event )  override;
	void btn_VerEliminados( wxCommandEvent& event )  override;
	void SelectGrillaStockCizq( wxGridEvent& event )  override;
	void ClickGrillaStockI( wxGridEvent& event )  override;
	void ClickGrillaStockD( wxGridEvent& event )  override;
	void btn_busqueda( wxCommandEvent& event )  override;
	void btn_sumar( wxCommandEvent& event )  override;
	void btn_restar( wxCommandEvent& event )  override;
	void btn_agregar( wxCommandEvent& event )  override;
	void btn_editar_producto( wxCommandEvent& event )  override;
	void btn_eliminar( wxCommandEvent& event )  override;
	Sistema *m_sistema;
	Producto p;
	int cont_disponibles = 0;
	std::vector <int> pos_b;
public:
	hija_stock(wxWindow *parent, Sistema *sistema);
	void refrescar_grilla_stock ();
	void OnOff (bool opcion);
	~hija_stock();
};

#endif

