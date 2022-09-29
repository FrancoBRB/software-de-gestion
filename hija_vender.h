#ifndef HIJA_VENDER_H
#define HIJA_VENDER_H
#include "wxfb_project.h"
#include "Sistema.h"
#include <vector>
#include "Stock.h"
struct Factura{
	std::vector <int> cant;
	std::vector <int> desc;
	std::vector <int> p_total;
	Stock carrito_de_compra;
};
class hija_vender : public ventana_vender {
	
private:
	
protected:
	void RecargarGrillaProdCizq( wxGridEvent& event )  override;
	void btn_sumar_cant( wxCommandEvent& event )  override;
	void btn_restar_cant( wxCommandEvent& event )  override;
	void SelectGrillaFactCizq( wxGridEvent& event )  override;
	void SelectGrillaProdCizq( wxGridEvent& event )  override;
	void btn_busqueda_productos( wxCommandEvent& event )  override;
	void btn_agregar( wxCommandEvent& event )  override;
	void btn_realizar_venta( wxCommandEvent& event )  override;
	void btn_quitar_producto( wxCommandEvent& event )  override;
	Factura fac;
	int cont_total = 0, cont_filas = 0, cont_disponibles = 0;
	Sistema *m_sistema;
	std::vector<int> pos_f; /* Vector con filas */
	std::vector<int> pos_b; /* Vector con las posiciones de las busquedas */
public:
	hija_vender(wxWindow *parent,Sistema *sistema);
	void refrescar_grilla_productos();
};

#endif

