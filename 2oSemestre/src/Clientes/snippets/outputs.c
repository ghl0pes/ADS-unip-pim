#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void verticalLine(linesQuantity) {
	int i;
	for (i = 0; i < linesQuantity; i++) {
		printf("|                                                |\n");
	}
}

void horizontalLine()  {
	printf("--------------------------------------------------\n");
}

void headerRegistration () {
	horizontalLine();
	
	verticalLine(1);
	printf("| Bem vindo ao sistema de cadastro de usuários!  |\n", setlocale(LC_ALL,""));
	verticalLine(2);
	printf("| Falta pouco para ter acesso ao mundo da        |\n");
	printf("| prototipação 3D!                               |\n", setlocale(LC_ALL,""));
	verticalLine(2);
	printf("| Como deseja continuar?                         |\n", setlocale(LC_ALL,""));
	printf("| 1 - Email				         |\n", setlocale(LC_ALL,""));
	printf("| 2 - Celular		                         |\n", setlocale(LC_ALL,""));
	verticalLine(1);
	
	horizontalLine();
}

void outCpfInfo() {
	printf("\n\n");
	horizontalLine();
	
	verticalLine(1);
	printf("| Certo! Agora vamos receber suas                |\n", setlocale(LC_ALL,""));
	printf("| informações pessoais!                          |\n", setlocale(LC_ALL,""));
	verticalLine(1);
	
	horizontalLine();
	printf("\n\n");
}
