#include <stdio.h>
#include <stdlib.h>
#define CLAVE 123

int main(void){
	char primero[20], segundo[20];
	int fila,columna,opcion,codigo_1,array_bi[8];
	printf("Escribe el Nombre del jugador 1: ");
	scanf("%s", primero);
	printf("\nEscribe el Nombre del Jugador 2: ");
	scanf("%s", segundo);
	system("cls");
	printf("%s te toca colocar los barcos", primero);
	getch();
	system("cls");
	printf("Las variables tienen que estar entre el 0 y el 7");
	printf("\nEscribe la variable fila: ");
	scanf("%d", &fila);
	printf("\nEscribe la variable columna: ");
	scanf("%d", &columna);
	array_bi[fila][columna] = 1;
	printf("Hay un barco en la posicion %d, %d", fila,columna);
	getch();
	system("cls");
principio:
	printf("\nOPCIONES\n");
	printf("-------------------------\n");
	printf("\n1 Colocar mas barcos\n");
	printf("2 Disparar\n");
	printf("0 Salir\n");
	printf("Escriba el numero de la opcion que quiera(0-2): ");
	scanf("%d", &opcion);
	switch (opcion)
	{
		case 1:
			system("cls");
			printf("Las variables tienen que estar entre el 0 y el 7");
			printf("\nEscribe la variable fila: ");
			scanf("%d", &fila);
			printf("\nEscribe la variable columna: ");
			scanf("%d", &columna);
			array_bi[fila][columna] = 1;
			printf("Hay un barco en la posicion %d, %d", fila,columna);
			getch();
			system("cls");
			goto principio;
			break;

		case 0:
			system("cls");
			system("exit");
			break;
		default:
			system("cls");
			printf("Esa no es una opcion");
			getch();
			system("cls");
			goto principio;


		case 2:
			system("cls");
			printf("%s te toca disparar", segundo);
			getch();
			system("cls");
			printf("Recuerda que las variables tienen que estar entre el 0 y el 7");
			printf("\nEscribe la variable fila: ");
			scanf("%d", &fila);
			printf("\nEscribe la variable columna: ");
			scanf("%d", &columna);
			if (array_bi[fila][columna] == 1){
				printf("El valor es %s", array_bi[fila][columna]);
				printf("TOCADO Y HUNDIDO");
				getch();
				array_bi[fila][columna]=0;
				goto principio;
			}else{
				printf("AGUA");
				goto principio;
			}
	}
}
