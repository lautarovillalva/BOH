#include <iostream>
using namespace std;
#include "cstdio"
#include "cstdlib"
#include "cstring"
#include "iomanip"
#include "Funciones.h"
#include "Articulo.h"


//const char ARCHIVO_ARTICULOS[]="articulos.dat";

//setters
bool Articulo::setId(int id)
{
    bool x= true;
    //val
    this->id=id;
    return x;
}
bool Articulo::setModelo(const char * modelo)
{
    bool x= true;
    //val
    strcpy(this->modelo, modelo);
    return x;
}
bool Articulo::setTalle(const char * talle)
{
    bool x= true;
    //val
    strcpy(this->talle, talle);
    return x;
}
bool Articulo::setGenero( const char * genero)
{
    bool x= true;
    //val
    strcpy(this->genero, genero);
    return x;
}
bool Articulo::setCantidad(int cantidad)
{
    bool x= true;
    //val
    this->cantidad= cantidad;
    return x;
}
bool Articulo::setPrecio(float precio)
{
    bool x= true;
    //val
    this->precio= precio;
    return x;
}
//getters
int Articulo::getId(){return id;}
const char * Articulo::getModelo(){return modelo;}
const char * Articulo::getTalle(){return talle;}
const char * Articulo::getGenero(){return genero;}
int Articulo::getCantidad(){return cantidad;}
float Articulo::getPrecio(){return precio;}
//constructor
Articulo::Articulo()
{
    setId(0);
    setModelo(" ");
    setTalle(" ");
    setGenero(" ");
    setCantidad(0);
    setPrecio(0);
}

int generarID_articulo()
{
    FILE *p;
    p=fopen(ARCHIVO_ARTICULOS,"ab");
    fseek(p,0,SEEK_END);
    int id=((ftell(p)/sizeof(Articulo)))+100;
    fclose(p);
    return id;
}
void Articulo::nuevo()
{
    if(cargar()==true)
    {
        cout<<"-    CARGADO CORRECTAMENTE!"<<endl;
        if(guardar()==true)
            cout<<"-    GUARDADO CORRECTAMENTE!"<<endl;
        else
            cout<<"-    ERROR AL GUARDAR!"<<endl;
    }
    else
        cout<<"-    ERROR AL CARGAR!"<<endl;
}
bool Articulo::guardar()
{
    bool guardado=false;
    FILE * p;
    p=fopen(ARCHIVO_ARTICULOS,"ab");
    if(p!=NULL)
    {
        fwrite(this,sizeof(Articulo), 1, p);
        guardado=true;
    }
    fclose(p);
    return guardado;
}
bool Articulo::cargar()
{

    setId(generarID_articulo());
    cout<<"-    1) CARGAR ARTICULO"<<endl;
    cout<<"-    CARGAR ID       : ";
    cout<< getId() << endl;
    cout<<"-    CARGAR MODELO   : ";
    cargarcadena(modelo, 20);
    if(setModelo(modelo)==false) return false;
    cout<<"-    CARGAR TALLE    : ";
    cargarcadena(talle, 5);
    if(setTalle(talle)== false) return false;
    cout<<"-    CARGAR GENERO   : ";
    cargarcadena(genero, 10);
    if(setGenero(genero)== false) return false;
    cout<<"-    CARGAR PRECIO   :$";
    precio= ingresoFlotanteValidado();
    if(setPrecio(precio)== false) return false;
    setCantidad(0);
    return true;
}

void Articulo::mostrar(int modo)
{
    if(modo== 1)
    {
        cout<<"-       ID: " << id << endl;
        cout<<"-   MODELO: " << modelo << endl;
        cout<<"-    TALLE: " << talle << endl;
        cout<<"-   GENERO: " << genero << endl;
        cout<<"- CANTIDAD: " << cantidad << endl;
        cout<<"-   PRECIO: $" << precio << endl;
    }
    if(modo== 2)
    {
        cout<<"|"<<setw(10)<<left<<id<<"|"<<setw(20)<<left<<modelo<<"|"<<setw(5)<<left<<talle<<"|"<<setw(10)<<left<<genero<<"|"<<setw(5)<<left<<cantidad<<"|"<<setw(5)<<left<<precio<<"|"<<endl;
    }
}

void modificarArticulo()
{
    bool modificado= false;
    int aux;
    Articulo obj;
    cout<<"-    MODIFICAR ARTICULO"<<endl;
    cout<<"-    ID ARTICULO QUE DESEA MODIFICAR: ";
    aux= ingresoEnteroValidado();
    FILE * p;
    p=fopen(ARCHIVO_ARTICULOS, "rb+");
    if(p==NULL)
    {
        cout<<"- NO SE PUDO ABRIR EL ARCHIVO!"<< endl;
        return;
    }
    while(fread(&obj, sizeof(Articulo), 1, p)== true)
    {
        if(aux==obj.getId())
        {
            int aux2;
            cout<<"-    "<<obj.getModelo()<<endl;
            cout<<"-    MODIFICAR NUEVA CANTIDAD: ";
            aux2= ingresoEnteroValidado();
            if(obj.setCantidad(aux2)== false) return;
            fseek(p, ftell(p)-sizeof(Articulo), SEEK_SET);
            modificado= fwrite(&obj, sizeof(Articulo), 1, p);
            cout<<"- GUARDADO EXITOSO!" <<endl;
            break;
        }
    }
    if(modificado==false)
    {
        cout<<"- ERROR AL MODIFICAR ARTICULO!" << endl;
    }
    fclose(p);

}
void mostrarxid_Articulo()
{
    cout<<"-         MOSTRAR ARTICULO POR ID"<<endl;
    bool mostrado=false;
    int idaux;
    cout<<"- ID ARTICULO QUE DESEA MOSTRAR: ";
    idaux= ingresoEnteroValidado();
    FILE * p;
    Articulo obj;
    p = fopen(ARCHIVO_ARTICULOS, "rb");
    if(p== NULL)
    {
        cout<<"- NO SE PUDO ABRIR EL ARCHIVO!"<< endl;
        return;
    }
    while(fread(&obj, sizeof(Articulo), 1, p)== true)
    {
        if(idaux== obj.getId())
        {
            obj.mostrar(1);
            mostrado=true;
        }
    }
    if(mostrado==false)
    {
        cout<<"- ID CLIENTE NO ENCONTRADO!" << endl;
    }
    fclose(p);
}




