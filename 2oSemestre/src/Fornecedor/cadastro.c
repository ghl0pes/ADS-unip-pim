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
	char nomeEmpresa[30];
	char razaoSocial[30];
	char cnpj[15];
	char email[30];
	char telefone[30];
	
	//infos de endere�o
	char cep[15];
	char endereco[50];
	char numero[10];
	char complemento[30];
	char bairro[30];
	char referenciaEndereco[30];
	char situacaoCadastral;
	
	//categorias de atua��o da empresa
	int categorias[10];
	int categoriasFilhas[30];
	
	//funcion�rios
	int codigo[10];
	int cargo[10];
	int emailFuncionario[10][50];
} company_card;
/*
int outCheckoutClient(company_card company) {
	system("cls");
	horizontalLine();
	
	printf("Confira seus dados para confirmar o cadastro na plataforma.\n\n", setlocale(LC_ALL,""));
	
	horizontalLine();
	printf("--- Dados Pessoais ---\n");
	printf("| Nome: %s\n", company.nomeEmpresa);
	printf("| Email: %s\n", company.email);
	printf("| CPF: %s\n", company.cpf);
	printf("| Sexo: %c\n", company.sexo);
	printf("| Telefone: %s\n", company.telefone);
	printf("| Data de nascimento: %s\n\n", company.datanascimento);
	
	horizontalLine();
	printf("--- Dados de endere�o ---\n");
	printf("| Endere�o: %s", company.endereco);
	printf("| N�mero: %s", company.numero);
	printf("| Complemento: %s", company.complemento);
	printf("| Bairro: %s", company.bairro);
	printf("| Refer�ncia do endere�o: %s\n\n", company.referenciaEndereco);
	
	horizontalLine();
	printf("--- Categorias de interesse ---\n");
	int i = 0;
	while(company.categorias[i] != 0 ){
		if(company.categorias[i] < 10) {
			printf("| -%d\n", companycliente.categorias[i]); 
			int j = 0;
			while(company.categoriasFilhas[j] != 0) {
				switch(company.categorias[i]) {
					case 1:
						if(company.categoriasFilhas[j] > 10 && company.categoriasFilhas[j] <= 16)
							printf("| --%d\n", companycliente.categoriasFilhas[j]); 
						break;
					case 2:
						if(company.categoriasFilhas[j] > 20 && company.categoriasFilhas[j] <= 24)
							printf("| --%d\n", company.categoriasFilhas[j]); 
						break;
					case 3:
						if(company.categoriasFilhas[j] > 30 && company.categoriasFilhas[j] <= 32)
							printf("| --%d\n", company.categoriasFilhas[j]); 
						break;
					case 4:
						if(company.categoriasFilhas[j] > 40 && company.categoriasFilhas[j] <= 41)
							printf("| --%d\n", company.categoriasFilhas[j]); 
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
	printf("Deseja confirmar o cadastro? 1 - Sim / 0 - N�o\n", setlocale(LC_ALL,""));
	scanf("%d", &check);
	
	return check;
}*/

int main() {
	company_card company;
	
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
					printf("\n -- Endere�o de email inv�lido. Preencha novamente, por favor! --\n\n", setlocale(LC_ALL,""));
					goto recieveEmail;
				}
					
				printf("Por favor, confirme o email: ");
				scanf("%s", confirmationEmail);
				
				if (strcmp(email, confirmationEmail) != 0) {
					printf("\n -- Endere�os de e-mail n�o conferem. Preencha novamente, por favor! --\n\n", setlocale(LC_ALL,""));
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
					printf("\n -- Endere�o de e-mail inv�lido. Preencha novamente, por favor! --\n\n", setlocale(LC_ALL,""));
					goto recieveEmail;
				}
				
				confirmCode:
					printf("Enviamos um c�digo de confirma��o /(1234)/ para o seu email, digite para continuar: ", setlocale(LC_ALL,""));
					scanf("%s", confirmationCode);
					
					if(strcmp(confirmationCode, "1234") != 0) {
						printf("\n -- C�dido de confirma��o inv�lido. Preencha novamente, por favor! --\n\n", setlocale(LC_ALL,""));
						goto confirmCode;
					}
				strcpy(company.email, email);				
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
					printf("-- O telefone possui caracteres inv�lidos. Preencha novamente, por favor! --\n\n", setlocale(LC_ALL,""));
					goto recieveCellphone;
				}
				
				confirmCode:
					printf("Enviamos um c�digo de confirma��o /(1234)/ por SMS, digite para continuar: ", setlocale(LC_ALL,""));
					scanf("%s", confirmationCode);
					
					if(strcmp(confirmationCode, "1234") != 0) {
						printf("\n -- C�dido de confirma��o inv�lido. Preencha novamente, por favor! --\n\n", setlocale(LC_ALL,""));
						goto confirmCode;
					}
					
				strcpy(company.telefone, phone);
				break;
			default:
				printf("Op��o selecionada inv�lida! Digite a op��o correta: \n", setlocale(LC_ALL,""));
				goto optRegistration;
		}
	
	/*outCpfInfo();
	
	printf("Digite seu nome completo: ");
	fflush(stdin);
	
	// -------------- CPF --------------
	char cnpj[15];
	validateCNPJ:	
		printf("Cnpj: ");
		fflush(stdin);
		scanf("%s", cnpj);
		
		if(strlen(cnpj) != 11) {
			printf("-- O CNPJ n�o � v�lido. Preencha novamente, por favor! --\n\n", setlocale(LC_ALL,""));
			goto validateCNPJ;
		}
		
		i = 0; j = 10;
		int sum = 0;
		for(i = 0; i < (strlen(cnpj) - 2); i++){
			sum += (cnpj[i] - '0') * j;
			j--;
		}
		
		if(((sum * 10) % 11) != (cnpj[9] - '0')) {
			printf("-- O primeiro d�gito verificador n�o � v�lido. Preencha novamente, por favor! --\n\n", setlocale(LC_ALL,""));
			goto validateCNPJ;
		}
		
		j = 11; sum = 0;
		for(i = 0; i < (strlen(cpf) - 1); i++){
			sum += (cpf[i] - '0') * j;
			j--;
		}
		
		if(((sum * 10) % 11) != (cpf[10] - '0')) {
			printf("-- O segundo d�gito verificador n�o � v�lido. Preencha novamente, por favor! --\n\n", setlocale(LC_ALL,""));
			goto validateCNPJ;
		}
		
	strcpy(company.cnpj, cnpj);
	// -------------- SEXO DO CLIENTE --------------
	char optSex;
	recieveClientSex: 
		printf("Sexo: \n");
		printf("| M - Masculino\n| F - Feminino\n| N - Prefiro n�o informar\n\n", setlocale(LC_ALL,""));
		
		fflush(stdin);
		scanf("%c", &optSex);
		
		if((optSex != 'M' && optSex != 'm') && (optSex != 'F' && optSex != 'f') && (optSex != 'N' && optSex != 'n')) {
			printf("Op��o inv�lida! Preencha novamente, por favor.", setlocale(LC_ALL,""));
			goto recieveClientSex;
		}
	company.sexo = optSex;
	
	// -------------- DATA DE ANIVERS�RIO --------------
	char strDay[2], strMonth[2], strYear[4];
	Date getDate = {0};
	int status = 0;
	recieveBirthDate:	    
	    printf("Data de nascimento (dd/mm/YYYY): ");
	    scanf("%d/%d/%d",&getDate.dd,&getDate.mm,&getDate.yyyy);
	    
	    if (isValidDate(&getDate) == 0) {
	    	printf("-- Data inv�lida. Preencha novamente, por favor! --\n\n", setlocale(LC_ALL,""));
			goto recieveBirthDate;
		}
		
		itoa(getDate.dd, strDay, 10);
		itoa(getDate.mm, strMonth, 10);
		itoa(getDate.yyyy, strYear, 10);
		
	strcpy(company.datanascimento, (strcat(strcat(strcat(strDay, "/"), strcat(strMonth, "/")), strYear)));
	
	// -------------- ENDERE�O DO CLIENTE --------------
	outAddressInfo();
	recieveAddress:
		printf("Endere�o: ");
		fflush(stdin);
		fgets(company.endereco, 50, stdin);
		
		printf("N�mero: ", setlocale(LC_ALL,""));
		fflush(stdin);
		fgets(company.numero, 50, stdin);
		
		printf("Complemento (tecle enter se n�o tiver): ", setlocale(LC_ALL,""));
		fflush(stdin);
		fgets(company.complemento, 50, stdin);
		
		printf("Bairro: ", setlocale(LC_ALL,""));
		fflush(stdin);
		fgets(company.bairro, 50, stdin);
		
		printf("Refer�ncia do endere�o: ", setlocale(LC_ALL,""));
		fflush(stdin);
		fgets(company.referenciaEndereco, 50, stdin);
	
	outPreferencesInfo();
	
	int optionSegment = 0;
	i = 0; j = 0;
	
	chooseCategory:
	do {
		printf("Qual tipo de produto � de seu interesse?\n1 - Prototipa��o para ind�stria\n2 - Decora��o\n3 - �rea m�dica\n4 - Artigos personalizados\n5 - Outros\n0 - N�o desejo cadastrar isso agora\n\n", setlocale(LC_ALL,""));
		fflush(stdin);
		scanf("%d", &company.categorias[i]);
		horizontalLine();
		
		if(client.categorias[i] < 0 || client.categorias[i] > 5) {
			printf("Categoria inv�lida!. Preencha novamente, por favor!\n\n", setlocale(LC_ALL,""));
			goto chooseCategory;
		} else if (company.categorias[i] == 0) {
			break;
		}
		
		int optSub;
		chooseSubCategory:
		do {
			optSub = 0;
			optsSegmentChild(company.categorias[i]);
			scanf("%d", &company.categoriasFilhas[j]);
			horizontalLine();
			if (
				(company.categorias[i] == 1 && (company.categoriasFilhas[j] <= 10 || company.categoriasFilhas[j] > 16)) ||
				(company.categorias[i] == 2 && (company.categoriasFilhas[j] <= 20 || company.categoriasFilhas[j] > 24)) ||
				(company.categorias[i] == 3 && (company.categoriasFilhas[j] <= 30 || company.categoriasFilhas[j] > 32)) ||
				(company.categorias[i] == 4 && (company.categoriasFilhas[j] <= 40 || company.categoriasFilhas[j] > 41))
			) {
				printf("Subcategoria inv�lida. Preencha novamente, por favor!\n\n");
				goto chooseSubCategory;
			}
			
			printf("Deseja cadastrar mais alguma subcategoria? 1 - Sim / 0 - N�o\n", setlocale(LC_ALL,""));
			scanf("%d", &optSub);
			
			j++;
		} while (optSub == 1);
		
		
		printf("\n-Deseja cadastrar mais uma categoria? 1 - Sim /0 - N�o\n", setlocale(LC_ALL,""));
		scanf("%d", &optionSegment);
		i++;
	} while (optionSegment == 1);
	
	int checkout;
	checkout = outCheckoutClient(company);
	
	if(checkout == 0) {
		system("clear");
		goto optRegistration;
	} else {
		success();
		system("pause");
	}	*/
}