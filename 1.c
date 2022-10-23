#include <string.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <ctype.h>
#include "colores.h"

//Variables Globales
char HarryPotter[22][50] = {"HARRYPOTTER","HERMIONEGRANGER","RONWEASLEY","ALBUSDUMBLEDORE","SEVERUSSNAPE","MINERVAMCGONAGALL","RUBEUSHAGRID","LORDVOLDEMORT","DRACOMALFOY","DOBBY","LUNALOVEGOOD","SIRIUSBLACK","BELLATRIXLESTRANGE","REMUSLUPIN","DOLORESUMBRIDGE","GELLERTGRINDELWALD","NEWTSCAMANDER","HEDWIG","LUCIUSMALFOY","NARCISSAMALFOY","ARGUSFILCH","VERNONDURSLEY"};
char Marvel[25][50] = {"CAPITANAMERICA","IRONMAN","HULK","HAWKEYE","BLACKWIDOW","THOR","BRUJAESCARLATA","PANTERANEGRA","SPIDERMAN","LOKI","DOCTORSTRANGE","DEADPOOL","FALCON","STARLORD","GAMORA","GROOT","ROCKET","ANTMAN","WONG","VENOM","YELENABELOVA","SHANGCHI","WOLVERINE","PROFESORX","MAGNETO"};


//Prototipo de Funciones
void elegirCategoria();
void empezarJuego(int);
void dibujo(int);


//Funcion Principal
int main() {
    elegirCategoria();
    return 0;
}

//Implementacion
void elegirCategoria() {
    //system("cls");
    int opcion = 0;
    printf(SALMON_T "\n\t *** " LILA_T "THE" MAGENTA_T " HANGMAN" SALMON_T " ***\n");
    printf(RESET_COLOR "CATEGORIAS\n");
    printf(AMARILLOFUERTE_T "1." AMARILLOCLARO_T "Personajes de Harry Potter\n");
    printf(VERDEFUERTE_T "2." VERDE_T "Personajes de Marvel\n");
    printf(RESET_COLOR "Ingrese una opcion > ");
    scanf("%d",&opcion);

    if(opcion > 3){
        system("cls");
        printf(MARRON_T "Opcion Incorrecta!\n" RESET_COLOR);
        elegirCategoria();
    } else {
        system("cls");
        empezarJuego(opcion);
    }
}

void empezarJuego(int pCategoria){
    int puntos = 1200;
    int aciertos;
    int intentos = 0;
    int opcion = 0;
    int espacios;
    int longitud = 0;
    char letra;
    int i,j;
    srand(time(NULL));

    if(pCategoria == 1) {
        opcion = rand() % 23; 
        longitud = strlen(HarryPotter[opcion]);
        char palabra[longitud];

        for(i=0;i<longitud;i++){
            palabra[i] = '_';
        }

        do {
            aciertos = 0;
            espacios = 0;
            system("cls");
            printf(LILA_T "\n\t\tCATEGORIA: " AMARILLOFUERTE_T "PERSONAJES DE HARRY POTTER\n" RESET_COLOR);
            printf("\t\tIntentos Disponibles: %d \t\t\t Puntuacion: %d \n\n",6 - intentos, puntos);
            dibujo(intentos);

            for(i=0;i<longitud;i++){
                printf(" %c ",palabra[i]);
            }

            if(intentos == 6){
                printf(SALMON_T "\n\n\t\t\t\tPERDISTE!\n\n");
                printf("LA RESPUESTA ERA: %s\n\n",HarryPotter[opcion]);
                elegirCategoria();
            }

            for(i=0;i<longitud;i++){
                if(palabra[i] == '_'){
                    espacios++;
                }
            }

            if(espacios == 0){
                printf(VERDE_T "\n\n\t\t\t\tHAS GANADO!!!\n\n");
                elegirCategoria();
            }

            printf("\n\nIngrese una letra: ");
            fflush(stdin);
            scanf("%c",&letra);
            letra = toupper(letra);

            for(j=0;j<longitud;j++) {
                if(letra == HarryPotter[opcion][j]){
                    palabra[j] = letra;
                    aciertos++;
                } 
            }

            if(aciertos == 0){
                intentos++;
                puntos -= 200;
            }

        } while (intentos != 7);
        
        printf("\n\n");

    } else {

        opcion = rand() % 26;
        longitud = strlen(Marvel[opcion]);
        char palabra[longitud];

        for(i=0;i<longitud;i++){
            palabra[i] = '_';
        }

        do {
            aciertos = 0;
            espacios = 0;
            system("cls");
            printf(LILA_T "\n\t\tCATEGORIA: " AMARILLOFUERTE_T "PERSONAJES DE MARVEL\n" RESET_COLOR);
            printf("\t\tIntentos Disponibles: %d \t\t\t Puntuacion: %d \n\n",6 - intentos, puntos);
            dibujo(intentos);
            for(i=0;i<longitud;i++){
                printf(" %c ",palabra[i]);
            }

            if(intentos == 6){
                printf(SALMON_T "\n\n\t\t\t\tPERDISTE!\n\n");
                printf("LA RESPUESTA ERA: %s\n\n",Marvel[opcion]);
                elegirCategoria();
            }

            for(i=0;i<longitud;i++){
                if(palabra[i] == '_'){
                    espacios++;
                }
            }

            if(espacios == 0){
                printf(VERDE_T "\n\n\t\t\t\tHAS GANADO!!!\n\n");
                elegirCategoria();
            }

            printf("\n\nIngrese una letra: ");
            fflush(stdin);
            scanf("%c",&letra);
            letra = toupper(letra);

            for(i=0;i<longitud;i++) {
                if(letra == Marvel[opcion][i]){
                    palabra[i] = letra;
                    aciertos++;
                } 
            }

            if(aciertos == 0){
                intentos++;
                puntos -= 200;
            }

        } while (intentos != 7);
        printf("\n\n");
    }

}

void dibujo (int pIntentos){
	switch(pIntentos){
		case 0:
			printf("\n     _______\n    |       |\n    |\n    |\n    |\n    |\n    |\n ----------");
        break;

		case 1:
			printf("\n     _______\n    |       |\n    |       0\n    |\n    |\n    |\n    |\n ----------");
        break;

		case 2:
			printf("\n     _______\n    |       |\n    |       0\n    |       |\n    |\n    |\n    |\n ----------");
        break;

		case 3:
			printf("\n     _______\n    |       |\n    |       0\n    |      /|\n    |\n    |\n    |\n ----------");
        break;

		case 4:
			printf("\n     _______\n    |       |\n    |       0\n    |      /|");
			printf("\\");
			printf("\n");
			printf("    |\n    |\n    |\n ----------");
        break;

		case 5:
			printf("\n     _______\n    |       |\n    |       0\n    |      /|");
			printf("\\");
			printf("\n");
			printf("    |      /\n    |\n    |\n ----------");
        break;

		case 6:
			printf("\n     _______\n    |       |\n    |       0\n    |      /|");
			printf("\\");
			printf("\n");
			printf("    |      / ");
			printf("\\");
			printf("\n");
			printf("    |\n    |\n ----------");
        break;
	}
}


