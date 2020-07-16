#include <iostream>
using namespace std;
#include "cstdio"
#include "cstdlib"
#include "cstring"
#include "iomanip"
#include "Funciones.h"
#include "Proveedor.h"



bool Proveedor::setId(int id)
{
    bool x= true;
    if(id<0) return false;
    this->id= id;
    return x;
}
bool Proveedor::setCuit(const char * cuit)
{
    bool x= true;
    if(strcmp(cuit,"\0")==0 || strcmp(cuit," ")==0) return false;
    strcpy(this->cuit, cuit);
    return x;
}
bool Proveedor::setTelefono(const char * telefono)
{
    bool x= true;
    //val
    strcpy(this->telefono, telefono);
    return x;
}
bool Proveedor::setRsocial(const char * rsocial)
{
    bool x= true;
    if(strcmp(rsocial,"\0")==0 || strcmp(rsocial," ")==0) return false;
    strcpy(this->rsocial, rsocial);
    return x;
}
bool Proveedor::setMail(const char * mail)
{
    bool x= true;
    //val
    strcpy(this->mail, mail);
    return x;
}
bool Proveedor::setDireccion(const char * direccion)
{
    bool x= true;
    //val
    strcpy(this->direccion, direccion);
    return x;
}
//getters
int Proveedor::getId()
{
    return id;
}
const char * Proveedor::getCuit()
{
    return cuit;
}
const char * Proveedor::getTelefono()
{
    return telefono;
}
const char * Proveedor::getRsocial()
{
    return rsocial;
}
const char * Proveedor::getDireccion()
{
    return direccion;
}
const char * Proveedor::getMail()
{
    return mail;
}
//constructor
Proveedor::Proveedor()
{
    setId(0);
    setCuit(" ");
    setTelefono(" ");
    setRsocial(" ");
    setMail(" ");
    setDireccion(" ");
}
void Proveedor::nuevo()
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
bool Proveedor::guardar()
{
    bool guardado=false;
    FILE * p;
    p=fopen(ARCHIVO_PROVEEDORES,"ab");
    if(p!=NULL)
    {
        fwrite(this,sizeof(Proveedor), 1, p);
        guardado=true;
    }
    fclose(p);
    return guardado;
}
int generarID_proveedor()
{
    FILE *p;
    p=fopen(ARCHIVO_PROVEEDORES,"ab");
    fseek(p,0,SEEK_END);
    int id=((ftell(p)/sizeof(Proveedor)))+10;
    fclose(p);
    return id;
}
bool Proveedor::cargar()
{
    setId(generarID_proveedor());
    cout<<"------------------------------------------"<<endl;
    cout<<"     CARGAR PROVEEDOR                    -"<<endl;
    cout<<"------------------------------------------"<<endl;
    cout<<"- ID AUTOGENERADO      : "<<getId() << endl;
    cout<<"- CARGAR CUIT          : ";
    cargarcadena(cuit, 12);
    if(validarCuit(cuit)== false)
    {
        cout<<"------------------------------------------"<<endl;
        cout<<"     ERROR AL CARGAR CUIT!               -"<<endl;
        cout<<"------------------------------------------"<<endl;
        return false;
    }
    if(setCuit(cuit)== false)
        return false;
    cout<<"- CARGAR TELEFONO      : ";
    cargarcadena(telefono, 11);
    if(setTelefono(telefono)== false)
        return false;
    cout<<"- CARGAR RAZON SOCIAL  : ";
    cargarcadena(rsocial, 20);
    strupr(rsocial);
    if(validarRsocial(rsocial)== false)
    {
        cout<<"------------------------------------------"<<endl;
        cout<<"     ERROR AL CARGAR RAZON SOCIAL!       -"<<endl;
        cout<<"------------------------------------------"<<endl;
        return false;
    }
    if(setRsocial(rsocial)== false)
        return false;
    cout<<"- CARGAR MAIL          : ";
    cargarcadena(mail, 30);
    strupr(mail);
    if(setMail(mail)== false)
        return false;
    cout<<"- CARGAR DIRECCION     : ";
    cargarcadena(direccion, 20);
    strupr(direccion);
    if(setDireccion(direccion)== false)
        return false;
    return true;
}
void Proveedor::mostrar(int modo)
{
    if(modo== 1)
    {
        cout<<"------------------------------------------"<<endl;
        cout<<"- ID           : " <<id << endl;
        cout<<"- CUIT         : " << cuit << endl;
        cout<<"- RAZON SOCIAL : " << rsocial << endl;
        cout<<"- MAIL         : " << mail << endl;
        cout<<"- TELEFONO     : " << telefono << endl;
        cout<<"- DIRECCION    : " << direccion << endl;
        cout<<"------------------------------------------"<<endl;
    }
    if(modo== 2)
    {
        cout<<"|"<<setw(10)<<left<<id  <<"|"<<setw(20)<<rsocial       <<"|"<<setw(12)<<cuit  <<"|"<<setw(20)<<direccion  <<"|"<<setw(30)<<mail  <<"|"<<setw(11)<<telefono  <<"|"<<endl;
    }
}
void mostrarxid_Proovedor()
{
    cout<<"------------------------------------------"<<endl;
    cout<<"-         MOSTRAR PROVEEDOR POR ID       -"<<endl;
    cout<<"------------------------------------------"<<endl;
    bool mostrado=false;
    int idaux;
    cout<<"- ID PROVEEDOR QUE DESEA MOSTRAR: ";
    idaux= ingresoEnteroValidado();
    FILE * p;
    Proveedor obj;
    p = fopen(ARCHIVO_PROVEEDORES, "rb");
    if(p== NULL)
    {
        cout<<"------------------------------------------"<<endl;
        cout<<"- NO SE PUDO ABRIR EL ARCHIVO!           -"<< endl;
        cout<<"------------------------------------------"<<endl;
        return;
    }
    while(fread(&obj, sizeof(Proveedor), 1, p)== true)
    {
        if(idaux== obj.getId())
        {
            obj.mostrar(1);
            mostrado=true;
        }
    }
    if(mostrado==false)
    {
        cout<<"------------------------------------------"<<endl;
        cout<<"- ID PROVEEDOR NO ENCONTRADO!            -" << endl;
        cout<<"------------------------------------------"<<endl;
    }
    fclose(p);
}
void modificarProveedor()
{

    bool modificado= false;
    int aux;
    Proveedor obj;
    cout<<"------------------------------------------"<<endl;
    cout<<"-    MODIFICAR PROVEEDOR                 -"<<endl;
    cout<<"------------------------------------------"<<endl;
    cout<<"-    ID PROVEEDOR QUE DESEA MODIFICAR: ";
    aux= ingresoEnteroValidado();
    FILE * p;
    p=fopen(ARCHIVO_PROVEEDORES, "rb+");
    if(p==NULL)
    {
        cout<<"------------------------------------------"<<endl;
        cout<<"- NO SE PUDO ABRIR EL ARCHIVO!           -"<< endl;
        cout<<"------------------------------------------"<<endl;
        return;
    }
    while(fread(&obj, sizeof(Proveedor), 1, p)== true)
    {
        if(aux==obj.getId())
        {
            char cadaux[20];
            cout<<"-    "<<obj.getRsocial()<<endl;
            cout<<"-    MODIFICAR NUEVA DIRECCION: ";
            cargarcadena(cadaux, 20);
            strupr(cadaux);
            if(obj.setDireccion(cadaux)== false)
                return;
            fseek(p, ftell(p)-sizeof(Proveedor), SEEK_SET);
            modificado= fwrite(&obj, sizeof(Proveedor), 1, p);
            cout<<"------------------------------------------"<<endl;
            cout<<"- GUARDADO EXITOSO!                      -"<<endl;
            cout<<"------------------------------------------"<<endl;
            break;
        }
    }
    if(modificado==false)
    {
        cout<<"------------------------------------------"<<endl;
        cout<<"- ERROR AL MODIFICAR ARTICULO!           -"<< endl;
        cout<<"------------------------------------------"<<endl;
    }
    fclose(p);
}
bool Proveedor::leer(int pos)
{
    bool leyo= false;
    FILE * p;
    p=fopen(ARCHIVO_PROVEEDORES, "rb");
    if(p== NULL)
        return false;
    fseek(p, sizeof(Proveedor)*pos, SEEK_SET);
    leyo= fread(this, sizeof(Proveedor), 1, p);
    return leyo;
}
int buscarProveedor(int idP)
{
    Proveedor prov;
    int i=0;
    FILE * p;
    p=fopen(ARCHIVO_PROVEEDORES, "rb");
    if(p==NULL)
        return -2;
    while(fread(&prov, sizeof(Proveedor), 1, p)== true)
    {
        if(prov.getId()== idP)
        {
            fclose(p);
            return i;
        }
        i++;
    }
    fclose(p);
    return -1;
}
