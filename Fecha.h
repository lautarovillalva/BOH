#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

#include <iostream>
#include <cstdio>
#include <ctime>
#include <string.h>

using namespace std;
///////////////CLASE FECHA
//Puede utilizarse para fechas desde el 01/01/1900

class Fecha
{
  private:
    int dia;
    int mes;
    int anio;
    bool esbisiesto(int);
    void NumeroSerieaFecha(int);
  public:
    Fecha(int d=0,int m=0,int a=0);
    void setHoy();
    int getDia(){return dia;}
    int getMes(){return mes;}
    int getAnio(){return anio;}
    void setDia(int d){dia=d;}
    void setMes(int m){mes=m;};
    void setAnio(int a){anio=a;}
    void MostrarFecha();
    void MostrarFechaTexto();
    int NumeroSerie();
    bool operator >(Fecha &);
    bool operator ==(Fecha &);
    Fecha operator+(int);
    int operator -(Fecha &);
    void operator +=(int);
    friend istream & operator>>(istream &, Fecha &);
    friend ostream & operator<<(ostream &, Fecha &);
};

#endif // FECHA_H_INCLUDED
