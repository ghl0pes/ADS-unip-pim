#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

char*recieveEmail () {
	char email[30], confirmationEmail[30];
	
	printf("Informe seu e-mail para continuar: ");
	scanf("%s", email);
	
	if(strlen(email) == 0) {
		printf("\n -- Endere�o de email inv�lido. Preencha novamente, por favor! --\n\n");
		recieveEmail();
	}
		
	printf("Por favor, confirme o email: ");
	scanf("%s", confirmationEmail);
	
	if (strcmp(email, confirmationEmail) != 0) {
		printf("\n -- Endere�os de e-mail n�o conferem. Preencha novamente, por favor! --\n\n");
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
		printf("\n -- Endere�o de e-mail inv�lido. Preencha novamente, por favor! --\n\n");
		recieveEmail();
	}
	
	return email;
}


char*recieveCellphone () {
	char phone;
	char validChars[] = "01234567890+-()";
	
	printf("Informe seu celular para continuar: ");
	scanf("%s", phone);
	
	int i, j, invalidChars = 0;
	
	for(i = 0; i < strlen(phone); i++) {
		for(j = 0; j < strlen(validChars); j++) {
			if(validChars[j] != phone[i])
				invalidChars++;			
		}
	}
	
	if(invalidChars > 0) {
		printf("O telefone possui caracteres inv�lidos. Preencha novamente, por favor! --\n\n");
		recieveCellphone();
	}
	
	return phone;
}









