#ifndef ARTICULO_H_INCLUDED
#define ARTICULO_H_INCLUDED
const char ARCHIVO_ARTICULOS[]="articulos.dat";
class Articulo
{
private:
    int id;
    char modelo[20];
    char talle[5];
    char genero[10];
    int cantidad;
    float precio;
public:
    //setters
    bool setId(int );
    bool setModelo(const char * );
    bool setTalle(const char * );
    bool setGenero(const char * );
    bool setCantidad(int );
    bool setPrecio(float );
    //getters
    int getId();
    const char * getModelo();
    const char * getTalle();
    const char * getGenero();
    int getCantidad();
    float getPrecio();
    //constructor
    Articulo();

    void nuevo();
    bool cargar();
    bool guardar();
    void mostrar(int );
};

//funciones
int generarID_articulo();
void modificarArticulo();
void mostrarxid_Articulo();

#endif // ARTICULO_H_INCLUDED
