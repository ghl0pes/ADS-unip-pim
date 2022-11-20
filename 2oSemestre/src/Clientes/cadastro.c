#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

//imported functions
#include "./snippets/validate.c"
#include "./snippets/outputs.c"

struct client_card {
	char nome[30];
	char email[30];
	char cpf[11];
	char telefone[30];
	char datanascimento[10];
	char endereco[50];
	int tipoPessoa; //1 - Fisica; 2 - Jurídica
};

int main() {
	/*
		----- Cadastro de clientes -----
	*/
	headerRegistration();
	
	struct client_card client;
	
	int opt;
	char stringOpt[30], retornoFuncao[30];
	optRegistration: 
		scanf("%d", &opt);
	
		switch(opt) {
			case 1:	
				strcpy(client.email, recieveEmail());
				break;
			case 2:
				strcpy(client.telefone, recieveCellphone());
				break;
			default:
				printf("Opção selecionada inválida! Digite a opção correta: \n", setlocale(LC_ALL,""));
				goto optRegistration;
		}
	
	outCpfInfo();
	strcpy(client.cpf, validateCpf());
	strcpy(client.datanascimento, recieveBirthDate());
	strcpy(client.endereco, recieveAddress());
	
	
	system("pause");
	return 0;
	
}
