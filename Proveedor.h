#ifndef PROVEEDOR_H_INCLUDED
#define PROVEEDOR_H_INCLUDED

const char ARCHIVO_PROVEEDORES[]= "proveedores.dat";

class Proveedor
{
private:
    int id;
    char cuit[12];
    char telefono[11];
    char rsocial[20];
    char direccion[20];
    char mail[30];
public:
    //setters
    bool setId(int );
    bool setCuit(const char * );
    bool setTelefono(const char * );
    bool setRsocial(const char * );
    bool setMail(const char * );
    bool setDireccion(const char * );
    //getters
    int getId();
    const char * getCuit();
    const char * getTelefono();
    const char * getRsocial();
    const char * getDireccion();
    const char * getMail();
    //constructor
    Proveedor();

    bool leer(int );
    void nuevo();
    bool cargar();
    bool guardar();
    void mostrar(int );
};

int generarID_proveedor();
void modificarProveedor();
void mostrarxid_Proovedor();
int buscarProveedor(int );



#endif // PROVEEDOR_H_INCLUDED
