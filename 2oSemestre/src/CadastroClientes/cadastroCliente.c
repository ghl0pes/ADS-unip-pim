#include <stdio.h>
#include <string.h>
#include <locale.h>
#include "./externalFunctions/extras.c"
	
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

int main() {
	/*
		----- Cadastro de clientes -----
	*/
	headerRegistration();
	
	int opt;
	char stringOpt[30], confirmationOpt[30];
	optRegistration: 
		scanf("%d", &opt);
	
	switch(opt) {
		case 1: 
			optEmail:
				printf("Informe seu e-mail para continuar: ");
				scanf("%s", stringOpt);
				printf("Por favor, digite-o novamente: ");
				scanf("%s", confirmationOpt);
				if (strcmp() != 0) {
					printf("Endereços de e-mail não conferem. Preencha novamente, por favor!\n");
					goto optEmail;
				}
				if (validEmail(stringOpt) == 0)
					goto optEmail;
			break;
		case 2:
			validCellphone();
			break;
		default:
			printf("Opção selecionada inválida! Digite a opção correta: \n", setlocale(LC_ALL,""));
			goto optRegistration;
	}
	
}
