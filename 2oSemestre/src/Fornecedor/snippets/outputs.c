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

void outAddressInfo() {
	printf("\n\n");
	horizontalLine();
	
	verticalLine(1);
	printf("| Ótimo! Agora são suas informações              |\n", setlocale(LC_ALL,""));
	printf("| de endereço!                                   |\n", setlocale(LC_ALL,""));
	verticalLine(1);
	
	horizontalLine();
	printf("\n\n");
}

void outPreferencesInfo() {
	printf("\n\n");
	horizontalLine();
	
	verticalLine(1);
	printf("| Agora me conte. Quais são suas preferências?   |\n", setlocale(LC_ALL,""));
	verticalLine(1);
	
	horizontalLine();
	printf("\n\n");
}

void optsSegmentChild (const int category) {
	printf("Selecione uma subcategoria de %d: \n", category);
	switch(category) {
		case 1:
			printf("11 - Indústria da Construção Civil\n", setlocale(LC_ALL,""));
			printf("12 - Indústria da Automotiva\n", setlocale(LC_ALL,""));
			printf("13 - Indústria Alimentícia\n", setlocale(LC_ALL,""));
			printf("14 - Automação industrial\n", setlocale(LC_ALL,""));
			printf("15 - Indústria energética\n", setlocale(LC_ALL,""));
			printf("16 - Outro tipo de indústria\n", setlocale(LC_ALL,""));
			break;
		case 2:
			printf("21 - Artigos de casa\n", setlocale(LC_ALL,""));
			printf("22 - Actions figures\n", setlocale(LC_ALL,""));
			printf("23 - Artigos geeks\n", setlocale(LC_ALL,""));
			printf("24 - Material para setup de informática\n", setlocale(LC_ALL,""));
			break;
		case 3:
			printf("31 - Material cirúrgico\n", setlocale(LC_ALL,""));
			printf("32 - Material para consultório\n", setlocale(LC_ALL,""));
			break;
		case 4:
			printf("41 - A combinar com o produtor\n", setlocale(LC_ALL,""));
			break;
	}
}

void success() {
	printf("\n\n");
	horizontalLine();
	
	verticalLine(1);
	printf("| Cadastro realizado com sucesso! Aproveite a    |\n", setlocale(LC_ALL,""));
	printf("| plataforma e boas compras :D                   |\n", setlocale(LC_ALL,""));
	verticalLine(1);
	
	horizontalLine();
	printf("\n\n");
}

