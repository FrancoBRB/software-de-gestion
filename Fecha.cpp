#include "Fecha.h"
#include <tuple>
#include <ctime>
#include <cstring>

int VerFechaActual(){
	time_t t1 = time(NULL);
	tm *ptm2 = localtime(&t1);
	return aaaammdd(ptm2->tm_year+1900,ptm2->tm_mon+1,ptm2->tm_mday);;
}

int aaaammdd(int anio,int mes,int dia){
	int aaaammdd=anio*10000+mes*100+dia;
	return aaaammdd;
}

std::tuple<int,int,int>FechaSeparada(int aaaammdd){
	int anio,mes,dia,aux;
	anio=aaaammdd / 10000;
	aux=aaaammdd % 10000;
	mes=aux /100;
	dia=aux%100;
	return std::make_tuple(dia,mes,anio);
}

std::string FechaString(int aaaammdd){
	int dia,mes,anio;
	std::tie(dia,mes,anio)=FechaSeparada(aaaammdd);
	std::string fecha=std::to_string(dia)+"/"+std::to_string(mes)+"/"+std::to_string(anio);
	return fecha;
}
