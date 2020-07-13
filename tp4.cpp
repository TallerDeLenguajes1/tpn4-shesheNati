#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct{
    int TareaID;   
    char *Descripcion;
    int Duracion;  
}S_Tarea;


/***********************  PROTOTIPO *****************************/
void AltaDeTareas(S_Tarea **tar, int cantT);
void OrganizandoTareas(S_Tarea **tareasT, S_Tarea **tareasP, S_Tarea **tareasR, int cantT);
void MostrarTareas(S_Tarea **tar,int cantT);
S_Tarea *BuscarTareaXPalabra(S_Tarea **tar,int cantT ,char *palabra);
S_Tarea *BuscarTareaID(S_Tarea **tar,int cantT);



/*********************** PROGRAMA PRINCIPAL ************************/
int main()
{
    int cant_tareas, ID;
    char palabra[30];
    S_Tarea **tareas_realizadas;//arreglos de punteros dobles de tipo estructura S_Tarea
    S_Tarea **tareas_pendientes;
    S_Tarea **tareas_totales;

    printf("Bienvenido al Control de Tareas\n");
    printf("Ingrese la cantidad de tareas a cargar:"); 
    scanf("%d",&cant_tareas);

    tareas_realizadas = (S_Tarea **) malloc(sizeof(S_Tarea *) * cant_tareas); //reserva dinamica de memoria
    tareas_pendientes = (S_Tarea **) malloc(sizeof(S_Tarea *) * cant_tareas);
    tareas_totales = (S_Tarea **) malloc(sizeof(S_Tarea *) * cant_tareas);

    AltaDeTareas(tareas_totales, cant_tareas);
    OrganizandoTareas(tareas_totales, tareas_pendientes, tareas_realizadas, cant_tareas);
    MostrarTareas(tareas_realizadas, cant_tareas);

    S_Tarea *busca_palabra_clave = BuscarTareaXPalabra(tareas_realizadas,cant_tareas,palabra);
    if (busca_palabra_clave == NULL) 
    {
        printf("Sin coincidencias con esa palabra clave en las tareas %s\n", palabra);
    }
    else
    {
        printf("Resultado de la palabra clave: ID: %d Duracion: %d\n",busca_palabra_clave->TareaID, busca_palabra_clave->Duracion);
    }


    S_Tarea *buscar_tarea = BuscarTareaID(tareas_realizadas,cant_tareas);
    if(buscar_tarea == NULL)
    {
        printf("No se encontro ninguna tarea con ese ID: %d\n",ID);
    }
    else
    {
        printf("La tarea con ID %d es: %s\n",ID,buscar_tarea->Descripcion);
    }


    scanf(" %c");
    return 0;
}


/******************* FUNCIONES *****************/

void AltaDeTareas(S_Tarea **tar, int cantT)
{
    char descripcion[99];
    
    for(int i = 0; i < cantT; i++)
    {
        tar[i] = (S_Tarea*)malloc(sizeof(tar));
        tar[i]->TareaID = i;

        printf("Ingrese la descripcion de la tarea ID %d:", i);
        scanf("%s", descripcion); 
        tar[i]->Descripcion = (char *)malloc(sizeof(char) * strlen(descripcion) + 1);//reserva dinamica necesaria para strcpy
        strcpy(tar[i]->Descripcion, descripcion);
        
        tar[i]->Duracion = rand() % 91 + 10;

    }
}

void OrganizandoTareas(S_Tarea **tareasT, S_Tarea **tareasP, S_Tarea **tareasR, int cantT)
{
    char aux[3];
    for( int i = 0; i < cantT; i++)
    {
        printf(" ¿Tarea ID %d realizada? \n Ingrese la descripcion de la tarea: %s\n SI / NO: ", i, tareasT[i]->Descripcion);
        scanf("%s", aux);

        if(strcmp(aux,"si") == 0 || strcmp(aux, "SI") == 0 || strcmp(aux, "Si") == 0 ) //si el resultado es 0 son iguales
        {
            tareasR[i] = (S_Tarea*)malloc(sizeof(S_Tarea));
            tareasP[i] = (S_Tarea *)malloc(sizeof(S_Tarea));

            tareasR[i] = tareasT[i];
            tareasP[i] = NULL;
        }
        else
        {
            tareasR[i] = NULL;
            tareasP[i] = tareasT[i];
            
        }
    
    }

}

void MostrarTareas(S_Tarea **tar,int cantT)
{
    for(int i = 0; i < cantT; i++)
    {
        if(tar[i] != NULL)
        {
            printf("\nID de tarea: %d\n",tar[i]->TareaID);
            printf("Descripcion: %s\n",tar[i]->Descripcion);
            printf("Duracion: %d\n",tar[i]->Duracion);
            printf("________________________________\n");
        }
    }
}

S_Tarea *BuscarTareaXPalabra(S_Tarea **tar,int cantT ,char *palabra)
{
    printf("Ingrese la palabra clave de la tarea que desea buscar:\n");
    scanf("%s ",palabra);

    for (int i = 0; i < cantT; i++)
    {
        if (tar[i] != NULL)
        {
            if (strcmp(tar[i]->Descripcion,palabra) == 0)
            {
                return tar[i];
            }
        } 
    }
    return NULL;
}

S_Tarea *BuscarTareaID(S_Tarea **tar,int cantT)
{
    int aux_id;

    printf("Ingrese id de la tarea a buscar\n");
    scanf("%d",&aux_id);
    for (int i = 0; i < cantT; i++)
    {
        if (tar[i] != NULL) 
        {
            if (tar[i]->TareaID == aux_id)
            {
                return tar[i];
            }
        }
    }
    return NULL;
}

