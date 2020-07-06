#include <iostream>
using namespace std;
#include <cstdlib>
#include "Articulo.h"
#include "Proveedor.h"
#include "Pedido.h"
#include "Grilla.h"
#include "Listado.h"
#include "Deposito.h"
#include "Funciones.h"

void Deposito::menuPrincipal()
{
    bool salir = false;
    int opcion;
    while(!salir)
    {
        system("cls");
        cout<<"|"<<endl;
        cout<<"|            MENU PRINCIPAL"<<endl;
        cout<<"|"<<endl;
        cout<<"|        1) ARTICULO"<<endl;
        cout<<"|        2) PROVEEDOR"<<endl;
        cout<<"|        3) PEDIDO"<<endl;
        cout<<"|        4) ENGRILLAR/DESENGRILLAR"<<endl;
        cout<<"|        5) LISTADOS"<<endl;
        cout<<"|"<<endl;
        cout<<"|        0) SALIR DEL PROGRAMA"<<endl;
        cout<<"|"<<endl;
        opcion= ingresoEnteroValidado();
        switch(opcion)
        {
        case 1:
        {
            menuArticulo();
        }
        break;
        case 2:
        {
            menuProveedor();
        }
        break;
        case 3:
        {
            menuPedido();
        }
        break;
        case 4:
        {
            menuGrilla();
        }
        break;
        case 5:
        {
            menuListado();
        }
        break;
        default:
        {
            cout<<"|    OPCION NO VALIDA!"<<endl;
            system("pause");
        }
        break;
        case 0:
        {
            salir=true;
        }
        break;

        }
    }
}
void Deposito::menuArticulo()
{
    Articulo art;
    bool salir = false;
    int opcion;
    while(!salir)
    {
        system("cls");
        cout<<"|"<<endl;
        cout<<"|            MENU ARTICULO"<<endl;
        cout<<"|"<<endl;
        cout<<"|        1) CARGAR ARTICULO"<<endl;
        cout<<"|        2) MOSTRAR ARTICULO"<<endl;
        cout<<"|        3) MODIFICAR CANTIDAD ARTICULO"<<endl;
        cout<<"|"<<endl;
        cout<<"|        0) VOLVER AL MENU"<<endl;
        cout<<"|"<<endl;
        opcion= ingresoEnteroValidado();
        switch(opcion)
        {
        case 1:
        {
            art.nuevo();
            system("pause");
        }
        break;
        case 2:
        {
            mostrarxid_Articulo();
            system("pause");
        }
        break;
        case 3:
        {
            modificarArticulo();
            system("pause");
        }
        break;
        default:
        {
            cout<<"|    OPCION NO VALIDA!"<<endl;
            system("pause");
        }
        break;
        case 0:
        {
            salir=true;
        }
        break;

        }
    }
}


void Deposito::menuProveedor()
{
    Proveedor prov;
    bool salir = false;
    int opcion;
    while(!salir)
    {
        system("cls");
        cout<<"|"<<endl;
        cout<<"|            MENU PROVEEDOR"<<endl;
        cout<<"|"<<endl;
        cout<<"|        1) CARGAR PROVEEDOR"<<endl;
        cout<<"|        2) MOSTRAR PROVEEDOR"<<endl;
        cout<<"|        3) MODIFICAR PROVEEDOR"<<endl;
        cout<<"|"<<endl;
        cout<<"|        0) VOLVER AL MENU"<<endl;
        cout<<"|"<<endl;
        opcion= ingresoEnteroValidado();
        switch(opcion)
        {
        case 1:
        {
            prov.nuevo();
            system("pause");
        }
        break;
        case 2:
        {
            mostrarxid_Proovedor();
            system("pause");
        }
        break;
        case 3:
        {
            modificarProveedor();
            system("pause");
        }
        break;
        default:
        {
            cout<<"|    OPCION NO VALIDA!"<<endl;
            system("pause");
        }
        break;
        case 0:
        {
            salir=true;
        }
        break;
        }
    }
}
void Deposito::menuPedido()
{
    Pedido ped;
    bool salir = false;
    int opcion;
    while(!salir)
    {
        system("cls");
        cout<<"|"<<endl;
        cout<<"|            MENU PEDIDO"<<endl;
        cout<<"|"<<endl;
        cout<<"|        1) CARGAR PEDIDO"<<endl;
        cout<<"|        2) MOSTRAR PEDIDO"<<endl;
        cout<<"|        3) INGRESAR PEDIDO"<<endl;
        cout<<"|"<<endl;
        cout<<"|        0) VOLVER AL MENU"<<endl;
        cout<<"|"<<endl;
        opcion= ingresoEnteroValidado();
        switch(opcion)
        {
        case 1:
        {
            ped.nuevo();
            system("pause");
        }
        break;
        case 2:
        {
            mostrarxid_pedido();
            system("pause");
        }
        break;
        case 3:
        {
            ingresarPedido();
            system("pause");
        }
        break;
        default:
        {
            cout<<"|    OPCION NO VALIDA!"<<endl;
            system("pause");
        }
        break;
        case 0:
        {
            salir=true;
        }
        break;
        }
    }
}
void Deposito::menuGrilla()
{
    Grilla gri;
    bool salir = false;
    int opcion;
    while(!salir)
    {
        system("cls");
        cout<<"|"<<endl;
        cout<<"|            MENU GRILLA"<<endl;
        cout<<"|"<<endl;
        cout<<"|        1) ENGRILLAR"<<endl;
        cout<<"|        2) DESENGRILLAR"<<endl;
        cout<<"|        3) MOSTRAR GRILLA POR ID"<<endl;
        cout<<"|"<<endl;
        cout<<"|        0) VOLVER AL MENU"<<endl;
        cout<<"|"<<endl;
        opcion= ingresoEnteroValidado();
        switch(opcion)
        {
        case 1:
        {
            gri.nuevo();
            system("pause");
        }
        break;
        case 2:
        {
            desengrillar();
            system("pause");
        }
        break;
        case 3:
        {
             mostrarGrillaxId();
            system("pause");
        }
        break;
        default:
        {
            cout<<"|    OPCION NO VALIDA!"<<endl;
            system("pause");
        }
        break;
        case 0:
        {
            salir=true;
        }
        break;
        }
    }

}
void Deposito::menuListado()
{
    bool salir = false;
    int opcion;
    while(!salir)
    {
        system("cls");
        cout<<"|"<<endl;
        cout<<"|            MENU LISTADO"<<endl;
        cout<<"|"<<endl;
        cout<<"|        1) LISTAR ARTICULOS"<<endl;
        cout<<"|        2) LISTAR PROVEEDORES"<<endl;
        cout<<"|        3) LISTAR GRILLA"<<endl;
        cout<<"|        4) LISTAR PEDIDOS INGRESADOS"<<endl;
        cout<<"|        5) LISTAR PEDIDOS NO INGRESADOS"<<endl;
        cout<<"|"<<endl;
        cout<<"|        0) VOLVER AL MENU"<<endl;
        cout<<"|"<<endl;
        opcion= ingresoEnteroValidado();
        switch(opcion)
        {
        case 1:
        {
            listarArticulos();
            system("pause");
        }
        break;
        case 2:
        {
            listarProveedores();
            system("pause");
        }
        break;
        case 3:
        {
            listarGrilla();
            system("pause");
        }
        break;
        case 4:
        {
            listarPedidosIngresados();
            system("pause");
        }
        break;
        case 5:
        {
            listarPedidosNoIngresados();
            system("pause");
        }
        break;
        default:
        {
            cout<<"|    OPCION NO VALIDA!"<<endl;
            system("pause");
        }
        break;
        case 0:
        {
            salir=true;
        }
        break;
        }
    }
}
