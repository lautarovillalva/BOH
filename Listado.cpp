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
        cout<<"------------------------------------------"<<endl;
        cout<<"-    NO SE PUDO ABRIR EL ARCHIVO!        -"<<endl;
        cout<<"------------------------------------------"<<endl;
        return;
    }
    cout<<"------------------------------------------"<<endl;
    cout<<"-        PEDIDOS NO INGRESADOS           -"<<endl;
    cout<<"------------------------------------------"<<endl;
//    cout<<"|"<<setw(12)<<left<<"FECHA";
//    cout<<"|"<<setw(10)<<left<<"CODIGO"<<"|"<<setw(12)<<"COD. ART."<<"|"<<setw(12)<<"COD. PROV."<<"|"<<setw(10)<<"CANTIDAD"<<"|"<<endl;
    while(fread(&ped, sizeof(Pedido), 1, p)==true)
    {
        if(ped.getEstado()==true)
            ped.mostrar(1);
    }
    cout<<"------------------------------------------"<<endl;
    fclose(p);
}
void listarPedidosIngresados()
{
    Pedido ped;
    FILE * p;
    p=fopen(ARCHIVO_PEDIDOS, "rb");
    if(p==NULL)
    {
        cout<<"------------------------------------------"<<endl;
        cout<<"-    NO SE PUDO ABRIR EL ARCHIVO!        -"<<endl;
        cout<<"------------------------------------------"<<endl;
        return;
    }
    cout<<"------------------------------------------"<<endl;
    cout<<"-        PEDIDOS INGRESADOS              -"<<endl;
    cout<<"------------------------------------------"<<endl;
//    cout<<"|"<<setw(12)<<"FECHA";
//    cout<<"|"<<setw(10)<<left<<"CODIGO"<<"|"<<setw(12)<<"COD. ART."<<"|"<<setw(12)<<"COD. PROV."<<"|"<<setw(10)<<"CANTIDAD"<<"|"<<endl;
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
        cout<<"------------------------------------------"<<endl;
        cout<<"-    NO SE PUDO ABRIR EL ARCHIVO!        -"<<endl;
        cout<<"------------------------------------------"<<endl;
        return;
    }
    cout<<"------------------------------------------"<<endl;
    cout<<"-        LISTAR ARTICULOS                -"<<endl;
    cout<<"------------------------------------------"<<endl;
    int i;
    for(i=0; i<62; i ++)
        cout<<"-";
    cout<<endl;
    cout<<"|"<<setw(10)<<left<<"ID"<<"|"<<setw(20)<<left<<"MODELO"<<"|"<<setw(5)<<left<<"TALLE"<<"|"<<setw(10)<<left<<"GENERO"<<"|"<<setw(5)<<left<<"CANT."<<"|"<<setw(5)<<left<<"AR$"<<"|"<<endl;
    for(i=0; i<62; i ++)
        cout<<"-";
    cout<<endl;
    while(fread(&art, sizeof(Articulo),1, p)==true)
    {
        art.mostrar(2);
    }
    for(i=0; i<62; i ++)
        cout<<"-";
    cout<<endl;
}
void listarProveedores()
{
    Proveedor prov;
    FILE * p;
    p=fopen(ARCHIVO_PROVEEDORES, "rb");
    if(p==NULL)
    {
        cout<<"------------------------------------------"<<endl;
        cout<<"-    NO SE PUDO ABRIR EL ARCHIVO!        -"<<endl;
        cout<<"------------------------------------------"<<endl;
        return;
    }
    cout<<"------------------------------------------"<<endl;
    cout<<"-        LISTAR PROVEEDORES              -"<<endl;
    cout<<"------------------------------------------"<<endl;
    for(int i=0; i<110; i++)
        cout<<"-";
    cout<< endl;
    cout<<"|"<<setw(10)<<left<<"CODIGO"<<"|"<<setw(20)<<"RAZON SOCIAL"<<"|"<<setw(12)<<"CUIT"<<"|"<<setw(20)<<"DIRECCION"<<"|"<<setw(30)<<"MAIL"<<"|"<<setw(11)<<"TELEFONO"<<"|"<<endl;
    for(int i=0; i<110; i++)
        cout<<"-";
    cout<< endl;
    while(fread(&prov, sizeof(Proveedor), 1, p)==true)
    {
        prov.mostrar(2);
    }
    for(int i=0; i<110; i++)
        cout<<"-";
    cout<< endl;
    fclose(p);
}
void listarGrilla()
{
    Grilla gri;
    FILE * p;
    p=fopen(ARCHIVO_GRILLA, "rb");
    if(p==NULL)
    {
        cout<<"------------------------------------------"<<endl;
        cout<<"-    NO SE PUDO ABRIR EL ARCHIVO!        -"<<endl;
        cout<<"------------------------------------------"<<endl;
        return;
    }
    cout<<"------------------------------------------"<<endl;
    cout<<"-        LISTAR GRILLA                   -"<<endl;
    cout<<"------------------------------------------"<<endl;
    for(int i=0; i<27; i++)
        cout<<"-";
    cout<<endl;
    cout<<"|"<<setw(12)<<left<<"COD. ART."<<"|"<<setw(12)<<"CONTENEDOR"<<"|"<<endl;
    for(int i=0; i<27; i++)
        cout<<"-";
    cout<<endl;
    while(fread(&gri, sizeof(Grilla), 1, p)==true)
    {
        if(gri.getEstado()==true)
            gri.mostrar(2);
    }
    for(int i=0; i<27; i++)
        cout<<"-";
    cout<<endl;
    fclose(p);
}
