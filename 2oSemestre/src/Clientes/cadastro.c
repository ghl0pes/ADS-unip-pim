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
	char sexo;
	char telefone[30];
	char datanascimento[10];
	
	//infos de endereço
	char endereco[50];
	char numero[10];
	char complemento[30];
	char bairro[30];
	char referenciaEndereco[30];
	
	//infos de interesse do cliente
	int categorias[10]; 
	int categoriasFilhas[30];
};

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
	
	system("pause");
	return 0;
	
}
