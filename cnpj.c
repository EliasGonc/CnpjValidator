#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>
#include "cnpj.h"

char generateValidationDigit(char *incompleteCnpj) {
	char buffer[2];
	char *weights = strlen(incompleteCnpj) == 12 ? WEIGHTS_1 : WEIGHTS_2;
	int weightedSum = 0, remainder;

	switch(strlen(incompleteCnpj)) {
	case 12:
	case 13:
		for(short int i = 0; i < strlen(weights); i++) {
			char cnpjDigit[2] = {incompleteCnpj[i], '\0'};
			char digitWeight[2] = {weights[i], '\0'};
			weightedSum += atoi(cnpjDigit) * atoi(digitWeight);
		}
		if((remainder = weightedSum % 11) < 2) {
			return '0';
		} else {
			itoa(11 - remainder, buffer, 10);
			return buffer[0];
		}
		break;
	default:
		return 'e';
	}
}

char* generateValidationDigits(char *incompleteCnpj) {
	char *validationDigits = malloc(3 * sizeof(char));
	char almostCompleteCnpj[LENGTH];
	if(strlen(incompleteCnpj) == LENGTH-2) {
		validationDigits[0] = generateValidationDigit(incompleteCnpj);
		validationDigits[1] = '\0';
		strcpy(almostCompleteCnpj, incompleteCnpj);
		strcat(almostCompleteCnpj, validationDigits);
		validationDigits[1] = generateValidationDigit(almostCompleteCnpj);
		validationDigits[2] = '\0';
		return validationDigits;
	} else {
		return "e\0";
	}
}

char* generateRandomCnpj(char *branch) {
	if(strlen(branch) == 4) {
		char *cnpj = malloc((LENGTH+1) * sizeof(char));
		for(short int i = 0; i < 8; i++) {
			char buffer[2];
			itoa(rand() % 10, buffer, 10);
			cnpj[i] = buffer[0];
		}
		strcat(cnpj, branch);
		strcat(cnpj, generateValidationDigits(cnpj));
		return cnpj;
	} else {
		return "e";
	}
}

short int checkCnpjValidity(char *cnpj) {
	char partialCnpj[LENGTH-1];
	char validationDigits[3];
	char correctCnpj[LENGTH+1];

	if(strlen(cnpj) == 14) {
		strncpy(partialCnpj, cnpj, LENGTH-2);
		strcpy(validationDigits, generateValidationDigits(partialCnpj));
		strcpy(correctCnpj, partialCnpj);
		strcat(correctCnpj, validationDigits);
		if(strcmp(cnpj, correctCnpj) == 0) {
			return 0;
		}
		return 1;
	} else {
		return 2;
	}
}

void printMenu() {
	system("cls");
	printf("Selecione uma op��o abaixo.\n");
	printf("1. Gerar CNPJ aleat�rio.\n");
	printf("2. Gerar d�gitos verificadores de um CNPJ.\n");
	printf("3. Validar CNPJ.\n");
	printf("4. Sair.\n");
	printf("Op��o: ");
}

void menuHandler(short int menuOption) {
	char cnpj[LENGTH+1], validationDigits[3], branch[5];
	system("cls");
	switch(menuOption) {
	case 1:
		printf("Digite o n�mero da filial/matriz: ");
		scanf("%s", branch);
		printf("CNPJ: %s\n",  formatCnpj(generateRandomCnpj(branch)));
		printf("\nPressione qualquer tecla pra retornar ao menu principal.\n");
		break;
	case 2:
		printf("Digite os 12 d�gitos iniciais (apenas n�meros): ");
		scanf("%s", cnpj);
		strcpy(validationDigits, generateValidationDigits(cnpj));
		printf("\nOs d�gitos verificadorse s�o %s.\n", validationDigits);
		printf("\nPressione qualquer tecla pra retornar ao menu principal.\n");
		break;
	case 3:
		printf("Digite o CNPJ (apenas digitos): ");
		scanf("%s", cnpj);
		switch(checkCnpjValidity(cnpj)) {
		case 0:
			printf("O CNPJ digitado � v�lido.\n");
			break;
		case 1:
			printf("O CNPJ digitado n�o � v�lido.\n");
			break;
		case 2:
			printf("O CNPJ digitado n�o cont�m 14 d�gitos.\n");
			break;
		}
		printf("\nPressione qualquer tecla pra retornar ao menu principal.\n");
		break;
	case 4:
		printf("\nEncerrando...\n");
		break;
	default:
		printf("Op��o inv�lida. Pressione qualquer tecla para continuar.\n");
	}
	system("pause>nul");
}
char* formatCnpj(char *cnpj) {
	short int formattedCnpjLength = LENGTH+5;
	char *formattedCnpj = malloc((formattedCnpjLength)*sizeof(char));
	short k = 0;
	if(checkCnpjValidity(cnpj) == 0) {
		memset(formattedCnpj, ' ', formattedCnpjLength);
		formattedCnpj[2] = '.';
		formattedCnpj[6] = '.';
		formattedCnpj[10] = '/';
		formattedCnpj[15] = '-';
		for(short int i = 0; i < formattedCnpjLength; i++) {
			if(formattedCnpj[i] == ' ') {
				formattedCnpj[i] = cnpj[k];
				k++;
			}
		}
		formattedCnpj[formattedCnpjLength-1] = '\0';
	}
	return formattedCnpj;
}
