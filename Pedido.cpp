#include <iostream>
using namespace std;
#include "cstdlib"
#include "Fecha.h"
#include "Pedido.h"
#include "Articulo.h"
#include "Funciones.h"
#include "Proveedor.h"

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
int Pedido::getCodigo()
{
    return codigo;
}
int Pedido::getIDArticulo()
{
    return idArticulo;
}
int Pedido::getIDProveedor()
{
    return idProveedor;
}
Fecha Pedido::getFechaEncargo()
{
    return f_encargo;
}
Fecha Pedido::getFechaIngreso()
{
    return f_ingreso;
}
int Pedido::getCantidad()
{
    return cantidad;
}
bool Pedido::getEstado()
{
    return estado;
}
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
    Articulo art;
    Proveedor prov;
    int pos;
    Fecha fec;
    fec.setHoy();
    setFechaEncargo(fec);
    fec.setDia(0);
    fec.setMes(0);
    fec.setAnio(0);
    setFechaIngreso(fec);
    setCodigo(generarID_pedido());
    cout<<"------------------------------------------"<<endl;
    cout<<"-    CARGAR PEDIDO                       -"<< endl;
    cout<<"------------------------------------------"<<endl;
    cout<<"-    CODIGO AUTOGENERADO    : "<< getCodigo() << endl;
    cout<<"-    CARGAR ID ARTICULO     : ";
    idArticulo= ingresoEnteroValidado();
    pos= buscarArticulo(idArticulo);
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
        return false;
    art.leer(pos);
    cout<<"-    "<<art.getModelo()<< endl;
    if(setIDArticulo(idArticulo)== false)
        return false;
    cout<<"-    CARGAR ID PROVEEDOR    : ";
    idProveedor= ingresoEnteroValidado();
    pos= buscarProveedor(idProveedor);
    if(pos<0)
        return false;
    prov.leer(pos);
    cout<<"-    "<<prov.getRsocial()<< endl;
    if(setIDProveedor(idProveedor)== false)
        return false;
    cout<<"-    CARGAR CANTIDAD        : ";
    cantidad= ingresoEnteroValidado();
    if(setCantidad(cantidad)== false)
        return false;
    setEstado(1);
    return true;
}
void Pedido::mostrar(int modo)
{
    if(modo== 1)
    {
        cout<<"------------------------------------------"<<endl;
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
        cout<<"------------------------------------------"<<endl;
    }
}
void mostrarxid_pedido()
{
    cout<<"------------------------------------------"<<endl;
    cout<<"-         MOSTRAR PEDIDO POR CODIGO      -"<<endl;
    cout<<"------------------------------------------"<<endl;
    bool mostrado=false;
    int idaux;
    cout<<"- CODIGO DE PEDIDO QUE DESEA MOSTRAR: ";
    idaux= ingresoEnteroValidado();
    FILE * p;
    Pedido obj;
    p = fopen(ARCHIVO_PEDIDOS, "rb");
    if(p== NULL)
    {
        cout<<"------------------------------------------"<<endl;
        cout<<"- NO SE PUDO ABRIR EL ARCHIVO!           -"<< endl;
        cout<<"------------------------------------------"<<endl;
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
        cout<<"------------------------------------------"<<endl;
        cout<<"- CODIGO DE PEDIDO NO ENCONTRADO!        -" << endl;
        cout<<"------------------------------------------"<<endl;
    }
    fclose(p);
}
void ingresarPedido()
{
    bool encontrado= false;
    Pedido ped;
    Articulo art;
    int aux;
    cout<<"------------------------------------------"<<endl;
    cout<<"-    INGRESAR PEDIDO                     -"<<endl;
    cout<<"------------------------------------------"<<endl;
    cout<<"- INGRESAR CODIGO DE PEDIDO:";
    aux= ingresoEnteroValidado();
    FILE * p;
    p=fopen(ARCHIVO_PEDIDOS, "rb+");
    if(p==NULL)
    {
        cout<<"------------------------------------------"<<endl;
        cout<<"-    NO SE PUDO ABRIR EL ARCHIVO!        -"<<endl;
        cout<<"------------------------------------------"<<endl;
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
            if(encontrado== true)
            {
                cout<<"------------------------------------------"<<endl;
                cout<<"-    PEDIDO ENCONTRADO!                  -"<<endl;
                cout<<"------------------------------------------"<<endl;
            }
            break;
        }
    }
    if(encontrado== false)
    {
        cout<<"------------------------------------------"<<endl;
        cout<<"-    ERROR AL ENCONTRAR PEDIDO!          -"<<endl;
        cout<<"------------------------------------------"<<endl;
        fclose(p);
        return;
    }
    fclose(p);
    FILE * p1;
    p1= fopen(ARCHIVO_ARTICULOS, "rb+");
    if(p1==NULL)
    {
        cout<<"------------------------------------------"<<endl;
        cout<<"-    NO SE PUDO ABRIR EL ARCHIVO!        -"<<endl;
        cout<<"------------------------------------------"<<endl;
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
            if(encontrado== true)
            {
                cout<<"------------------------------------------"<<endl;
                cout<<"-    PEDIDO INGRESADO A STOCK!           -"<<endl;
                cout<<"------------------------------------------"<<endl;
            }
            break;
        }
    }
    if(encontrado== false)
    {
        cout<<"------------------------------------------"<<endl;
        cout<<"-    ERROR AL INGRESAR PEDIDO AL STOCK!  -"<<endl;
        cout<<"------------------------------------------"<<endl;
    }
    fclose(p1);
}
