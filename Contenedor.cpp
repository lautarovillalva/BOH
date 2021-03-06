#include <iostream>
using namespace std;
#include "cstdio"
#include "Contenedor.h"
#include "cstring"
//setters
bool Contenedor::setNumero(int numero)
{
    bool x= true;
    if(numero<0) return false;
    this->numero= numero;
    return x;
}
bool Contenedor::setEstante(char estante)
{
    bool x= true;
    //val
    estante=toupper(estante);
    this->estante= estante;
    return x;
}
//getters
int Contenedor::getNumero()
{
    return numero;
}
char Contenedor::getEstante()
{
    return estante;
}
//constructor
Contenedor::Contenedor()
{
    setNumero(0);
    setEstante(' ');
}
bool Contenedor::cargar()
{
    cout<<"-    INGRESAR CONTENEDOR : ";
    cin>>numero;
    if(setNumero(numero)== false)
        return false;
    cout<<"-    INGRESAR ESTANTE    : ";
    cin>>estante;
    if(setEstante(estante)== false)
        return false;
    return true;
}
void Contenedor::mostrar()
{
    cout<<"["<<numero<<estante<<"]";
}
