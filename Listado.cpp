#include <iostream>
using namespace std;
#include "Funciones.h"
#include "Articulo.h"
#include "Proveedor.h"
#include "Pedido.h"
#include "Grilla.h"
#include "iomanip"

void listarPedidosNoIngresados()
{
    Pedido ped;
    FILE * p;
    p=fopen(ARCHIVO_PEDIDOS, "rb");
    if(p==NULL)
    {
        cout<<"-    NO SE PUDO ABRIR EL ARCHIVO!"<<endl;
        return;
    }
    cout<<"-        PEDIDOS INGRESADOS"<<endl;
    cout<<"|"<<setw(12)<<"FECHA";
    cout<<"|"<<setw(10)<<left<<"CODIGO"<<"|"<<setw(12)<<"COD. ART."<<"|"<<setw(12)<<"COD. PROV."<<"|"<<setw(10)<<"CANTIDAD"<<"|"<<endl;
    while(fread(&ped, sizeof(Pedido), 1, p)==true)
    {
        if(ped.getEstado()==true)
            ped.mostrar(1);
    }
    fclose(p);
}
void listarPedidosIngresados()
{
    Pedido ped;
    FILE * p;
    p=fopen(ARCHIVO_PEDIDOS, "rb");
    if(p==NULL)
    {
        cout<<"|    NO SE PUDO ABRIR EL ARCHIVO!"<<endl;
        return;
    }
    cout<<"|        PEDIDOS INGRESADOS"<<endl;
    cout<<"|"<<setw(12)<<"FECHA";
    cout<<"|"<<setw(10)<<left<<"CODIGO"<<"|"<<setw(12)<<"COD. ART."<<"|"<<setw(12)<<"COD. PROV."<<"|"<<setw(10)<<"CANTIDAD"<<"|"<<endl;
    while(fread(&ped, sizeof(Pedido), 1, p)==true)
    {
        if(ped.getEstado()==false)
            ped.mostrar(1);
    }
    fclose(p);
}
void listarArticulos()
{
    Articulo art;
    FILE * p;
    p=fopen(ARCHIVO_ARTICULOS, "rb");
    if(p==NULL)
    {
        cout<<"-    NO SE PUDO ABRIR EL ARCHIVO!"<<endl;
        return;
    }
    cout<<"-        LISTAR ARTICULOS"<<endl;
    while(fread(&art, sizeof(Articulo),1, p)==true)
    {
        art.mostrar(2);
    }
}
void listarProveedores()
{
    Proveedor prov;
    FILE * p;
    p=fopen(ARCHIVO_PROVEEDORES, "rb");
    if(p==NULL)
    {
        cout<<"-    NO SE PUDO ABRIR EL ARCHIVO!"<<endl;
        return;
    }
    cout<<"-        LISTAR PROVEEDORES" <<endl;
    cout<<"|"<<setw(10)<<left<<"CODIGO"<<"|"<<setw(20)<<"RAZON SOCIAL"<<"|"<<setw(12)<<"CUIT"<<"|"<<setw(20)<<"DIRECCION"<<"|"<<setw(30)<<"MAIL"<<"|"<<setw(11)<<"TELEFONO"<<"|"<<endl;
    while(fread(&prov, sizeof(Proveedor), 1, p)==true)
    {
        prov.mostrar(2);
    }
    fclose(p);
}
void listarGrilla()
{
    Grilla gri;
    FILE * p;
    p=fopen(ARCHIVO_GRILLA, "rb");
    if(p==NULL)
    {
        cout<<"-    NO SE PUDO ABRIR EL ARCHIVO!"<<endl;
        return;
    }
    cout<<"-        LISTAR GRILLA"<<endl;
    cout<<"|"<<setw(12)<<left<<"COD. ART."<<"|"<<setw(12)<<"CONTENEDOR"<<"|"<<endl;
    while(fread(&gri, sizeof(Grilla), 1, p)==true)
    {
        if(gri.getEstado()==true) gri.mostrar(2);
    }
    fclose(p);
}
