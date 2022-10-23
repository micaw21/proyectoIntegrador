#include <string.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <ctype.h>
#include "colores.h"
// using namespace std;

//Prototipo de Funciones
void empezarJuego(char [][50], char []);
void dibujo(int);

//Implementacion
void empezarJuego(char pPalabras[][50], char pCategoria[]){
	// char soundfile[] = "C:\\harrypotter.wav";
    // PlaySound((LPCSTR)soundfile,NULL,SND_FILENAME | SND_ASYNC);
    int puntos = 1200;
    int aciertos;
    int intentos = 0;
    int opcion = 0;
    int espacios;
    int longitud = 0;
    char letra;
    int i,j;
    srand(time(NULL));
    opcion = rand() % 23; 
    longitud = strlen(pPalabras[opcion]);
    char palabra[longitud];

    for(i=0;i<longitud;i++){
        palabra[i] = '_';
    }

    do {
        aciertos = 0;
        espacios = 0;
        system("cls");
        printf(LILA_T "\n\t\tCATEGORIA: " AMARILLOFUERTE_T "%s\n",pCategoria);
        printf(RESET_COLOR"\t\tIntentos Disponibles: %d \t\t\t Puntuacion: %d \n\n",6 - intentos, puntos);
        dibujo(intentos);

        for(i=0;i<longitud;i++){
            printf(" %c ",palabra[i]);
        }

        if(intentos == 6){
            printf(SALMON_T "\n\n\t\t\t\tPERDISTE!\n\n");
            printf("LA RESPUESTA ERA: %s\n\n",pPalabras[opcion]);
            system("pause");
            break;
        }

        for(i=0;i<longitud;i++){
            if(palabra[i] == '_'){
                espacios++;
            }
        }

        if(espacios == 0){
            printf(VERDE_T "\n\n\t\t\t\tHAS GANADO!!!\n\n");
            system("pause");
            break;
            
        }

        printf("\n\nIngrese una letra: ");
        fflush(stdin);
        scanf("%c",&letra);
        letra = toupper(letra);

        for(j=0;j<longitud;j++) {
            if(letra == pPalabras[opcion][j]){
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
}


void dibujo(int pIntentos) {
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



