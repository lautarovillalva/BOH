#include <iostream>
using namespace std;
#include "cstdio"
#include "cstdlib"
#include "cstring"
#include "Proveedor.h"
#include "Articulo.h"

int ingresoEnteroValidado()
{
    int op;
    while(!(cin>>op))
    {
        cout<<"------------------------------------------"<<endl;
        cout<<"- ERROR, SE ESPERA UN VALOR NUMERICO: ";
        cin.clear();
        cin.ignore(123,'\n');
    }
    return op;
}
float ingresoFlotanteValidado()
{
    float op;
    while(!(cin>>op))
    {
        cout<<"------------------------------------------"<<endl;
        cout<<"- ERROR, SE ESPERA UN VALOR NUMERICO: ";
        cin.clear();
        cin.ignore(123,'\n');
    }
    return op;
}
void cargarcadena(char * cad, int tam)
{
    int i;
    fflush(stdin);
    for(i=0; i<tam; i++)
    {
        cad[i]=cin.get();
        if(cad[i]=='\n')
            break;
    }
    cad[i]='\0';
    fflush(stdin);
}
bool validarModelo(char * modelo)
{
    bool val = true;
    if(strcmp(modelo,"\0")==0 || strcmp(modelo," ")==0)
    {
        val=false;
        return val;
    }
    FILE * p;
    Articulo art;
    p= fopen(ARCHIVO_ARTICULOS, "rb");
    if(p!=NULL)
    {
        while(fread(&art, sizeof(Articulo), 1, p)==1)
        {
            if(strcmp(modelo, art.getModelo())==0)
            {
                val=false;
                fclose(p);
                return val;
            }
        }
    }
    fclose(p);
    return val;
}
bool validarRsocial(char * rsocial)
{
        bool val = true;
    if(strcmp(rsocial,"\0")==0 || strcmp(rsocial," ")==0)
    {
        val=false;
        return val;
    }
    FILE * p;
    Proveedor prov;
    p= fopen(ARCHIVO_PROVEEDORES, "rb");
    if(p!=NULL)
    {
        while(fread(&prov, sizeof(Proveedor), 1, p)==1)
        {
            if(strcmp(rsocial, prov.getRsocial())==0)
            {
                val=false;
                fclose(p);
                return val;
            }
        }
    }
    fclose(p);
    return val;
}
bool validarCuit(char * cuit)
{

        bool val = true;
    if(strcmp(cuit,"\0")==0 || strcmp(cuit," ")==0)
    {
        val=false;
        return val;
    }
    FILE * p;
    Proveedor prov;
    p= fopen(ARCHIVO_PROVEEDORES, "rb");
    if(p!=NULL)
    {
        while(fread(&prov, sizeof(Proveedor), 1, p)==1)
        {
            if(strcmp(cuit, prov.getCuit())==0)
            {
                val=false;
                fclose(p);
                return val;
            }
        }
    }
    fclose(p);
    return val;

}
