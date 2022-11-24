#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int validaCNPJ() {
	char cnpj[14];
	int verificaUm[12] = [5,4,3,2,9,8,7,6,5,4,3,2], verificaDois[13] = [6,5,4,3,2,9,8,7,6,5,4,3,2]; 
	
	printf("Digite o CNPJ a ser validado: ");
	scanf("%s", cnpj);
	
	if(strlen(cnpj) != 14) {
		printf("CNPJ precisa ter 14 algarismos. Digite novamente!");
		validaCNPJ();
	}
	
	int somatorio = 0, i;
	for (i = 0; i < strlen(cnpj), i++) {
		printf("%d * %d = %d", (cnpj[i] - '0'), verificaUm[i], (cnpj[i] - '0') * verificaUm[i]);
		somatorio += (cnpj[i] - '0') * verificaUm[i];
	}
	
	printf("%d", somatorio);
	
	
}
