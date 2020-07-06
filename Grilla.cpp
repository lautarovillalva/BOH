#include <iostream>
using namespace std;
#include <iomanip>
#include "cstdio"
#include "Grilla.h"
#include "Contenedor.h"
#include "Funciones.h"

bool Grilla::setIdArticulo(int idArticulo)
{
    bool x= true;
    //val
    this->idArticulo= idArticulo;
    return x;

}
bool Grilla::setContenedor(Contenedor cont)
{
    bool x= true;
    //val
    this->cont= cont;
    return x;
}
void Grilla::setEstado(bool estado)
{
    this->estado= estado;
}
//getters
int Grilla::getIdArticulo(){return idArticulo;}
Contenedor Grilla::getContenedor(){return cont;}
bool Grilla::getEstado(){return estado;}
//constuctor
Grilla::Grilla()
{
    setIdArticulo(0);
    setEstado(false);
}
void Grilla::nuevo()
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
bool Grilla::guardar()
{
    bool guardado=false;
    FILE * p;
    p=fopen(ARCHIVO_GRILLA,"ab");
    if(p!=NULL)
    {
        fwrite(this,sizeof(Grilla), 1, p);
        guardado=true;
    }
    fclose(p);
    return guardado;
}
bool Grilla::cargar()
{
    cout<<"-    ENGRILLAR"<<endl;
    cout<<"-    CARGAR ID ARTICULO: ";
    cin>> idArticulo;
    if(setIdArticulo(idArticulo)== false) return false;
    if(cont.cargar()== false) return false;
    setEstado(true);
    return true;
}
void Grilla::mostrar(int modo)
{
    if(modo==1)
    {
        cout<<"-    ID ARTICULO:"<< idArticulo <<endl;
        cout<<"-    CONTENEDOR:";
        cont.mostrar();
        cout<< endl;
    }
    if(modo==2)
    {
        cout<<"|"<<setw(12)<<left<<idArticulo<<"|";
        cont.mostrar();
        cout<<setw(8)<<right<<"|"<<endl;
    }
}
void desengrillar()
{
    int idaux;
    Grilla gri;
    cout<<"-    DESENGRILLAR" << endl;
    cout<<"-    ID ARTICULO QUE DESEA DESENGRILLAR: ";
    cin>> idaux;
    FILE * p;
    p= fopen(ARCHIVO_GRILLA, "rb+");
    if(p==NULL)
    {
        cout<<"-    NO SE PUDO ABRIR EL ARCHIVO!" << endl;
        return;
    }
    while(fread(&gri, sizeof(Grilla), 1, p)== true)
    {
        if(idaux== gri.getIdArticulo() && gri.getEstado()==true )
        {
            gri.getContenedor().mostrar();
            int op;
            cout<<"-    DESENGRILLAR?   1)SI    2)NO "<<endl;
            cin>>op;
            if(op==1)
            {
                gri.setEstado(false);
                fseek(p, ftell(p)-sizeof(Grilla), SEEK_SET);
                if(fwrite(&gri, sizeof(Grilla), 1, p)== true) cout<<"-  DESENGRILLADO CORRECTAMENTE! "<< endl;
            }
        }
    }
    fclose(p);
}
void mostrarGrillaxId()
{
    Grilla gri;
    int aux;
    cout<<"-    MOSTRAR GRILLA DE ARTICULO"<< endl;
    cout<<"-    ID DE ARTICULO: ";
    aux= ingresoEnteroValidado();
    FILE * p;
    p= fopen(ARCHIVO_GRILLA, "rb");
    if(p==NULL)
    {
        cout<<"-    NO SE PUDO ABRIR EL ARCHIVO!" << endl;
        return;
    }
    while(fread(&gri, sizeof(Grilla), 1, p)== true)
    {
        if(aux== gri.getIdArticulo() && gri.getEstado()==true )
        {
            gri.getContenedor().mostrar();
            cout<< endl;
        }
    }
    fclose(p);
}




