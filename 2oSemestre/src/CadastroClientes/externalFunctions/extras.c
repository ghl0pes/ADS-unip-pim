#include <stdio.h>
#include <string.h>
#include <locale.h>

void verticalLine(linesQuantity) {
	int i;
	for (i = 0; i < linesQuantity; i++) {
		printf("|                                                |\n");
	}
}

void horizontalLine()  {
	printf("--------------------------------------------------\n");
}

int validEmail (email) {
	int i, count;
	
	for (i = 0; i < strlen(email); i ++) {
		if(email[i] == '@' && (email[i++] || email[i--]) != '\0')
			count++;
	}
	
	printf("%d", count);
	
	return 1;
}

int validCellphone () {
	return 1;
}
