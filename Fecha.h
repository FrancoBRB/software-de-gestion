#ifndef FECHA_H
#define FECHA_H
#include <tuple>
#include <ctime>
#include <string>
#include <cstring>
int VerFechaActual();
int aaaammdd(int anio,int mes,int dia);
std::tuple<int,int,int>FechaSeparada(int aaaammdd);
std::string FechaString(int aaaammdd);
#endif
