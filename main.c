#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define MAX 10
#define TAM_NOMBRE 50
#define ARCHIVO "empleados.txt"

void guardarEmpleados(char empleados[][TAM_NOMBRE],int totalEmpleados);
int cargarEmpleados(char empleados[][TAM_NOMBRE],int max);

void guardarEmpleados(char empleados[][TAM_NOMBRE],int totalEmpleados){
    FILE *archivo=fopen(ARCHIVO,"w");
    if (archivo==NULL){
        printf("\nNo se pudo abrir el archivo %s para escritura.\n",ARCHIVO);
    }else{
        for (int i=0;i<totalEmpleados;i++){
            fprintf(archivo,"%s\n",empleados[i]); //fprintf imprime el contenido del archivo y requiere tres parametros
            //destino, formato, origen
        }
    }
    fclose(archivo);
}

int cargarEmpleados(char empleados[][TAM_NOMBRE],int max){
     FILE *archivo=fopen(ARCHIVO,"r");
    if (archivo==NULL){
        printf("\nNo se pudo abrir el archivo %s para lectura.\n",ARCHIVO);
        return 0;
    }
    int count=0;
    //Leer linea por linea hasta alcanzar el maximo o el final del archivo
    while(count<max && fgets(empleados[count],TAM_NOMBRE,archivo) != NULL){
        //Eliminar el salto de linea que incluye fgets si esta presente
        empleados[count][strcspn(empleados[count],"\n")] = '\0';
        count++;
    }
    fclose(archivo);
return count;
}

int main (){
setlocale(LC_ALL,"");

    char empleados[MAX][TAM_NOMBRE];
    int totalEmpleados=0;
    int opcion;
    char nombre[TAM_NOMBRE];

    //cargar los empleados desde el archivo al iniciar el programa
    totalEmpleados=cargarEmpleados(empleados,MAX);


    do{
    printf("\n-- MENU EMPLEADOS --\n");

    printf("\n\t 1.Alta de Empleado. \n");
    printf("\t 2.Baja de Empleado. \n");
    printf("\t 3.Listar Empleado. \n");
    printf("\t 4.Salir \n");

    printf("\nIngresa la opcion: ");
    scanf("%i",&opcion);

    getchar();//Limpiar el buffer

    switch(opcion){
    case 1:     //alta
        if (totalEmpleados < MAX) {
            printf("\nIngrese el nombre del empleado: ");

            fgets(nombre, TAM_NOMBRE, stdin); // Usar fgets para leer el nombre completo incluyendo espacios
            nombre[strcspn(nombre, "\n")] = '\0'; // Eliminar el salto de línea

            strcpy(empleados[totalEmpleados], nombre); // Copiar el nombre al arreglo
            totalEmpleados++; // Incrementar el contador de empleados

            printf("\nEmpleado agregado exitosamente.\n");
        } else {
            printf("\nNo se pueden agregar más empleados. Límite alcanzado.\n");
        }
        break;

    case 2:     //baja de empleados
        if(totalEmpleados>0){
            printf("\nIngrese el nombre del empleado a dar de baja: ");
            fgets(nombre,TAM_NOMBRE,stdin);
            nombre[strcspn(nombre, "\n")]='\0';
            int encontrando=0;
            //Buscar al empleado en el arreglo
            for(int i=0;i<totalEmpleados;i++){
                if(strcmp(empleados[i],nombre)==0){
                    //mover los empleados siguientes una posicion hacia atras para cubrir el espacio
                    for(int j=i;j<totalEmpleados-1;j++){
                        strcpy(empleados[j],empleados[j+1]);
                    }
                    empleados[totalEmpleados-1][0]='\0';//limpiar el ultimo elemento
                    totalEmpleados--;
                    printf("\nEmpleado dado de baja exitosamente.\n");
                    encontrando=1;
                    break;
                }
            }
            if(!encontrando){
                printf("\n Empleado no encontrado. \n");
            }
        }else{
            printf("\n No hay empleados registrados para dar de baja. \n");
        }
        break;

    case 3:     //listar
        if(totalEmpleados>0){
            printf("\n--Lista de Empleados--\n");
            for(int i=0;i<totalEmpleados;i++){
                printf("%d. %s\n",i+1,empleados[i]);
                }
            }else{
                printf("\n No hay empleados registrados \n");
            }
        break;

    case 4:     //salir
        guardarEmpleados(empleados,totalEmpleados);
        printf("\nGuardando y saliendo... \n");
        break;

    default:
        printf("\nOpcion no valida.\n");
        }
    }while (opcion!=4);

return 0;
}
