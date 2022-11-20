#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

//imported functions
#include "./snippets/validate.c"
#include "./snippets/outputs.c"

struct client_card {
	//infos pessoais
	char nome[30];
	char email[30];
	char cpf[11];
	char telefone[30];
	char datanascimento[10];
	
	//infos 
	char endereco[50];
	char numero[10];
	char complemento[30];
	char bairro[30];
	char referenciaEndereco[30];
	
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
	
	printf("-- Dados de endereço --", setlocale(LC_ALL,""));
	strcpy(client.endereco, recieveAddress());
	strcpy(client.numero, recieveNumber());
	strcpy(client.complemento, recieveComplement());
	strcpy(client.bairro, recieveDistrict());
	strcpy(client.referenciaEndereco, recieveRef());
	
	system("pause");
	return 0;
	
}
