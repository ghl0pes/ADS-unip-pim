#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <conio.h>

//imported functions
#include "./snippets/outputs.c"
#include "./snippets/middlewares/validDate.c"

typedef struct {
	//infos pessoais
	char nome[30];
	char email[30];
	char cpf[15];
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
} client_card;

int outCheckoutClient(client_card cliente) {
	system("cls");
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
	printf("| Endereço: %s", cliente.endereco);
	printf("| Número: %s", cliente.numero);
	printf("| Complemento: %s", cliente.complemento);
	printf("| Bairro: %s", cliente.bairro);
	printf("| Referência do endereço: %s\n\n", cliente.referenciaEndereco);
	
	horizontalLine();
	printf("--- Categorias de interesse ---\n");
	int i = 0;
	while(cliente.categorias[i] != 0 ){
		if(cliente.categorias[i] < 10) {
			printf("| -%d\n", cliente.categorias[i]); 
			int j = 0;
			while(cliente.categoriasFilhas[j] != 0) {
				switch(cliente.categorias[i]) {
					case 1:
						if(cliente.categoriasFilhas[j] > 10 && cliente.categoriasFilhas[j] <= 16)
							printf("| --%d\n", cliente.categoriasFilhas[j]); 
						break;
					case 2:
						if(cliente.categoriasFilhas[j] > 20 && cliente.categoriasFilhas[j] <= 24)
							printf("| --%d\n", cliente.categoriasFilhas[j]); 
						break;
					case 3:
						if(cliente.categoriasFilhas[j] > 30 && cliente.categoriasFilhas[j] <= 32)
							printf("| --%d\n", cliente.categoriasFilhas[j]); 
						break;
					case 4:
						if(cliente.categoriasFilhas[j] > 40 && cliente.categoriasFilhas[j] <= 41)
							printf("| --%d\n", cliente.categoriasFilhas[j]); 
						break;
				}
				j++;			
			}
			i++;
		}		
	}
	printf("\n");
	horizontalLine();
	
	int check; 
	printf("Deseja confirmar o cadastro? 1 - Sim / 0 - Não\n", setlocale(LC_ALL,""));
	scanf("%d", &check);
	
	return check;
}

int main() {
	client_card client;
	
	headerRegistration();	
		
	int opt;
	char verificationCode[10];
	char email[30], confirmationEmail[30], phone[30], validChars[15] = "01234567890+-()", confirmationCode[4];
	int i, j, invalidChars = 0;
	
	optRegistration:
		scanf("%d", &opt);
	
		switch(opt) {
			case 1:	
				// -------------- EMAIL --------------
				recieveEmail:
				printf("Informe seu e-mail para continuar: ");
				scanf("%s", email);
				
				if(strlen(email) == 0) {
					printf("\n -- Endereço de email inválido. Preencha novamente, por favor! --\n\n", setlocale(LC_ALL,""));
					goto recieveEmail;
				}
					
				printf("Por favor, confirme o email: ");
				scanf("%s", confirmationEmail);
				
				if (strcmp(email, confirmationEmail) != 0) {
					printf("\n -- Endereços de e-mail não conferem. Preencha novamente, por favor! --\n\n", setlocale(LC_ALL,""));
					goto recieveEmail;
				}	
				
				int i, countAt = 0, countDot = 0;
				for (i = 0; i < strlen(email); i++) {
					if((email[i] == '@'))
						countAt++;
					if((email[i] == '.'))
						countDot++;
				}
				
				if((countAt != 1) || (countDot != 1)) {
					printf("\n -- Endereço de e-mail inválido. Preencha novamente, por favor! --\n\n", setlocale(LC_ALL,""));
					goto recieveEmail;
				}
				
				confirmCode:
					printf("Enviamos um código de confirmação /(1234)/ para o seu email, digite para continuar: ", setlocale(LC_ALL,""));
					scanf("%s", confirmationCode);
					
					if(strcmp(confirmationCode, "1234") != 0) {
						printf("\n -- Códido de confirmação inválido. Preencha novamente, por favor! --\n\n", setlocale(LC_ALL,""));
						goto confirmCode;
					}
					
				strcpy(client.email, email);				
			break;
			
			case 2:
				// -------------- CELULAR --------------
				recieveCellphone:
				printf("Informe seu celular para continuar: ");
				scanf("%s", phone);
				
				for(i = 0; i < strlen(phone); i++) {
					int valid = 0;
					for(j = 0; j < strlen(validChars); j++) 
						if(validChars[j] == phone[i]) valid++;	
						
					if(valid == 0) invalidChars++;
				}
				
				if(invalidChars > 0) {
					printf("-- O telefone possui caracteres inválidos. Preencha novamente, por favor! --\n\n", setlocale(LC_ALL,""));
					goto recieveCellphone;
				}
				
				confirmCode:
					printf("Enviamos um código de confirmação /(1234)/ por SMS, digite para continuar: ", setlocale(LC_ALL,""));
					scanf("%s", confirmationCode);
					
					if(strcmp(confirmationCode, "1234") != 0) {
						printf("\n -- Códido de confirmação inválido. Preencha novamente, por favor! --\n\n", setlocale(LC_ALL,""));
						goto confirmCode;
					}
					
				strcpy(client.telefone, phone);
				break;
			default:
				printf("Opção selecionada inválida! Digite a opção correta: \n", setlocale(LC_ALL,""));
				goto optRegistration;
		}
	
	outCpfInfo();
	
	printf("Digite seu nome completo: ");
	fflush(stdin);
	fgets(client.nome, 30, stdin);
	
	// -------------- CPF --------------
	char cpf[15];
	validateCpf:	
		printf("CPF: ");
		fflush(stdin);
		scanf("%s", cpf);
		
		if(strlen(cpf) != 11) {
			printf("-- O CPF não é válido. Preencha novamente, por favor! --\n\n", setlocale(LC_ALL,""));
			goto validateCpf;
		}
		
		i = 0; j = 10;
		int sum = 0;
		for(i = 0; i < (strlen(cpf) - 2); i++){
			sum += (cpf[i] - '0') * j;
			j--;
		}
		
		if(((sum * 10) % 11) != (cpf[9] - '0')) {
			printf("-- O primeiro dígito verificador não é válido. Preencha novamente, por favor! --\n\n", setlocale(LC_ALL,""));
			goto validateCpf;
		}
		
		j = 11; sum = 0;
		for(i = 0; i < (strlen(cpf) - 1); i++){
			sum += (cpf[i] - '0') * j;
			j--;
		}
		
		if(((sum * 10) % 11) != (cpf[10] - '0')) {
			printf("-- O segundo dígito verificador não é válido. Preencha novamente, por favor! --\n\n", setlocale(LC_ALL,""));
			goto validateCpf;
		}
		
	strcpy(client.cpf, cpf);
	// -------------- SEXO DO CLIENTE --------------
	char optSex;
	recieveClientSex: 
		printf("Gênero: \n", setlocale(LC_ALL,""));
		printf("| M - Masculino\n| F - Feminino\n| N - Prefiro não informar\n\n", setlocale(LC_ALL,""));
		
		fflush(stdin);
		scanf("%c", &optSex);
		
		if((optSex != 'M' && optSex != 'm') && (optSex != 'F' && optSex != 'f') && (optSex != 'N' && optSex != 'n')) {
			printf("Opção inválida! Preencha novamente, por favor.", setlocale(LC_ALL,""));
			goto recieveClientSex;
		}
	client.sexo = optSex;
	
	// -------------- DATA DE ANIVERSÁRIO --------------
	char strDay[2], strMonth[2], strYear[4];
	Date getDate = {0};
	int status = 0;
	recieveBirthDate:	    
	    printf("Data de nascimento (dd/mm/YYYY): ");
	    scanf("%d/%d/%d",&getDate.dd,&getDate.mm,&getDate.yyyy);
	    
	    if (isValidDate(&getDate) == 0) {
	    	printf("-- Data inválida. Preencha novamente, por favor! --\n\n", setlocale(LC_ALL,""));
			goto recieveBirthDate;
		}
		
		itoa(getDate.dd, strDay, 10);
		itoa(getDate.mm, strMonth, 10);
		itoa(getDate.yyyy, strYear, 10);
		
	strcpy(client.datanascimento, (strcat(strcat(strcat(strDay, "/"), strcat(strMonth, "/")), strYear)));
	
	// -------------- ENDEREÇO DO CLIENTE --------------
	outAddressInfo();
	recieveAddress:
		printf("Endereço: ");
		fflush(stdin);
		fgets(client.endereco, 50, stdin);
		
		printf("Número: ", setlocale(LC_ALL,""));
		fflush(stdin);
		fgets(client.numero, 50, stdin);
		
		printf("Complemento (tecle enter se não tiver): ", setlocale(LC_ALL,""));
		fflush(stdin);
		fgets(client.complemento, 50, stdin);
		
		printf("Bairro: ", setlocale(LC_ALL,""));
		fflush(stdin);
		fgets(client.bairro, 50, stdin);
		
		printf("Referência do endereço: ", setlocale(LC_ALL,""));
		fflush(stdin);
		fgets(client.referenciaEndereco, 50, stdin);
	
	outPreferencesInfo();
	
	int optionSegment = 0;
	i = 0; j = 0;
	
	chooseCategory:
	do {
		printf("Qual tipo de produto é de seu interesse?\n1 - Prototipação para indústria\n2 - Decoração\n3 - Área médica\n4 - Artigos personalizados\n5 - Outros\n0 - Não desejo cadastrar isso agora\n\n", setlocale(LC_ALL,""));
		fflush(stdin);
		scanf("%d", &client.categorias[i]);
		horizontalLine();
		
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
			horizontalLine();
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
	
	if(checkout == 0) {
		system("clear");
		goto optRegistration;
	} else {
		success();
		system("pause");
	}
}
