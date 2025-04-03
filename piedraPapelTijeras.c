#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include "colors.h"

void menu();
int jugar(char *nombre);
void historial();
void limpiar_Y_Pausar_Pantalla();
void guardarHistorial();

void menu(){
    printf("\n======Menu de Actividades=====\n");
    printf("\t 1.Jugar\n");
    printf("\t 2.Mostrar historial \n");
    printf("\t 3.Salir\n");
}

int jugar (char *nombre){
    char *opciones[3]={"Piedra","Papel","Tijera"};
    int jugador, computadora;
    srand(time(NULL));//generador de numeros aleatorios
    computadora=srand()%3;

    printf("\nEscoge tu destino: \n\t 0.Piedra || 1.Papel || 2.Tijera \n");
    scanf("%d",&jugador);

    printf("\n %s eligió: % \n",*nombre,*opciones[jugador]);
    printf(" La computadora eligió: %s \n",*opciones[computadora]);

    if (jugador==computadora){
        printf("\nEs un Empate!\n");
    } else if((jugador==0 && computadora==2) || (jugador==1 && computadora==0) || (jugador==2 && computadora==1)){
        printf("\nGanaste!\n");
    }else{
        printf("\nPerdiste!\n");
    }
}

void limpiar_Y_Pausar_Pantalla(){
    system("cls");
    system("pause");
}

//
int main() {
setlocale(LC_ALL, "");

    int eleccion;
    char nombre[50];
    char *opciones[3]={"Piedra","Papel","Tijera"};

    srand(time(NULL));//generador de numeros aleatorios

    printf("\n Ingesa tu nombre: \n");
    scanf("%s",&nombre);

    do{
    limpiar_Y_Pausar_Pantalla();

    menu();
    printf("\n ¿Qué desas hacer? \n");
    scanf("%i",&eleccion);

    switch(eleccion){

    case 1:
        limpiar_Y_Pausar_Pantalla();

        printf("\nEs hora de-de-de del DUELO!!!\n");
        jugar(nombre);

        limpiar_Y_Pausar_Pantalla();
        break;
    case 2:

        break;
    case 3:

        break;
    }
}while(eleccion!=3);

    return 0;
}
