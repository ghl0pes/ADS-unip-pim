#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#include "./middlewares/validDate.c"

char*recieveEmail () {
	char email[30], confirmationEmail[30];
	
	printf("Informe seu e-mail para continuar: ");
	scanf("%s", email);
	
	if(strlen(email) == 0) {
		printf("\n -- Endereço de email inválido. Preencha novamente, por favor! --\n\n", setlocale(LC_ALL,""));
		recieveEmail();
	}
		
	printf("Por favor, confirme o email: ");
	scanf("%s", confirmationEmail);
	
	if (strcmp(email, confirmationEmail) != 0) {
		printf("\n -- Endereços de e-mail não conferem. Preencha novamente, por favor! --\n\n", setlocale(LC_ALL,""));
		recieveEmail();
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
		recieveEmail();
	}
	
	return email;
}


char*recieveCellphone () {
	char phone[30];
	char validChars[15] = "01234567890+-()";
	
	printf("Informe seu celular para continuar: ");
	scanf("%s", phone);
	
	int i, j, invalidChars = 0;
	
	for(i = 0; i < strlen(phone); i++) {
		int valid = 0;
		for(j = 0; j < strlen(validChars); j++) 
			if(validChars[j] == phone[i]) valid++;	
			
		if(valid == 0) invalidChars++;
	}
	
	if(invalidChars > 0) {
		printf("-- O telefone possui caracteres inválidos. Preencha novamente, por favor! --\n\n", setlocale(LC_ALL,""));
		recieveCellphone();
	}
	
	return phone;
}


char*validateCpf() {
	char cpf[30];
	
	printf("Digite seu CPF para prosseguir: ");
	scanf("%s", cpf);
	
	if(strlen(cpf) != 11) {
		printf("-- O CPF não é válido. Preencha novamente, por favor! --\n\n", setlocale(LC_ALL,""));
		validateCpf();
	}
	
	int i, j = 10, sum = 0;
	for(i = 0; i < (strlen(cpf) - 2); i++){
		sum += (cpf[i] - '0') * j;
		j--;
	}
	
	if(((sum * 10) % 11) != (cpf[9] - '0')) {
		printf("-- O primeiro dígito verificador não é válido. Preencha novamente, por favor! --\n\n", setlocale(LC_ALL,""));
		validateCpf();
	}
	
	j = 11; sum = 0;
	for(i = 0; i < (strlen(cpf) - 1); i++){
		sum += (cpf[i] - '0') * j;
		j--;
	}
	
	if(((sum * 10) % 11) != (cpf[10] - '0')) {
		printf("-- O segundo dígito verificador não é válido. Preencha novamente, por favor! --\n\n", setlocale(LC_ALL,""));
		validateCpf();
	}
	
	return cpf;
}

char*recieveBirthDate() {
	Date getDate = {0};
    int status = 0;
    
    printf("Data de nascimento (dd/mm/YYYY): ");
    scanf("%d/%d/%d",&getDate.dd,&getDate.mm,&getDate.yyyy);
    
    if (isValidDate(&getDate) == 0) {
    	printf("-- Data inválida. Preencha novamente, por favor! --\n\n", setlocale(LC_ALL,""));
		validateCpf();
	}
	
	char strDay[2], strMonth[2], strYear[4];
	itoa(getDate.dd, strDay, 10);
	itoa(getDate.mm, strMonth, 10);
	itoa(getDate.yyyy, strYear, 10);
	
	return (strcat(strcat(strcat(strDay, "/"), strcat(strMonth, "/")), strYear));
}

char*recieveClientSex() {
	char optSex;
	
	printf("Sexo: ");
	printf("M - Masculino\nF - Feminino\nN - Prefiro não informar", setlocale(LC_ALL,""));
	
	scanf("%c", optSex);
	
	if(optSex != 'M' && optSex != 'F' && optSex != 'N') {
		printf("Opção inválida! Preencha novamente, por favor.", setlocale(LC_ALL,""));
		recieveClientSex();
	}
	
	return optSex;
}

char*recieveAddress() {
	char address[50];
	
	printf("Endereço: ");
	fflush(stdin);
	fgets(address, 50, stdin);
	
	return address;
}

char*recieveNumber() {
	char addressNumber[10];
	
	printf("Número: ", setlocale(LC_ALL,""));
	fflush(stdin);
	fgets(addressNumber, 50, stdin);
	
	return addressNumber;
}

char*recieveComplement() {
	char complement[30];
	
	printf("Complemento (tecle enter se não tiver): ", setlocale(LC_ALL,""));
	fflush(stdin);
	fgets(complement, 50, stdin);
	
	return complement;
}

char*recieveDistrict() {
	char district[30];
	
	printf("Bairro: ", setlocale(LC_ALL,""));
	fflush(stdin);
	fgets(district, 50, stdin);
	
	return district;
}

char*recieveRef() {
	char refAddress[30];
	
	printf("Referência do endereço: ", setlocale(LC_ALL,""));
	fflush(stdin);
	fgets(refAddress, 50, stdin);
	
	return refAddress;
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
