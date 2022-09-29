#ifndef HIJA_PRINCIPAL_H
#define HIJA_PRINCIPAL_H
#include "wxfb_project.h"
#include "Sistema.h"

class hija_principal : public ventana_principal {
	
private:
	Sistema *m_sistema;
protected:
	void clickAbrirStock( wxCommandEvent& event )  override;
	void clickAbrirVentas( wxCommandEvent& event )  override;
public:
	hija_principal();
};

#endif

