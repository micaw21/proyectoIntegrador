#include <string.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <ctype.h>
#include "colores.h"
#include "juego.h"

//Definicion de Tipos
typedef char tString [50];
//Variables Globales
char harryPotter[22][50] = {"HARRYPOTTER","HERMIONEGRANGER","RONWEASLEY","ALBUSDUMBLEDORE","SEVERUSSNAPE","MINERVAMCGONAGALL","RUBEUSHAGRID","LORDVOLDEMORT","DRACOMALFOY","DOBBY","LUNALOVEGOOD","SIRIUSBLACK","BELLATRIXLESTRANGE","REMUSLUPIN","DOLORESUMBRIDGE","GELLERTGRINDELWALD","NEWTSCAMANDER","HEDWIG","LUCIUSMALFOY","NARCISSAMALFOY","ARGUSFILCH","VERNONDURSLEY"};
char marvel[22][50] = {"CAPITANAMERICA","IRONMAN","HULK","HAWKEYE","BLACKWIDOW","THOR","BRUJAESCARLATA","PANTERANEGRA","SPIDERMAN","LOKI","DOCTORSTRANGE","DEADPOOL","FALCON","STARLORD","GAMORA","GROOT","ROCKET","ANTMAN","WONG","VENOM","WOLVERINE","MAGNETO"};
tString categorias[2] = {"Personaes de Harry Potter","Personajes de Marvel"};


//Prototipo de Funciones
void elegirCategoria();


//Funcion Principal
int main() {
    elegirCategoria();
    return 0;
}

//Implementacion
void elegirCategoria() {
	system("cls");
    int opcion = 0;
    printf(SALMON_T "\n\t *** " LILA_T "THE" MAGENTA_T " HANGMAN" SALMON_T " ***\n");
    printf(RESET_COLOR "CATEGORIAS\n");
    printf(AMARILLOFUERTE_T "1." AMARILLOCLARO_T "Personajes de Harry Potter\n");
    printf(VERDEFUERTE_T "2." VERDE_T "Personajes de Marvel\n");
	printf(AZUL_T"3." CYAN_T"Salir\n");
    printf(RESET_COLOR "Ingrese una opcion > ");
    scanf("%d",&opcion);

	switch(opcion) {
		case 1:
			system("cls");
			empezarJuego(harryPotter,categorias[opcion-1]);
			elegirCategoria();
		break;
		case 2:
			system("cls");
			empezarJuego(marvel,categorias[opcion-1]);
			elegirCategoria();
		break;
		case 3:
			printf("Juego finalizado!");
		break;
		default:
			system("cls");
			printf("Opcion incorrecta!\n");
			elegirCategoria();
		break;
	}
}
