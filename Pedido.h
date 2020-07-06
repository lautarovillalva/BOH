#ifndef PEDIDO_H_INCLUDED
#define PEDIDO_H_INCLUDED
#include "Fecha.h"

const char ARCHIVO_PEDIDOS []= "pedidos.dat";
class Pedido
{
private:
    int codigo;
    int idArticulo;
    int idProveedor;
    Fecha f_encargo;
    Fecha f_ingreso;
    int cantidad;
    bool estado;
public:
    //setters
bool setCodigo(int );
bool setIDArticulo(int );
bool setIDProveedor(int );
bool setFechaEncargo(Fecha );
bool setFechaIngreso(Fecha );
bool setCantidad(int );
void setEstado(bool );
//getters
int getCodigo();
int getIDArticulo();
int getIDProveedor();
Fecha getFechaEncargo();
Fecha getFechaIngreso();
int getCantidad();
bool getEstado();
//constructor
Pedido();

void nuevo();
bool cargar();
bool guardar();
void mostrar(int );

};
int generarID_pedido();
void mostrarxid_pedido();
void ingresarPedido();

#endif // PEDIDO_H_INCLUDED
