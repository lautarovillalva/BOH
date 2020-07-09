#ifndef GRILLA_H_INCLUDED
#define GRILLA_H_INCLUDED
#include "Contenedor.h"


const char ARCHIVO_GRILLA[]="grilla.dat";


class Grilla
{
private:
    int idArticulo;
    Contenedor cont;
    bool estado;
public:
    //setters
    bool setIdArticulo(int );
    bool setContenedor(Contenedor );
    void setEstado(bool );
    //getters
    int getIdArticulo();
    Contenedor getContenedor();
    bool getEstado();

    Grilla();
    void nuevo();
    bool cargar();
    bool guardar();
    void mostrar(int );

};
void mostrarGrillaxId();
void desengrillar();

#endif // GRILLA_H_INCLUDED
