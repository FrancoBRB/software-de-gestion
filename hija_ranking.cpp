#include "hija_ranking.h"
#include <wx/icon.h>
#include "iconoranking.xpm"

hija_ranking::hija_ranking(wxWindow *parent,Sistema *sistema) : ventana_ranking(parent),m_sistema(sistema){
	SetIcon(wxIcon(iconoranking_xpm));
	cat_nro aux;
	int cont=0;
	for(auto x:m_sistema->VerVentas().VerCategoriasVentas(m_sistema->VerStock())){
		m_comboBoxVR->Append(x);
		aux.c=x;
		aux.n=cont;
		v.push_back(aux);
		cont++;
	}
}

void hija_ranking::btn_cerrar_ranking( wxCommandEvent& event )  {
	EndModal(0);
}

void hija_ranking::btn_buscar_ranking( wxCommandEvent& event )  {
	std::string seleccion,str_prod;
	int pos,posj;
	SRanking xx;
	for(size_t i=0;i<v.size();i++) { 
		if(v[i].n==m_comboBoxVR->GetSelection()){
			seleccion=v[i].c;
			break;
		}
	}
	if (grilla_ranking->GetNumberRows()!=0){	
		grilla_ranking-> DeleteRows(0,grilla_ranking->GetNumberRows()); 
	}
	std::vector<SRanking>aux=m_sistema->VerVentas().Ranking(seleccion,m_sistema->VerStock());
	for(size_t i=0;i<aux.size();i++) {
		for(size_t j=0;j<aux.size();j++) { 
			if(aux[i].cant==aux[j].cant){
				pos = m_sistema -> VerStock().BuscarID(aux[i].id);
				Producto p = m_sistema -> VerStock().VerProductoStock(pos);
				posj = m_sistema -> VerStock().BuscarID(aux[j].id);
				Producto p2 = m_sistema -> VerStock().VerProductoStock(posj);
				if(p.VerNombre()<p2.VerNombre()){
					xx=aux[i];
					aux[i]=aux[j];
					aux[j]=xx;
				}
			}
		}
	}
	for(size_t i=0;i<aux.size();i++) { 
		grilla_ranking-> AppendRows();
		pos = m_sistema -> VerStock().BuscarID(aux[i].id);
		Producto p = m_sistema -> VerStock().VerProductoStock(pos);
		str_prod=p.VerNombre()+" "+p.VerMarca()+" | "+std::to_string(aux[i].cant);
		if(aux[i].cant>1){
			str_prod+=" unidades";
		}else{
			str_prod+=" unidad";
		}
		if (p.VerEliminado()) {
			str_prod += "   ///  ''Prod. discontinuado''";
		}
		grilla_ranking->SetCellValue(grilla_ranking->GetNumberRows()-1,0,str_prod);
	}
	grilla_ranking-> AutoSizeColumns();
	grilla_ranking-> AutoSizeRows();
}

