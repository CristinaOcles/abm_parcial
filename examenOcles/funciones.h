#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
    int codigoJuego;
    char descripcion[51];
    int importe;
    int idCategoria;
    int isEmpty;

} eJuegos;

typedef struct
{
    int id;
    char descripcion[51];

} eCategorias;


typedef struct
{

    int codigoCliente;
    char nombre[51];
    char sexo;
    char telefono[21];
    int isEmpty;

} eClientes;

typedef struct
{

    int dia;
    int mes;
    int anio;

} eFecha;


typedef struct
{

    int CodigoAlquiler;
    int CodigoJuego;
    int CodigoCliente;
    int isEmpty;
    eFecha fecha;

} eAlquileres;





int menuPrincipal();
int menuClientes();
int menuAlquileres();
void inicializarClientes(eClientes lista[], int tam);
void mostrarCliente(eClientes unCliente);
void mostrarClientes(eClientes lista[], int tam);
int buscarLibreCliente(eClientes lista[], int tam);
int buscarCliente(eClientes lista[], int tam, int codigoCliente);
void altaCliente(eClientes lista[], int tam, int* pCodigoCliente);
void bajaCliente(eClientes lista[], int tam);
void modificaCliente(eClientes lista[], int tam);
void modificar(eClientes lista[], int tam, int indice);
void cargarJuegos(eJuegos juegos[]);
void cargarCategorias(eCategorias categorias[]);
void inicializarAlquiler(eAlquileres lista[], int tam);
int buscarAlquiler(eAlquileres lista[], int tam, int codigoAlquiler);
int buscarLibreAlquiler(eAlquileres lista[], int tam);
void altaAlquiler(eAlquileres alquiler[], int tamAl, eJuegos juegos[], int tamj, eClientes clientes[], int tamCl, eCategorias categorias[], int tamcat, int* pId);
void obtenerDescAlquiler(eJuegos juego[], int tamj, int codigoJuego, char cadena[]);
void mostrarAlquiler(eAlquileres unAlquiler, eJuegos juegos[], int tamJue, eClientes clientes[], int tamCli, eCategorias categorias[], int tamCat);
void mostrarJuegos(eJuegos lista[], int tamJ, eCategorias categorias[], int tamC);
void mostrarJuego(eJuegos unJuego, eCategorias categorias[], int tam);
void listarJuegos(eJuegos juegos[], int tam, eCategorias categorias[], int tamCat);
void mostrarAlquileres(eAlquileres alquileres[], int tamAl, eJuegos juegos[], int tamJue, eClientes clientes[], int tamClien, eCategorias categorias[], int tamC);
void obtenerCategoria(eCategorias categorias[], int tam, int idCategoria, char descripcion[]);
void listarCategorias(eCategorias categorias[], int tam);
void listarJuegosXcategorias(eJuegos juegos[],int tamJ, eCategorias categorias[], int tamC);
void juegosCatMesa(eJuegos juegos[], int tamJue, eCategorias categorias[], int tamCat);
int menuListar();
