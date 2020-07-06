#include <iostream>
using namespace std;
#include "cstdlib"
#include "Fecha.h"
#include "Pedido.h"
#include "Articulo.h"
#include "Funciones.h"


//setters
bool Pedido::setCodigo(int codigo)
{
    bool x= true;
    //val
    this->codigo= codigo;
    return x;
}
bool Pedido::setIDArticulo(int ida)
{
    bool x= true;
    //val
    this->idArticulo= ida;
    return x;
}
bool Pedido::setIDProveedor(int idp)
{
    bool x= true;
    //val
    this->idProveedor= idp;
    return x;
}
bool Pedido::setFechaEncargo(Fecha fen)
{
    bool x= true;
    //val
    this->f_encargo=fen;
    return x;
}
bool Pedido::setFechaIngreso(Fecha fin)
{
    bool x= true;
    //val
    this->f_ingreso= fin;
    return x;
}
bool Pedido::setCantidad(int cantidad)
{
    bool x= true;
    //val
    this->cantidad= cantidad;
    return x;
}
void Pedido::setEstado(bool estado)
{
    this->estado= estado;
}
//getters
int Pedido::getCodigo(){return codigo;}
int Pedido::getIDArticulo(){return idArticulo;}
int Pedido::getIDProveedor(){return idProveedor;}
Fecha Pedido::getFechaEncargo(){return f_encargo;}
Fecha Pedido::getFechaIngreso(){return f_ingreso;}
int Pedido::getCantidad(){return cantidad;}
bool Pedido::getEstado(){return estado;}
//constructor
Pedido::Pedido()
{
    setCodigo(0);
    setIDArticulo(0);
    Fecha fec;
    fec.setHoy();
    setFechaEncargo(fec);
    setFechaIngreso(fec);
    setIDProveedor(0);
    setCantidad(0);
    setEstado(0);
}
int generarID_pedido()
{
    FILE *p;
    p=fopen(ARCHIVO_PEDIDOS,"ab");
    fseek(p,0,SEEK_END);
    int id=((ftell(p)/sizeof(Pedido)))+1000;
    fclose(p);
    return id;
}
void Pedido::nuevo()
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
bool Pedido::guardar()
{
    bool guardado=false;
    FILE * p;
    p=fopen(ARCHIVO_PEDIDOS,"ab");
    if(p!=NULL)
    {
        fwrite(this,sizeof(Pedido), 1, p);
        guardado=true;
    }
    fclose(p);
    return guardado;
}
bool Pedido::cargar()
{
    Fecha fec;
    fec.setHoy();
    setFechaEncargo(fec);
    fec.setDia(0);
    fec.setMes(0);
    fec.setAnio(0);
    setFechaIngreso(fec);
    setCodigo(generarID_pedido());
    cout<<"-    CARGAR PEDIDO" << endl;
    cout<<"-    CARGAR CODIGO DE PEDIDO: "<< getCodigo() << endl;
    cout<<"-    CARGAR ID ARTICULO     :";
    idArticulo= ingresoEnteroValidado();
    if(setIDArticulo(idArticulo)== false) return false;
    cout<<"-    CARGAR ID PROVEEDOR    : ";
    idProveedor= ingresoEnteroValidado();
    if(setIDProveedor(idProveedor)== false) return false;
    cout<<"-    CARGAR CANTIDAD        : ";
    cantidad= ingresoEnteroValidado();
    if(setCantidad(cantidad)== false) return false;
    setEstado(1);
    return true;
}
void Pedido::mostrar(int modo)
{
    if(modo== 1)
    {
        cout<<"- CODIGO           : "<< codigo <<endl;
        cout<<"- ID ARTICULO      : "<< idArticulo<<endl;
        cout<<"- ID PROVEEDOR     : "<< idProveedor<<endl;
        if(estado== true)
        {
            cout<<"- FECHA DE ENCARGO : ";
            getFechaEncargo().MostrarFecha();
        }
        else
        {
            cout<<"- FECHA DE ENCARGO : ";
            getFechaEncargo().MostrarFecha();
            cout<<"- FECHA DE INGRESO : ";
            getFechaIngreso().MostrarFecha();
        }
        cout<<"- CANTIDAD PEDIDA  : " << cantidad << endl;
    }
}
void mostrarxid_pedido()
{
        cout<<"-         MOSTRAR PEDIDO POR CODIGO"<<endl;
    bool mostrado=false;
    int idaux;
    cout<<"- CODIGO DE PEDIDO QUE DESEA MOSTRAR: ";
    idaux= ingresoEnteroValidado();
    FILE * p;
    Pedido obj;
    p = fopen(ARCHIVO_PEDIDOS, "rb");
    if(p== NULL)
    {
        cout<<"- NO SE PUDO ABRIR EL ARCHIVO!"<< endl;
        return;
    }
    while(fread(&obj, sizeof(Pedido), 1, p)== true)
    {
        if(idaux== obj.getCodigo())
        {
            obj.mostrar(1);
            mostrado=true;
        }
    }
    if(mostrado==false)
    {
        cout<<"- CODIGO DE PEDIDO NO ENCONTRADO!" << endl;
    }
    fclose(p);
}
void ingresarPedido()
{
    bool encontrado= false;
    Pedido ped;
    Articulo art;
    int aux;
    cout<<"-    INGRESAR PEDIDO"<< endl;
    cout<<"- INGRESAR CODIGO DE PEDIDO:";
    aux= ingresoEnteroValidado();
    FILE * p;
    p=fopen(ARCHIVO_PEDIDOS, "rb+");
    if(p==NULL)
    {
        cout<<"-    NO SE PUDO ABRIR EL ARCHIVO!" << endl;
        return;
    }
    while(fread(&ped, sizeof(Pedido), 1, p)== true)
    {
        if(aux== ped.getCodigo() && ped.getEstado()== true)
        {
            Fecha fec;
            fec.setHoy();
            ped.setFechaIngreso(fec);
            ped.setEstado(false);
            fseek(p, ftell(p)-sizeof(Pedido), SEEK_SET);
            encontrado= fwrite(&ped, sizeof(Pedido), 1, p);
            if(encontrado== true) cout<<"-  PEDIDO ENCONTRADO!" <<endl;
            break;
        }
    }
    if(encontrado== false) cout<<"- ERROR AL ENCONTRAR PEDIDO! "<<endl;
    fclose(p);
    FILE * p1;
    p1= fopen(ARCHIVO_ARTICULOS, "rb+");
    if(p1==NULL)
    {
        cout<<"-    NO SE PUDO ABRIR EL ARCHIVO!" << endl;
    }
    while(fread(&art, sizeof(Articulo), 1, p)== true)
    {
        if(ped.getIDArticulo()==art.getId())
        {
            int cant;
            cant= ped.getCantidad()+art.getCantidad();
            art.setCantidad(cant);
            fseek(p1, ftell(p)-sizeof(Articulo), SEEK_SET);
            encontrado= fwrite(&art, sizeof(Articulo), 1, p);
            if(encontrado== true) cout<<"-  PEDIDO INGRESADO A STOCK!"<< endl;
            break;
        }
    }
    if(encontrado== false) cout<<"- ERROR AL INGRESAR PEDIDO AL STOCK! "<<endl;
    fclose(p1);
}
