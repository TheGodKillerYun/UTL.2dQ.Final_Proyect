#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>

//Definimos el valor de ganar o empatar para los puntajes
#define GANAR 10
#define EMPATE 5

#define TAM_NOMBRE 50
#define ARCHIVO "puntajes.txt"

//Funciones de impresion
int menuJuego();
void presentacion(char nombre[TAM_NOMBRE],char enemigo[TAM_NOMBRE]);

//Funciones de procesamiento
int maquina();
void jugadorElige(int a);

//Funciones relacionadas con el archivo .txt
void historial();
void guardarPuntaje(char nombre[TAM_NOMBRE], int totalPuntaje);


int menuJuego(int i){
    int jugador;
    printf("== Ronda %d ==\n", i+1);
    i++;
    printf("1. Piedra\n");
    printf("2. Papel\n");
    printf("3. Tijera\n");
    printf("Elija una opción: ");
    scanf("%d", &jugador);

    return jugador;
}

void presentacion(char nombre[TAM_NOMBRE],char enemigo[TAM_NOMBRE]){
    int ganar=GANAR, empate=EMPATE;

    printf("DUELO\n\n%s VS %s\n", nombre, enemigo);

    printf("\nVALORES BASE:\n");
    printf("GANAR - %dpts",ganar);
    printf("\nEMPATAR - %dpts\n\n",empate);

    printf("SERA MEJOR QUE TE PREPARES PARA EL DU DU DU DUELO!\n");
    printf("\nLISTO?\n");
    system("PAUSE");
    system("cls");

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

void guardarPuntaje (char nombre[TAM_NOMBRE], int totalPuntaje){

    FILE *archivo = fopen(ARCHIVO, "a");

        if (archivo == NULL) {
            perror("Error al abrir el archivo");
        }else {
            fprintf(archivo, "Nombre: %s ------ Puntaje: %d\n", nombre, totalPuntaje); // Guardar los datos en el archivo
        }

    fclose(archivo);

}

void historial (){

    FILE *archivo = fopen(ARCHIVO, "r");

        if (archivo == NULL) {
            perror("Error al abrir el archivo");
        }else {
            char caracter;
            while ((caracter = fgetc(archivo)) != EOF) {
                printf("%c", caracter);
            }
        }

    fclose(archivo);

}

int main(){

    //colores
    const char *const titulo="\033[5;40;36m";
    const char *const normal="\033[0m";
    setlocale(LC_ALL,"");

    //definir variables
    char nombre[TAM_NOMBRE],enemigo[TAM_NOMBRE];
    int opcion,gameOver=0,i=0,contEmpate=0;
    /*
    gameOver sirve para detener el bucle que repite el proceso de jugar
    i es el contador de las rondas
    contEmpate cuenta las veces que se han empatado
    */

    //Desplegamos introduccion al programa

    /*FALTA QUE CADA NOMBRE SE ILUMINE DE UN COLOR DIFERENTE*/

    printf("%sPIEDRA, PAPEL O TIJERA%s\n", titulo, normal);
    printf("%sEQUIPO 2%s\n", titulo, normal);
    printf("\n\t%sYun%s\n", titulo, normal);
    printf("\n\t%sSophia%s\n", titulo, normal);
    printf("\n\t%sLeo%s\n", titulo, normal);
    printf("\n\t%sSofia%s\n", titulo, normal);
    printf("\n\t%sAsarel%s\n", titulo, normal);
    printf("\n\t%sDanila%s\n", titulo, normal);
    system("\nPAUSE");
    system("cls");


    do{
        system("cls"); //Se limpia consola

        //MENU PRINCIPAL
        printf("%s--- MENÚ PRINCIPAL ---%s\n", titulo, normal);
        printf("1) Jugar Partida (IA)\n");
        printf("2) Jugar Partida (JcJ)\n");
        printf("3) Ver puntajes\n");
        printf("4) Salir\n");

        printf("Ingresa la opcion: ");
        scanf("%d", &opcion);


        system("cls");
        switch(opcion){
            case 1:// Jugar
                printf("Ingrese su nombre: "); //Pedir nombre del jugador
                scanf("%s", &nombre);

                printf("Ingrese el nombre de su adversario: "); //Pedir nombre del enemigo
                scanf("%s", &enemigo);

                system("cls"); //Limpiamos consola para no saturar de informacion

                presentacion(nombre,enemigo); //Iniicamos la partida para que se puedan cotejar los datos ingresados

                    int totalPuntaje=0, contGanar=0, contEmpate=0; //Declaracion de variables para jugar

                        do{

                            int jugadorOpcion = menuJuego(i); //Muestra el menu para la partida
                            system("cls");

                            int computadora = maquina(); //La maquina elije su opcion en base al numero aleatorio
                            jugadorElige(jugadorOpcion); //Solo imprime la opcion que escogio el jugador


                            //Evaluamos para determinar si el jugador gano la ronda
                            if(jugadorOpcion==computadora){
                                printf("\n¡Empate!\n");
                                contEmpate++;
                            }
                            else if((jugadorOpcion==1 && computadora==3)||(jugadorOpcion==2 && computadora==1)||(jugadorOpcion==3 && computadora==2)){
                                printf("\n¡Ganaste!\n");
                                contGanar++;
                            }
                            else if((jugadorOpcion==1 && computadora==2)||(jugadorOpcion==2 && computadora==3)||(jugadorOpcion==3 && computadora==1)){
                                printf("\n¡Gana %s!\n\tGAME OVER\n", enemigo);
                                gameOver=2;
                            }

                            //En caso de ganar la IA se termina el bucle

                            if(gameOver < 2){
                                totalPuntaje = (contGanar * GANAR) + (contEmpate * EMPATE);
                            }

                            i++;//Aumenta el contador de las rondas
                            /*Dejamos un espacio para que el jugador pueda procesar la informacion y
                            tambien asi no se borra de inmediato el resultado*/
                            printf("Listo para la siguiente ronda?\n");
                            system("PAUSE");
                            system("cls");


                        }while(gameOver !=2);

                    printf("\n  Su puntaje es de: %d\n", totalPuntaje);//Imprimimos el puntaje
                    guardarPuntaje(nombre, totalPuntaje);//Guardamos el puntaje al escribirlo en el documento

                    system("PAUSE");

                    break;

            case 2:

                printf("BIENVENIDO AL MODO JcJ\n");

                    int j=0, totalPp1=0, contGp1=0, totalPp2=0, contGp2=0; //Declaracion de variables para jugar
                    char nombre2[10];

                printf("Ingrese el nombre del P1: "); //Pedir nombre del jugador
                scanf("%s", &nombre);

                printf("\nIngrese el nombre del P2: "); //Pedir nombre del enemigo
                scanf("%s", &nombre2);

                system("cls");//Limpiamos para evitar saturar de informacion

                printf("Ingrese el numero de rondas que desean jugar:\n\t"); //Pide un numero de rondas, es el numero de veces que se va a repetir
                scanf("%d",&j);

                system("cls");

                presentacion(nombre,nombre2);


                        do{

                            printf("Turno del P1\n\t%s\n\n",nombre);//Se especifica a quien corresponde el turno para evitar confusiones
                            int jugador1Opcion = menuJuego(i);//Muestra el menu para que el jugador 1 eliga
                            system("cls"); //Limpia la consola para evitar que el siguiente jugador vea su eleccion

                            printf("Turno del P2\n\t%s\n\n",nombre2);//Se especifica a quien corresponde el turno para evitar confusiones
                            int jugador2Opcion = menuJuego(i); //Muestra el menu para que el jugador 2 eliga
                            system("cls"); //Limpia la consola para evitar que se acumule informacion en la pantalla

                            //Imprimimos la eleccion de cada jugador
                            jugadorElige(jugador1Opcion);
                            jugadorElige(jugador2Opcion);

                            //Evaluamos para determinar quien gana la ronda
                            if(jugador1Opcion==jugador2Opcion){
                                printf("\n¡Empate!\n\n");
                                contEmpate++;
                                gameOver++;
                            }
                            else if((jugador1Opcion==1 && jugador2Opcion==3)||(jugador1Opcion==2 && jugador2Opcion==1)||(jugador1Opcion==3 && jugador2Opcion==2)){
                                printf("\n¡Gana P1!\n\n");
                                contGp1++;
                                gameOver++;
                            }
                            else if((jugador1Opcion==1 && jugador2Opcion==2)||(jugador1Opcion==2 && jugador2Opcion==3)||(jugador1Opcion==3 && jugador2Opcion==1)){
                                printf("\n¡Gana P2!\n\n");
                                contGp2++;
                                gameOver++;
                            } //Evalua quien gana

                            if(gameOver == j){
                                totalPp1 = contGp1 * GANAR;
                                totalPp2 = contGp2 * GANAR;
                            }
                            //Aumentamos el contador de rondas
                            i++;
                            /*Dejamos un espacio para que los jugadores puedan procesar la informacion
                            tambien asi no se borra de inmediato el resultado*/
                            printf("Listos para la siguiente ronda?\n");
                            system("PAUSE");
                            system("cls");


                        }while(gameOver != j);

                    printf("\n  Sus puntajes son:\nP1=%d\nP2=%d\nCon un total de empates:%d", totalPp1,totalPp2,contEmpate);

                    if(totalPp1>totalPp2){

                                printf("GANO EL P2:%s!\n",nombre2);

                            }else{

                                printf("GANO EL P1:%s!\n",nombre);

                            }

                    system("PAUSE");

                break;

            case 3: //puntajes

                historial();
                system("PAUSE");

            break;

            case 4: //salir
                printf("GRACIAS POR JUGAR\n");
                printf("\n\tNOS VEREMOS DEL OTRO LADO...\n\n");
                printf("Saliendo...\n");
            break;

            default:

                printf("Opcion incorrecta\n\tIntentelo de nuevo");
                system("PAUSE");
                system("cls");

                break;


        }
    }while(opcion < 4&&opcion>0);
}
