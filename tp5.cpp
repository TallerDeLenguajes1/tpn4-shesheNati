#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct
{
    int TareaID;   
    char *Descripcion;
    int Duracion;  
}S_Tarea;

struct Nodo
{
    S_Tarea T;
    struct Nodo *siguiente;
};
typedef struct Nodo S_Nodo;


/***********************  PROTOTIPO *****************************/
S_Nodo *CrearListaVacia();
S_Nodo *CrearNodo(int id);
void AgregarTareas(S_Nodo **start, S_Nodo *tar);
void MostrarTareas(S_Nodo **start,S_Nodo *tareasR);
S_nodo *EliminarNodo(S_Nodo **start,int id);
void BuscaTPendientes(S_Nodo *start);
void BuscaTRealizadas(S_Nodo *tareasR);


/*********** PROGRAMA PRINCIPAL ***************/
int main()
{
    srand (time(NULL));

    int valor,id;
    S_Nodo *nueva_tarea;
    S_Nodo *tareas_pendientes = CrearListaVacia();
    S_Nodo *tareas_realizadas = CrearListaVacia();


    do{
		printf("1 )Ingrese la tarea a agregar\n");
        printf("2)Mostrar Tareas Realizadas y Pendientes\n");
		printf("3)Marcar las tareas realizadas\n");
        printf("4)Busqueda por ID tareas pendientes:\n");
        printf("5)Busqueda por ID tareas realizadas:\n");
		printf("6)Salir\n");
        printf("Opcion: ");
		scanf("%d", &valor);

        switch(valor) 
        {
            case 1:
             {
                id = id +1;
                nueva_tarea = CrearNodo(id);
                AgregarTareas(&tareas_pendientes,nueva_tarea);
                printf("\n");
                break;
            }
            case 2: 
            {
                MostrarTareas(tareas_pendientes,tareas_realizadas);
                break;
            }
            case 3: {
                char respuesta[3];
                S_Nodo *auxiliar = tareas_pendientes;

                while(auxiliar! = NULL){
                    printf("\n Tarea completa ID: %d?\n Descripcion de tarea: %s\n SI/NO: ",aux->T.TareaID,aux->T.Descripcion);
                    scanf("%s",respuesta);

                    if(strcmp(respuesta,"SI") == 0 || strcmp(respuesta,"si") == 0 || strcmp(respuesta,"Si") == 0){
                        S_Nodo* NodoAux;
                        int IDaux = auxiliar->T.TareaID;
                        auxiliar = auxiliar->siguiente;
                        NodoAux = EliminarNodo(&tareas_pendientes,IDaux); 
                        AgregarTareas(&tareas_realizadas,NodoAux);
                    }else
                    {
                        auxiliar = auxiliar->siguiente;
                    }  
                }
                break;
            }
            case 4:
            {
                BuscaTPendientes(tareas_pendientes);
                break;
            }
            case 5:
            {
                BuscaTRealizadas(tareas_realizadas);
                break;
            }
        }
    }while(valor != 6);

    scanf(" %c");
    return 0;
}


/************** FUNCIONES ***********************/

S_Nnodo * CrearListaVacia()
{
    return NULL;
}

S_Nodo *CrearNodo(int id)
{
    char descripcion[100];
    S_Nodo *aux = (S_Nodo*) malloc(sizeof(S_Nodo));

    aux->T.TareaID = id;
    aux->T.Duracion = rand() % 91+10;

    printf("Descripcion de la tarea ID %d: ",id);
    scanf("%s",descripcion);
    aux->T.Descripcion = (char*) malloc(strlen(descripcion)+1 * sizeof(char));
    strcpy(aux->T.Descripcion,descripcion);

    aux-> siguiente = NULL;

    return aux;
}


void AgregarTareas(S_Nodo **start,S_Nodo *tar)
{ 
    tar->siguiente = *start;
    *start = tar;
}

void MostrarTareas(S_Nodo **start,S_Nodo *tareasR)
{
    printf("\nTareas pendientes:\n");
    while(start != NULL)
    {
        printf("\nID de tarea: %d\n",start->T.TareaID);
        printf("Descripcion: %s\n",start->T.Descripcion);
        printf("Duracion: %d\n",start->T.Duracion);
        printf("--------------------------------------\n");
        start = start->siguiente;
    }

    printf("\nTareas realizadas:\n");
     while(tareasR != NULL){
        printf("\nID de tarea: %d\n",realizadas->T.TareaID);
        printf("Descripcion: %s\n",realizadas->T.Descripcion);
        printf("Duracion: %d\n",realizadas->T.Duracion);
        printf("--------------------------------------\n");
        tareasR = tareasR->siguiente;
    }
    printf("\n\n");
}

S_nodo *EliminarNodo(S_Nodo **start,int id)
{
   if(*start != NULL)
   {
       S_Nodo *aux = *start;
       S_Nodo *temp;
        if(aux->T.TareaID == id)
        { 
            *start = (*start)->siguiente;
            return aux;
        }else
        {
            while((aux->siguiente)->T.TareaID != id)
            { 
                aux = aux->siguiente;
            }
            temp = aux->siguiente; 
            aux->siguiente = (aux->siguiente)->siguiente; 
            return temp;
        }

   }
}

void BuscaTPendientes(S_Nodo *start)
{
    int IDaBuscar;
    S_Nodo *NodoEncontrado = NULL;
    printf("Ingrese el ID de la tarea a buscar: ");
    scanf("%d",&IDaBuscar);

    while(start != NULL)
    {
        if(start->T.TareaID == IDaBuscar){
            NodoEncontrado = start;
            printf("\n\n----------------------------------");
            printf("\n Tarea encontrada\nID: %d\nDescripcion: %s\nDuracion: %d\n",NodoEncontrado->T.TareaID,NodoEncontrado->T.Descripcion,NodoEncontrado->T.Duracion);
            printf("----------------------------------\n\n");
            break;
        }else
        {
           start = start->siguiente;
        }    
    }
    if(NodoEncontrado == NULL)
    {
        printf("\n-----\n No se pudo encontrar ninguna tarea!\n-----\n");
    }
}

void BuscaTRealizadas(S_Nodo *tareasR)
{
    int IDaBuscar;
    S_nodo *NodoEncontrado = NULL;
    printf("Ingrese el ID de la tarea a buscar: ");
    scanf("%d",&IDaBuscar);

    while(tareasR != NULL)
    {
        if(tareasR->T.TareaID == IDaBuscar)
        {
            NodoEncontrado = realizadas;
            printf("\n\n----------------------------------");
            printf("\nSe encontro una tarea\nID: %d\nDescripcion: %s\nDuracion: %d\n",NodoEncontrado->T.TareaID,NodoEncontrado->T.Descripcion,NodoEncontrado->T.Duracion);
            printf("\n\n----------------------------------\n\n");
            break;
        }else
        {
           tareasR = tareasR->siguiente;
        }
        
    }
    if(NodoEncontrado == NULL)
    {
        printf("\n-----\n No se pudo encontrar ninguna tarea!\n-----\n");
    }
}