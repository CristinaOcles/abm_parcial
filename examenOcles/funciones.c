#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"


int menuPrincipal()
{
    int seleccion;

    printf("\n 1 - menu clientes\n");
    printf("\n 2 - dar de alta alquiler\n");
    printf("\n 3 - listar\n");
    printf("\n 4 - salir\n");
    printf("\n elegir opcion: (1/2/3/4)\n");
    scanf("%d", &seleccion);

    while(seleccion<1 || seleccion>3)
    {
        printf("\n 1 - menu clientes\n");
        printf("\n 2 - dar de alta alquiler\n");
        printf("\n 3 - listar\n");
        printf("\n 4 - salir\n");
        printf("\n elegir opcion: (1/2/3/4)\n");
        scanf("%d", &seleccion);
    }

    return seleccion;
}

int menuClientes()
{

    int opcion;

    printf("\n***Menu Clientes***\n\n");

    printf("1- Alta CLiente \n");
    printf("2- Modificar Cliente\n");
    printf("3- Baja cliente\n");
    printf("4- Listar\n");
    printf("5- Salir\n");

    printf("***Elegir opcion***\n\n");

    scanf("%d", &opcion);

    return opcion;
}

int menuAlquileres()
{

    int opcion;

    system("cls");
    printf("\n*** Menu de alquileres ***\n\n");
    printf(" 1- Alta\n");
    printf(" 2- Listar alquileres\n");
    printf(" 3- Salir\n\n");
    printf(" Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

void inicializarClientes(eClientes lista[], int tam)
{

    for(int i=0; i < tam; i++)
    {

        lista[i].isEmpty = 1;
    }
}


void mostrarCliente(eClientes unCliente)
{

    printf("%6d %10s %8c %17s\n", unCliente.codigoCliente, unCliente.nombre, unCliente.sexo, unCliente.telefono);
}



void mostrarClientes(eClientes lista[], int tam)
{

    system("cls");
    printf("Codigo      nombre      sexo      telefono\n\n");

    for(int i=0; i < tam; i++)
    {

        if( lista[i].isEmpty == 0)
        {
            mostrarCliente(lista[i]);
        }
    }
    system("pause");
}




int buscarLibreCliente(eClientes lista[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {

        if( lista[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}


int buscarCliente(eClientes lista[], int tam, int codigoCliente)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {

        if( lista[i].codigoCliente == codigoCliente && lista[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;

}




void altaCliente(eClientes lista[], int tam, int* pCodigoCliente)
{
    int indice;
    int codigoCliente;
    int existe;
    eClientes nuevoCliente;

    codigoCliente = *pCodigoCliente;
    indice = buscarLibreCliente(lista, tam);

    system("cls");
    printf("*** Alta Cliente ***\n\n");

    if( indice == -1)
    {

        printf("No hay lugar en el sistema\n\n");
        system("pause");
    }
    else
    {

        existe = buscarCliente(lista, tam, codigoCliente);

        if( existe != -1)
        {

            printf("Ya existe un Cliente con el codigo de Cliente %d\n", codigoCliente);
            mostrarCliente(lista[existe]);
            system("pause");

        }
        else
        {

            nuevoCliente.codigoCliente = codigoCliente;

            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(nuevoCliente.nombre);
            printf("Ingrese sexo: ");
            fflush(stdin);
            scanf("%c", &nuevoCliente.sexo);
            printf("Ingrese telefono: ");
            fflush(stdin);
            gets(nuevoCliente.telefono);

            nuevoCliente.isEmpty = 0;

            lista[indice] = nuevoCliente;

            printf("Alta exitosa!: ");

            *pCodigoCliente = codigoCliente + 1;

        }
    }

}






void bajaCliente(eClientes lista[], int tam)
{

    int codigoCliente;
    int indice;
    char seguir;

    system("cls");
    printf("  *** Baja empelado ***\n\n");

    printf("Ingrese codigo de Cliente: ");
    scanf("%d", &codigoCliente);

    indice = buscarCliente(lista, tam, codigoCliente);

    if( indice == -1)
    {
        printf("No hay ningun Cliente con ese codigo de Cliente %d\n\n", codigoCliente);
        system("pause");
    }
    else
    {
        mostrarCliente(lista[indice]);

        printf("\nConfima borrado s/n: ");
        fflush(stdin);
        scanf("%c", &seguir);

        if(seguir == 'n')
        {
            printf("Baja cancelada\n\n");

        }
        else
        {

            lista[indice].isEmpty = 1;
            printf("Borrado exitoso\n\n");
        }
        system("pause");
    }

}





void modificaCliente(eClientes lista[], int tam)
{
    int codigoCliente;
    int indice;


    system("cls");
    printf("  *** Modificar  Cliente ***\n\n");

    printf("Ingrese codigo de Cliente: ");
    scanf("%d", &codigoCliente);

    indice = buscarCliente(lista, tam, codigoCliente);

    if( indice == -1)
    {
        printf("No hay ningun cliente con el codigo de Cliente %d\n\n", codigoCliente);
        system("pause");
    }
    else
    {
        mostrarCliente(lista[indice]);
        modificar(lista, tam, indice);

    }

}







void modificar(eClientes lista[], int tam, int indice)
{
    char seguimos = 's';
    char seguir = 's';
    int opcion;
    char nuevoNombre[21];
    char nuevoSexo;
    char nuevoTelefono[21];


    printf("\n\n***Menu Clientes***\n\n");

    printf("1- modificar nombre \n");
    printf("2- Modificar sexo\n");
    printf("3- modificar telefono\n");
    printf("4- Salir\n\n");

    printf("***Elegir opcion***\n");

    scanf("%d", &opcion);

    while(opcion<1 || opcion>4)
    {
        printf("***Opcion incorrecta, vuelva a elegir***\n\n");

        printf("1- modificar nombre \n");
        printf("2- Modificar sexo\n");
        printf("3- modificar telefono\n");
        printf("4- Salir\n\n");

        printf("***Elegir opcion***\n");

        scanf("%d", &opcion);

    }


    switch(opcion)
    {

    case 1:

        printf("\nModifica nombre? s/n: \n");
        fflush(stdin);
        scanf("%c", &seguir);

        if(seguir == 'n')
        {
            printf("Modificacion cancelada\n\n");

        }
        else
        {
            printf("Ingrese nuevo nombre: ");
            fflush(stdin);
            scanf("%s", nuevoNombre);
            strcpy(lista[indice].nombre, nuevoNombre);
            printf("Modificacion exitosa!\n\n");

        }

        break;

    case 2:

        printf("\nModifica sexo? s/n: ");
        fflush(stdin);
        scanf("%c", &seguir);

        if(seguir == 'n')
        {
            printf("Modificacion cancelada\n\n");

        }
        else
        {
            printf("Ingrese nuevo sexo: ");
            fflush(stdin);
            scanf("%c", &nuevoSexo);
            lista[indice].sexo = nuevoSexo;

            printf("Modificacion exitosa\n\n");
        }

        break;

    case 3:

        printf("\nModifica telefono? s/n: ");
        fflush(stdin);
        scanf("%c", &seguir);

        if(seguir == 'n')
        {
            printf("Modificacion cancelada\n\n");

        }
        else
        {
            printf("Ingrese nuevo telefono: ");
            scanf("%s", nuevoTelefono);
            strcpy(lista[indice].telefono, nuevoTelefono);

            printf("Modificacion exitosa\n\n");
        }

        break;
    case 4:
        seguimos = 'n';
        break;

    }
    system("pause");

}



void cargarJuegos(eJuegos juegos[])
{
    eJuegos jue[]=
    {
        {1, "Ajedrez", 300, 100, 0},
        {2, "Ruleta", 350, 101,0},
        {3, "Teg", 200, 100,0},
        {4, "Pool", 600, 103,0},
        {5, "Mago", 4500, 104,0}
    };
    for(int i=0; i < 5; i++)
    {
        juegos[i] = jue[i];
    }
}
void cargarCategorias(eCategorias categorias[])
{
    eCategorias cate[]=
    {
        {100, "mesa"},
        {101, "azar"},
        {102, "estrategia"},
        {103, "salon"},
        {104, "magia"}
    };
    for(int i=0; i < 5; i++)
    {
        categorias[i] = cate[i];
    }
}


































void inicializarAlquiler(eAlquileres lista[], int tam)
{

    for(int i=0; i < tam; i++)
    {

        lista[i].isEmpty = 1;
    }
}


int buscarAlquiler(eAlquileres lista[], int tam, int codigoAlquiler)
{
    int indice = -1;
    for(int i=0; i < tam; i++)
    {
        if(lista[i].isEmpty == 0 && lista[i].CodigoAlquiler == codigoAlquiler)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarLibreAlquiler(eAlquileres lista[], int tam)
{
    int indice = -1;
    for(int i=0; i < tam; i++)
    {
        if(lista[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}


void altaAlquiler(eAlquileres alquiler[], int tamAl, eJuegos juegos[], int tamj, eClientes clientes[], int tamCl, eCategorias categorias[], int tamcat, int* pId)
{
    int idAlquiler = *pId;
    int idCategoria;
    int idJuego;
    int idCliente;
    eFecha fecha;
    eAlquileres nuevoAlquiler;
    int indice;

    indice = buscarLibreAlquiler(alquiler, tamAl);

    if(indice == -1)
    {
        printf("No se pueden cargar mas alquileres\n\n");
    }
    else
    {
        nuevoAlquiler.CodigoAlquiler = idAlquiler;

        mostrarClientes(clientes, tamCl);

        printf("Ingrese codigo de clientes: ");
        while(scanf("%d", &idCliente) !=1)
        {
            printf(" reingrese  un numero: ");
            scanf("%d", &idCliente);
            fflush(stdin);
        }

        nuevoAlquiler.CodigoCliente = idCliente;

        listarJuegos(juegos, tamj, categorias, tamcat);

        printf("Ingrese juego: ");
        scanf("%d", &idJuego);

        nuevoAlquiler.CodigoJuego = idJuego;

        printf("\nIngrese dia: ");
        while(scanf("%d", &fecha.dia) !=1)
        {
            printf(" reingrese  un numero: ");
            scanf("%d", &fecha.dia);
            fflush(stdin);
        }

        printf("Ingrese mes: ");
        while(scanf("%d", &fecha.mes) !=1)
        {
            printf(" reingrese  un numero: ");
            scanf("%d", &fecha.mes);
            fflush(stdin);
        }


        printf("Ingrese anio: ");
        while(scanf("%d", &fecha.anio) !=1)
        {
            printf(" reingrese  un numero: ");
            scanf("%d", &fecha.anio);
            fflush(stdin);
        }

        for(int i=0; i<tamcat; i++)
        {
            if(categorias[i].id == idJuego)
            {
                idCategoria = categorias[i].id;

            }
        }
        //listarCategorias(categorias, tamcat);

        nuevoAlquiler.CodigoJuego = idCategoria;


        nuevoAlquiler.fecha = fecha;

        *pId = idAlquiler +1;

        nuevoAlquiler.isEmpty = 0;

        alquiler[indice] = nuevoAlquiler;

    }
}



void obtenerDescAlquiler(eJuegos juego[], int tamj, int codigoJuego, char cadena[])
{
    for(int i=0; i < tamj; i++)
    {
        if( juego[i].codigoJuego == codigoJuego)
        {
            strcpy(cadena, juego[i].descripcion);
        }
    }
}


void mostrarAlquiler(eAlquileres unAlquiler, eJuegos juegos[], int tamJue, eClientes clientes[], int tamCli, eCategorias categorias[], int tamCat)
{
    char descAlquiler[20];
    char descCat[20];
    int indice;
    eClientes cliente;

    obtenerDescAlquiler(juegos, tamJue, unAlquiler.CodigoJuego, descAlquiler);
    obtenerCategoria(categorias,tamCat,unAlquiler.CodigoJuego,descCat);
    indice = buscarCliente(clientes, tamCli, unAlquiler.CodigoCliente);

    cliente = clientes[indice];

    printf("%4d %02d/%02d/%d     %d        %2s    %10d      %10s     %10s\n", unAlquiler.CodigoAlquiler, unAlquiler.fecha.dia, unAlquiler.fecha.mes, unAlquiler.fecha.anio, cliente.codigoCliente, cliente.nombre, unAlquiler.CodigoJuego, descCat);

}






void mostrarJuegos(eJuegos lista[], int tamJ, eCategorias categorias[], int tamC)
{

    system("cls");
    printf("Legajo    Nombre      importe      categoria\n\n");

    for(int i=0; i < tamJ; i++)
    {

        if( lista[i].isEmpty == 0)
        {
            mostrarJuego(lista[i], categorias, tamC);
        }
    }

    printf("\n\n");


}

void mostrarJuego(eJuegos unJuego, eCategorias categorias[], int tam)
{
    char desCat[20];

    obtenerCategoria(categorias, tam, unJuego.codigoJuego, desCat);

    printf("%4d %10s  %6.2f %10s\n", unJuego.codigoJuego, unJuego.descripcion,unJuego.importe, desCat);
}






void listarJuegos(eJuegos juegos[], int tam, eCategorias categorias[], int tamCat)
{


    printf("\nLista de juegos\n\n");
    printf("\ncodigo idCategoria     descripcion    precio\n\n");
    for(int i=0; i < tam; i++)
    {
        for(int j=0; j<tamCat+1; j++)
        {

                if(juegos[i].idCategoria == categorias[j].id)
                {
                    printf(" %d  %10s %20s   %d  \n",juegos[i].codigoJuego, categorias[j].descripcion, juegos[i].descripcion, juegos[i].importe);
                }


        }

    }
    printf("\n\n");
}



void mostrarAlquileres(eAlquileres alquileres[], int tamAl, eJuegos juegos[], int tamJue, eClientes clientes[], int tamClien, eCategorias categorias[], int tamC)
{
    int flag = 0;

    system("cls");
    printf("********** Alquileres***********\n\n");
    printf("id   fecha   codigo   cliente    Nombre    juegos     categoria\n\n");

    for(int i=0; i < tamAl; i++)
    {
        if( alquileres[i].isEmpty == 0)
        {
            mostrarAlquiler(alquileres[i], juegos, tamJue, clientes, tamClien,categorias,tamC);
            flag = 1;
        }
    }

    if(flag == 0)
    {
        printf("No hay alquileres cargados\n\n");
    }
    printf("\n\n");
    system("pause");
}







void obtenerCategoria(eCategorias categorias[], int tam, int idCategoria, char descripcion[])
{


    for(int i=0; i < tam; i++)
    {

        if( categorias[i].id == idCategoria)
        {
            strcpy(descripcion, categorias[i].descripcion);
        }
    }

}




void listarCategorias(eCategorias categorias[], int tam)
{

    printf("Id  Descripcion\n\n");
    for(int i=0; i< tam; i++)
    {
        printf("%d   %10s\n", categorias[i].id, categorias[i].descripcion);

    }
    printf("\n\n");
}




void listarJuegosXcategorias(eJuegos juegos[],int tamJ, eCategorias categorias[], int tamC)
{
    int idCategoria;
    char descripcion[20];
    int flag = 0;

    system("cls");
    printf("  *** Lista de categorias ***\n\n");

    listarCategorias(categorias, tamC);
    printf("Ingrese categoria: ");
    scanf("%d",&idCategoria);

    obtenerCategoria(categorias, tamC, idCategoria, descripcion);

    system("cls");
    printf("juegos de categorias %s\n\n", descripcion);
    for(int i=0; i< tamC; i++)
    {
        if(juegos[i].isEmpty == 0 && juegos[i].codigoJuego == idCategoria)
        {
            mostrarJuego(juegos[i],categorias, tamC);
            flag = 1;
        }
    }

    printf("\n\n");

    if(flag == 0)
    {
        printf("No hay juegos que mostrar\n\n");
    }

}


int menuListar()
{

    int opcion;

    system("cls");
    printf("\n*** Menu Listar ***\n\n");
    printf(" 1- Mostrar juegos categoria mesa\n");
    printf(" 2- ****\n");
    printf(" 3- Salir\n\n");
    printf(" Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}







void juegosCatMesa(eJuegos juegos[], int tamJue, eCategorias categorias[], int tamCat)
{
    int catMesa = 100;
    system("cls");
    printf("*********Juegos de mesa*************\n\n");

    for(int i=0; i<tamJue; i++)
    {
        if(juegos[i].idCategoria == catMesa)
        {
            printf("%s\n", juegos[i].descripcion);
        }

    }
        printf("\n\n");
        listarCategorias(categorias, tamCat);
        listarJuegos(juegos, tamJue, categorias, tamCat);
}


