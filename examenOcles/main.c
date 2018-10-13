#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

#define TAM_CLIENTES 20
#define TAM_ALQUILERES 20







int main()
{
    char seguir = 's';
    char seguimos = 's';
    char elegirMenu = 's';
    char segui = 's';



    eClientes clientes[TAM_CLIENTES];
    eAlquileres alquileres[TAM_ALQUILERES];
    eCategorias categorias[5];
    eJuegos juegos[5];
    cargarCategorias(categorias);
    cargarJuegos(juegos);
    inicializarAlquiler(alquileres,TAM_ALQUILERES);
    inicializarClientes(clientes, TAM_CLIENTES);




    int idCodigoCliente = 1000;
    int idAlquiler = 100;



    do
    {
        switch(menuPrincipal())
        {
        case 1:
            do
            {
                switch(menuClientes())
                {
                case 1:
                    altaCliente(clientes, TAM_CLIENTES, &idCodigoCliente);
                    system("pause");
                    break;
                case 2:
                    modificaCliente(clientes, TAM_CLIENTES);
                    system("pause");
                    break;
                case 3:
                    bajaCliente(clientes, TAM_CLIENTES);
                    system("pause");
                    break;
                case 4:
                    mostrarClientes(clientes, TAM_CLIENTES);
                    system("pause");
                    break;
                case 5:
                    seguir = 'n';
                    break;
                }
            }while(seguir == 's');

            system("pause");
            break;


        case 2:
            do
            {
                switch(menuAlquileres())
                {
                case 1:
                    altaAlquiler(alquileres, TAM_ALQUILERES, juegos, 5, clientes, TAM_CLIENTES, categorias, 5, &idAlquiler);
                    system("pause");
                    break;
                case 2:
                    mostrarAlquileres(alquileres, TAM_ALQUILERES, juegos, 5, clientes, TAM_CLIENTES, categorias,5);
                    system("pause");
                    break;
                case 3:
                    seguimos = 'n';
                    break;
                }
            }
            while(seguimos == 's');

            system("pause");
            break;


        case 3:
                 do
            {
                switch(menuListar())
                {
                case 1:
                    juegosCatMesa(juegos, 5, categorias, 5);
                    system("pause");
                    break;
                case 2:
                    //mostrarAlquileres(alquileres, TAM_ALQUILERES, juegos, 5, clientes, TAM_CLIENTES, categorias,5);
                    system("pause");
                    break;
                case 3:
                    segui = 'n';
                    break;
                }
            }
            while(segui == 's');

            system("pause");
            break;
        case 4:
            printf("Salir");
            system("pause");
            elegirMenu = 'n';
            break;
        }
    }while(elegirMenu == 's');



    return 0;
}







