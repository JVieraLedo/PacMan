#include <stdio.h>
#include <stdlib.h>

#define CLAVE 123

int main(void){

	int codigo_1;

	printf("Escribe la clave para jugar: ");
	scanf("%d", &codigo_1);

	while (codigo_1 != CLAVE){
		printf("Clave incorrecta");

		printf("\nEscribe la clave para jugar: ");
		scanf("%d", &codigo_1);
	}

	printf("La clave es correcta");
	printf("\nPulsa cualquier tecla para empezar a jugar");
	printf("\n");
}
