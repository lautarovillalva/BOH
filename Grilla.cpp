#include <iostream>
using namespace std;
#include <iomanip>
#include "cstdio"
#include "Grilla.h"
#include "Articulo.h"
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
int Grilla::getIdArticulo()
{
    return idArticulo;
}
Contenedor Grilla::getContenedor()
{
    return cont;
}
bool Grilla::getEstado()
{
    return estado;
}
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
        cout<<"------------------------------------------"<<endl;
        cout<<"-    CARGADO CORRECTAMENTE!              -"<<endl;
        cout<<"------------------------------------------"<<endl;
        if(guardar()==true)
        {
            cout<<"------------------------------------------"<<endl;
            cout<<"-    GUARDADO CORRECTAMENTE!             -"<<endl;
            cout<<"------------------------------------------"<<endl;
        }
        else
        {
            cout<<"------------------------------------------"<<endl;
            cout<<"-    ERROR AL GUARDAR!                   -"<<endl;
            cout<<"------------------------------------------"<<endl;
        }
    }
    else
    {
        cout<<"------------------------------------------"<<endl;
        cout<<"-    ERROR AL CARGAR!                    -"<<endl;
        cout<<"------------------------------------------"<<endl;
    }

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
    Articulo art;
    cout<<"------------------------------------------"<<endl;
    cout<<"-    ENGRILLAR                           -"<<endl;
    cout<<"------------------------------------------"<<endl;
    cout<<"-    CARGAR ID ARTICULO  : ";
    idArticulo= ingresoEnteroValidado();
    int pos= buscarArticulo(idArticulo);
    if(pos== -2)
    {
        cout<<"------------------------------------------"<<endl;
        cout<<"-    NO SE PUDO ABRIR EL ARCHIVO!        -"<<endl;
        cout<<"------------------------------------------"<<endl;
    }
    if(pos== -1)
    {
        cout<<"------------------------------------------"<<endl;
        cout<<"-    ID ARTICULO NO ENCONTRADO!          -"<<endl;
        cout<<"------------------------------------------"<<endl;
    }
    if(pos< 0)
        return false;
    art.leer(pos);
    cout<<"-    "<<art.getModelo()<< endl;
    if(setIdArticulo(idArticulo)== false)
        return false;
    if(cont.cargar()== false)
        return false;
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
        cout<<setw(9)<<right<<"|"<<endl;
    }
}
void desengrillar()
{
    int idaux;
    Articulo art;
    Grilla gri;
    cout<<"------------------------------------------"<<endl;
    cout<<"-    DESENGRILLAR" << endl;
    cout<<"------------------------------------------"<<endl;
    cout<<"-    ID ARTICULO QUE DESEA DESENGRILLAR: ";
    idaux= ingresoEnteroValidado();
    int pos= buscarArticulo(idaux);
    if(pos== -2)
    {
        cout<<"------------------------------------------"<<endl;
        cout<<"-    NO SE PUDO ABRIR EL ARCHIVO!        -"<<endl;
        cout<<"------------------------------------------"<<endl;
    }
    if(pos== -1)
    {
        cout<<"------------------------------------------"<<endl;
        cout<<"-    ID ARTICULO NO ENCONTRADO!          -"<<endl;
        cout<<"------------------------------------------"<<endl;
    }
    if(pos<0)
        return;
    art.leer(pos);
    cout<<"-    "<<art.getModelo()<< endl;
    FILE * p;
    p= fopen(ARCHIVO_GRILLA, "rb+");
    if(p==NULL)
    {
        cout<<"------------------------------------------"<<endl;
        cout<<"-    NO SE PUDO ABRIR EL ARCHIVO!        -"<<endl;
        cout<<"------------------------------------------"<<endl;
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
                if(fwrite(&gri, sizeof(Grilla), 1, p)== true)
                    cout<<"-  DESENGRILLADO CORRECTAMENTE! "<< endl;
            }
        }
    }
    fclose(p);
}
void mostrarGrillaxId()
{
    Articulo art;
    Grilla gri;
    int idaux;
    cout<<"------------------------------------------"<<endl;
    cout<<"-    MOSTRAR GRILLA DE ARTICULO          -"<< endl;
    cout<<"------------------------------------------"<<endl;
    cout<<"-    ID DE ARTICULO      : ";
    idaux= ingresoEnteroValidado();
    int pos= buscarArticulo(idaux);
    if(pos== -2)
    {
        cout<<"------------------------------------------"<<endl;
        cout<<"-    NO SE PUDO ABRIR EL ARCHIVO!        -"<<endl;
        cout<<"------------------------------------------"<<endl;
    }
    if(pos== -1)
    {
        cout<<"------------------------------------------"<<endl;
        cout<<"-    ID ARTICULO NO ENCONTRADO!          -"<<endl;
        cout<<"------------------------------------------"<<endl;
    }
    if(pos< 0)
        return;
    art.leer(pos);
    cout<<"-    "<<art.getModelo()<< endl;
    FILE * p;
    p= fopen(ARCHIVO_GRILLA, "rb");
    if(p==NULL)
    {
        cout<<"------------------------------------------"<<endl;
        cout<<"-    NO SE PUDO ABRIR EL ARCHIVO!        -"<<endl;
        cout<<"------------------------------------------"<<endl;
        return;
    }
    while(fread(&gri, sizeof(Grilla), 1, p)== true)
    {
        if(idaux== gri.getIdArticulo() && gri.getEstado()==true )
        {
            cout<<"-    ";
            gri.getContenedor().mostrar();
            cout<< endl;
        }
    }
    cout<<"------------------------------------------"<<endl;
    fclose(p);
}
