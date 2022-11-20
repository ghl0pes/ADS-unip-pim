#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

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
	for(i = 0; i < (strlen(cpf) - 3); i++){
		sum += (cpf[i] - '0') * j;
		j--;
	}
	
	if(((sum * 10) % 11) != (cpf[9] - '0')) {
		printf("-- O CPF não é válido. Preencha novamente, por favor! --\n\n", setlocale(LC_ALL,""));
		validateCpf();
	}
	
	j = 11; sum = 0;
	for(i = 0; i < (strlen(cpf) - 2); i++){
		sum += (cpf[i] - '0') * j;
		j--;
	}
	
	if(((sum * 10) % 11) != (cpf[10] - '0')) {
		printf("-- O CPF não é válido. Preencha novamente, por favor! --\n\n", setlocale(LC_ALL,""));
		validateCpf();
	}
	
	return cpf;
}









