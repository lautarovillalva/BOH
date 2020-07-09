#include <iostream>
using namespace std;
#include "cstdio"
#include "cstdlib"
#include "cstring"

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
