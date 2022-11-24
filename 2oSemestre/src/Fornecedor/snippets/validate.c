#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int validaCNPJ() {
	char cnpj[14];
	int verificaUm[12] = {5,4,3,2,9,8,7,6,5,4,3,2}, verificaDois[13] = {6,5,4,3,2,9,8,7,6,5,4,3,2}; 
	
	printf("Digite o CNPJ a ser validado: ");
	scanf("%s", cnpj);
	
	if(strlen(cnpj) != 14) {
		printf("CNPJ precisa ter 14 algarismos. Digite novamente!");
		validaCNPJ();
	}
	
	int somatorio = 0, i;
	for (i = 0; i < 12; i++) {
		somatorio += (cnpj[i] - '0') * verificaUm[i];
	}
	
	int primeiro = (somatorio % 11);
	
	if (primeiro < 2) {
		if ((cnpj[strlen(cnpj) -2] - '0') != 0) {
			printf("Primeiro dígito verificador é inválido. Digite novamente!\n", setlocale(LC_ALL,""));
			validaCNPJ();
		}
	} else {
		if ((11 - primeiro) != (cnpj[strlen(cnpj) -2] - '0')) {
			printf("Primeiro dígito verificador é inválido. Digite novamente!\n", setlocale(LC_ALL,""));
			validaCNPJ();
		}
	}
	
	somatorio = 0;
	for (i = 0; i < 13; i++) {
		somatorio += (cnpj[i] - '0') * verificaDois[i];
	}
	
	int segundo = (somatorio % 11);
	if (segundo < 2) {
		if ((cnpj[strlen(cnpj) -1] - '0') != 0) {
			printf("Segundo dígito verificador é inválido. Digite novamente!\n", setlocale(LC_ALL,""));
			validaCNPJ();
		}
	} else {
		if ((11 - segundo) != (cnpj[strlen(cnpj) -1] - '0')) {
			printf("Segundo dígito verificador é inválido. Digite novamente!\n", setlocale(LC_ALL,""));
			validaCNPJ();
		}
	}
	
	printf("cnpj ok");
	
	return 0;
}
