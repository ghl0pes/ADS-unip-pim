#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <conio.h>

//imported functions
#include "./snippets/validate.c"
#include "./snippets/outputs.c"

typedef struct client_card {
	//infos pessoais
	char nome[30];
	char email[30];
	char cpf[11];
	char sexo;
	char telefone[30];
	char datanascimento[10];
	
	//infos de endereço
	char endereco[50];
	char numero[10];
	char complemento[30];
	char bairro[30];
	char referenciaEndereco[30];
	
	//categorias de interesse do cliente
	int categorias[10]; 
	int categoriasFilhas[30];
};

int outCheckoutClient(struct client_card cliente) {
	horizontalLine();
	
	printf("Confira seus dados para confirmar o cadastro na plataforma.\n\n", setlocale(LC_ALL,""));
	
	horizontalLine();
	printf("--- Dados Pessoais ---\n");
	printf("| Nome: %s\n", cliente.nome);
	printf("| Email: %s\n", cliente.email);
	printf("| CPF: %s\n", cliente.cpf);
	printf("| Sexo: %c\n", cliente.sexo);
	printf("| Telefone: %s\n", cliente.telefone);
	printf("| Data de nascimento: %s\n\n", cliente.datanascimento);
	
	horizontalLine();
	printf("--- Dados de endereço ---\n");
	printf("| Endereço: %s\n", cliente.endereco);
	printf("| Número: %s\n", cliente.numero);
	printf("| Complemento: %s\n", cliente.complemento);
	printf("| Bairro: %s\n", cliente.bairro);
	printf("| Referência do endereço: %s\n\n", cliente.referenciaEndereco);
	
	horizontalLine();
	printf("--- Categorias de interesse ---\n");
	int i, j;
	for(i = 0; i < sizeof(cliente.categorias); i++) {
		printf("| -%s\n", cliente.categorias[i]); 
		for(j = 0; j < sizeof(cliente.categoriasFilhas); j++) {
			if((cliente.categorias[i] == 1 && (cliente.categoriasFilhas[j] > 10 || cliente.categoriasFilhas[j] <= 16)) ||
				(cliente.categorias[i] == 2 && (cliente.categoriasFilhas[j] > 20 || cliente.categoriasFilhas[j] <= 24)) ||
				(cliente.categorias[i] == 3 && (cliente.categoriasFilhas[j] > 30 || cliente.categoriasFilhas[j] <= 32)) ||
				(cliente.categorias[i] == 4 && (cliente.categoriasFilhas[j] > 40 || cliente.categoriasFilhas[j] <= 41)))
				printf("| --%s\n", cliente.categoriasFilhas[j]); 				
		}
	}
	printf("\n\n");
	horizontalLine();
	
	int check; 
	printf("Deseja confirmar o cadastro? 1 - Sim / 0 - Não", setlocale(LC_ALL,""));
	scanf("%d", &check);
	
	return check;
}

int main() {
	struct client_card client;
	
	headerRegistration();	
		
	int opt;
	char verificationCode[10];
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
	strcpy(client.sexo, recieveClientSex());
	strcpy(client.datanascimento, recieveBirthDate());
	
	outAddressInfo();
	strcpy(client.endereco, recieveAddress());
	strcpy(client.numero, recieveNumber());
	strcpy(client.complemento, recieveComplement());
	strcpy(client.bairro, recieveDistrict());
	strcpy(client.referenciaEndereco, recieveRef());
	
	outPreferencesInfo();
	int categories[10];
	int optionSegment, i = 0, j = 0;
	
	chooseCategory:
	do {
		printf("Qual tipo de produto é de seu interesse?\n1 - Prototipação para indústria\n2 - Decoração\n3 - Área médica\n4 - Artigos personalizados\n5 - Outros\n0 - Não desejo cadastrar isso agora\n\n", setlocale(LC_ALL,""));
		scanf("%d", &client.categorias[i]);
		
		if(client.categorias[i] < 0 || client.categorias[i] > 5) {
			printf("Categoria inválida!. Preencha novamente, por favor!\n\n", setlocale(LC_ALL,""));
			goto chooseCategory;
		} else if (client.categorias[i] == 0) {
			break;
		}
		
		int optSub;
		chooseSubCategory:
		do {
			optSub = 0;
			optsSegmentChild(client.categorias[i]);
			scanf("%d", &client.categoriasFilhas[j]);
			
			if (
				(client.categorias[i] == 1 && (client.categoriasFilhas[j] <= 10 || client.categoriasFilhas[j] > 16)) ||
				(client.categorias[i] == 2 && (client.categoriasFilhas[j] <= 20 || client.categoriasFilhas[j] > 24)) ||
				(client.categorias[i] == 3 && (client.categoriasFilhas[j] <= 30 || client.categoriasFilhas[j] > 32)) ||
				(client.categorias[i] == 4 && (client.categoriasFilhas[j] <= 40 || client.categoriasFilhas[j] > 41))
			) {
				printf("Subcategoria inválida. Preencha novamente, por favor!\n\n");
				goto chooseSubCategory;
			}
			
			printf("Deseja cadastrar mais alguma subcategoria? 1 - Sim / 0 - Não\n", setlocale(LC_ALL,""));
			scanf("%d", &optSub);
			
			j++;
		} while (optSub == 1);
		
		
		printf("\n-Deseja cadastrar mais uma categoria? 1 - Sim /0 - Não\n", setlocale(LC_ALL,""));
		scanf("%d", &optionSegment);
		i++;
	} while (optionSegment == 1);
	
	int checkout;
	checkout = outCheckoutClient(client);
	
	if(checkout == 0)
		clrscr();
		goto optRegistration;
	
	system("pause");
	return 0;
	
}
