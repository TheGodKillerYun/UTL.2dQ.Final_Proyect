#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>

#define TAM_NOMBRE 50
#define ARCHIVO "puntajes.txt"

int menuJuego();
int maquina();
void jugadorElige(int a);
void juego(int a, int b, char nombre);


int menuJuego(){
    int jugador;
    printf("1. Piedra\n");
    printf("2. Papel\n");
    printf("3. Tijera\n");
    printf("Elija una opción: ");
    scanf("%d", &jugador);

    return jugador;
}

int maquina(){
    srand(time(NULL));
     int random_number = rand() % 3 + 1;

    switch(random_number){
    case 1:
        printf("Consola: piedra\n");
    break;
    case 2:
        printf("Consola: papel\n");
    break;
    case 3:
        printf("Consola: tijera\n");
    break;
}
    return random_number;
}

void jugadorElige(int a){
    switch(a){
    case 1:
        printf("\tVS \nJugador: piedra\n" );
    break;
    case 2:
        printf("\tVS \nJugador: papel\n");
    break;
    case 3:
        printf("\tVS \nJugador: tijera\n" );
    break;
    }
}

void juego(int a, int b, char nombre){

    if(a==b){
        printf("\n¡Empate!\n");
    }else if((a==1 && b==2)||(a==2 && b==3)||(a==3 && b==1)){
        printf("\n¡Gana Consola!\n\tGAME OVER\n");
    }else if((a==1 && b==3)||(a==2 && b==1)||(a==3 && b==2)){
        printf("\n¡Ganaste!\n");
    }
}



int main(){

    //colores
    const char *const titulo="\033[5;40;36m";
    const char *const normal="\033[0m";
    setlocale(LC_ALL,"");

    //definir variables
    char nombre[TAM_NOMBRE];
    int opcion, salir;

    //pantalla principal
    printf("%sPIEDRA, PAPEL O TIJERA%s\n", titulo, normal);
    system("\nPAUSE");



    //MENU PRINCIPAL
    system("cls");
    printf("%s--- MENÚ PRINCIPAL ---%s\n", titulo, normal);
    printf("1) Jugar Partida\n");
    printf("2) Ver puntajes\n");
    printf("3) Salir\n");
    printf("Ingresa la opcion: ");
    scanf("%d", &opcion);
    getchar(); //la verdad no me acuerdo pa que era

//Temporalmente es un do while
do{
    system("cls");
    switch(opcion){
    case 1:// Jugar
        printf("Ingrese su nombre: "); //Pedir nombre del jugador
        scanf("%s", &nombre);

        int jugadorOpcion = menuJuego(); //Muestra el menu para la partida
        system("cls");
        int computadora = maquina(); //La maquina elije su opcion en base al numero aleatorio
        jugadorElige(jugadorOpcion); //Solo imprime la opcion que escogio el jugador
        juego(jugadorOpcion, computadora, nombre[TAM_NOMBRE]); //Evalua quien gana

        //menu de opciones para jugar
    break;
    case 2: //puntajes

    break;
    case 3: //salir

        printf("Saliendo...\n");
    break;


    }
    system("PAUSE");
    system("cls");
    printf("\nQuiere seguir jugando?\n1.Si\n2.No \n :");
    scanf("%d", &salir);
    }while(salir == 1);
}
