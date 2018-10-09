#include <stdio.h>
#include <stdlib.h>
#define TAM_CLIENTES 20
#define TAM_ALQUILERES 20



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

}eFecha;

typedef struct
{

    int CodigoAlquiler;
    int CodigoJuego;
    int CodigoCliente;
    int isEmpty;
    eFecha fecha;

} eAlquileres;



void inicializarClientes(eClientes lista[], int tam);
void inicializarAlquileres(eAlquileres lista[], int tam);
int buscarLibreCliente(eClientes lista[], int tam);
int buscarLibreAlquileres(eAlquileres lista[], int tam);
int buscarCliente(eClientes lista[], int tam, int codigoCliente);
int buscarAlquiler(eAlquileres lista[], int tam, int codigoAlquiler);
void altaCliente(eClientes lista[], int tam, int pCodigoCliente);
int menuModificar();
void modificarCliente(eClientes lista[], int tam);
void mostrarCliente(eClientes unCliente);
void bajaCliente(eClientes lista[], int tam);
void mostrarClientes(eClientes lista[], int tam);
void cargarJuegos(eJuegos juegos[]);
void cargarCategorias(eCategorias categorias[]);












int main()
{

    char seguir = 's';
    int pCodigoClientes = 1000;
    int pCodigoAlquileres = 1000;

    eClientes clientes[TAM_CLIENTES];
    eAlquileres alquileres[TAM_ALQUILERES];

    inicializarAlquileres(alquileres,TAM_ALQUILERES);
    inicializarClientes(clientes, TAM_CLIENTES);
    eCategorias categorias[5];
    eJuegos juegos[5];

    do
    {
        switch(menu())
        {
        case 1:
            altaCliente(clientes, TAM_CLIENTES, pCodigoClientes);
            system("pause");
            break;
        case 2:
            modificarCliente(clientes, TAM_CLIENTES);
            system("pause");
            break;
        case 3:
            bajaCliente(clientes, TAM_CLIENTES);
            system("pause");
            break;
        case 4:
            listarClientes();
            system("pause");
            break;
        case 5:
            seguir = 'n';
            break;
        }
    }
    while(seguir == 's');





    return 0;
}




void inicializarClientes(eClientes lista[], int tam)
{
    for(int i=0; i < tam; i++)
    {
        lista[i].isEmpty = 1;
    }
}



void inicializarAlquileres(eAlquileres lista[], int tam)
{
    for(int i=0; i < tam; i++)
    {
        lista[i].isEmpty = 1;
    }
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



int buscarLibreAlquileres(eAlquileres lista[], int tam)
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







void altaCliente(eClientes lista[], int tam, int  pCodigoCliente)
{
    int indice;
    int codigoCliente;
    int existe;
    eClientes nuevoCliente;

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
        pCodigoCliente = pCodigoCliente + 1;

        existe = buscarCliente(lista, tam, pCodigoCliente);

        if( existe != -1)
        {

            printf("Ya existe un Cliente con el codigo Cliente %d\n", codigoCliente);
            mostrarCliente(lista[existe]);
            system("pause");

        }
        else
        {

            nuevoCliente.codigoCliente = pCodigoCliente;

            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(nuevoCliente.nombre);
            printf("Ingrese sexo: ");
            fflush(stdin);
            scanf("%c", &nuevoCliente.sexo);
            printf("Ingrese telefono: ");
            fflush(stdin);
            scanf("%d", &nuevoCliente.telefono);

            nuevoCliente.isEmpty = 0;

            lista[indice] = nuevoCliente;


        }
    }

}


void modificarCliente(eClientes lista[], int tam)
{
    int codigoCliente;
    int indice;
    char seguir= 's';


    system("cls");
    printf("  *** Modificar  Cliente ***\n\n");

    printf("Ingrese codigo Cliente: ");
    scanf("%d", &codigoCliente);

    indice = buscarCliente(lista, tam, codigoCliente);

    if( indice == -1)
    {
        printf("No hay ningun Cliente de codigoCliente %d\n\n", codigoCliente);
        system("pause");
    }
    else
    {
        mostrarCliente(lista[indice]);

        /* printf("\nModifica sueldo? s/n: ");
         fflush(stdin);
         scanf("%c", &seguir);

         if(seguir == 'n')
         {
             printf("Modificacion cancelada\n\n");

         }
         else
         {
             printf("Ingrese nuevo sueldo: ");
             scanf("%f", &nuevoSueldo);
             lista[indice].sueldo = nuevoSueldo;

             printf("Modificacion exitosa\n\n");
         }*/


            switch(menuModificar())
            {

                char nuevoNombre[21];
                char nuevoSexo;
                char nuevoTelefono[21];


            case 1:

                printf("\nModifica nombre? s/n: ");
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

                    printf("Modificacion exitosa\n\n");
                    system("pause");
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
                        scanf("%c", &nuevoSexo);
                        strcpy(lista[indice].sexo, nuevoSexo);

                        printf("Modificacion exitosa\n\n");
                        system("pause");
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
                            system("pause");

                            break;
                        case 4:
                            seguir = 'n';
                            break;
                        }



                    system("pause");
                }

            }


}


int menuModificar()
{
    int opcion;

    printf("***Menu modificar***\n\n");

    printf("1- Modificar nombre\n\n");
    printf("2- Modificar Sexo\n\n");
    printf("3- Modificar Telefono\n\n");
    printf("4- Salir\n\n");

    printf("***Elegir opcion***\n\n");

    scanf("%d", &opcion);

    return opcion;
}









void bajaCliente(eClientes lista[], int tam)
{

    int codigoCliente;
    int indice;
    char seguir;

    system("cls");
    printf("  *** Baja empelado ***\n\n");

    printf("Ingrese codigoCliente: ");
    scanf("%d", &codigoCliente);

    indice = buscarCliente(lista, tam, codigoCliente);

    if( indice == -1)
    {
        printf("No hay ningun Cliente con el  codigo Cliente %d\n\n", codigoCliente);
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




void mostrarCliente(eClientes unCliente)
{

    printf("%d   %s    %c    %d\n", unCliente.codigoCliente, unCliente.nombre, unCliente.sexo, unCliente.telefono);
}



void mostrarClientes(eClientes lista[], int tam)
{

    system("cls");
    printf("CodigoCliente    Nombre    Sexo    telefono\n\n");

    for(int i=0; i < tam; i++)
    {

        if( lista[i].isEmpty == 0)
        {
            mostrarCliente(lista[i]);
        }
    }
    system("pause");

}





/*
void cargarJuegos(eJuegos juegos[])
{
    eJuegos jue[]=
    {
        {1, "Ajedrez", 300, 100, 0},
        {2, "Ruleta", 350, 101, 0},
        {3, "Teg", 200, 102, 0},
        {4, "Pool", 600, 103, 0},
        {5, "Mago", 4500, 104, 0}
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
*/
