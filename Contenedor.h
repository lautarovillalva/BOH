#ifndef CONTENEDOR_H_INCLUDED
#define CONTENEDOR_H_INCLUDED

class Contenedor
{
protected:
    int numero;
    char estante;
public:
    bool setNumero(int );
    int getNumero();
    bool setEstante(char );
    char getEstante();

    Contenedor();
    bool cargar();
    void mostrar();
};


#endif // CONTENEDOR_H_INCLUDED
