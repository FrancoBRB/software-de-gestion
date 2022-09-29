#ifndef HIJA_RANKING_H
#define HIJA_RANKING_H
#include "wxfb_project.h"
#include "Sistema.h"
#include <vector>
struct cat_nro{
	std::string c;///categoria
	int n;///numero
};
class hija_ranking : public ventana_ranking {
	
private:
	
protected:
	void btn_buscar_ranking( wxCommandEvent& event )  override;
	std::vector <cat_nro> v;
	Sistema *m_sistema;
	void btn_cerrar_ranking( wxCommandEvent& event )  override;
public:
	hija_ranking(wxWindow *parent,Sistema *sistema);
};

#endif

