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
		char *validationDigits = malloc(3 * sizeof(char));
		for(short int i = 0; i < 8; i++) {
			char buffer[2];
			itoa(rand() % 10, buffer, 10);
			cnpj[i] = buffer[0];
		}
		for(short int i = 0; i < strlen(branch); i++) {
			cnpj[i+8] = branch[i];
		}
		validationDigits = generateValidationDigits(cnpj);
		for(short int i = 0; i < strlen(validationDigits); i++) {
			cnpj[i+12] = validationDigits[i];
		}
		cnpj[LENGTH] = '\0';
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
	printf("Selecione uma opção abaixo.\n");
	printf("1. Gerar CNPJ aleatório.\n");
	printf("2. Gerar dígitos verificadores de um CNPJ.\n");
	printf("3. Validar CNPJ.\n");
	printf("4. Sair.\n");
	printf("Opção: ");
}

void menuHandler(short int menuOption) {
	char cnpj[LENGTH+1], validationDigits[3], branch[5];
	system("cls");
	switch(menuOption) {
	case 1:
		printf("Digite o número da filial/matriz (4 dígitos): ");
		scanf("%s", branch);
		fflush(stdin);
		if(strlen(branch) == 4) {
			//char *formattedCnpj = ;
			printf("CNPJ: %s\n", formatCnpj(generateRandomCnpj(branch)));
			//free(formattedCnpj);
		} else {
			printf("O número da filial/matriz deve possuir 4 dígitos.\n");
		}
		printf("\nPressione qualquer tecla pra retornar ao menu principal.\n");
		break;
	case 2:
		printf("Digite os 12 dígitos iniciais (apenas números): ");
		scanf("%s", cnpj);
		fflush(stdin);
		if(strlen(cnpj) == 12) {
			strcpy(validationDigits, generateValidationDigits(cnpj));
			printf("\nOs dígitos verificadores são %s.\n", validationDigits);
		} else {
			printf("Você digitou apenas %d dígitos.\n", (int)strlen(cnpj));
		}
		printf("\nPressione qualquer tecla pra retornar ao menu principal.\n");
		break;
	case 3:
		printf("Digite o CNPJ (apenas digitos): ");
		scanf("%s", cnpj);
		fflush(stdin);
		switch(checkCnpjValidity(cnpj)) {
		case 0:
			printf("O CNPJ digitado é válido.\n");
			break;
		case 1:
			printf("O CNPJ digitado não é válido.\n");
			break;
		case 2:
			printf("O CNPJ digitado não contém 14 dígitos.\n");
			break;
		}
		printf("\nPressione qualquer tecla pra retornar ao menu principal.\n");
		break;
	case 4:
		printf("\nEncerrando...\n");
		break;
	default:
		printf("Opção inválida. Pressione qualquer tecla para continuar.\n");
	}
	system("pause>nul");
}
const char* formatCnpj(char *cnpj) {
	short int formattedCnpjLength = LENGTH+5;
	char *formattedCnpj = malloc(formattedCnpjLength * sizeof(char));
	short k = 0;
	if(checkCnpjValidity(cnpj) == 0) {
		for(short int i = 0; i < formattedCnpjLength; i++) {
			switch(i) {
			case 2:
			case 6:
				formattedCnpj[i] = '.';
				break;
			case 10:
				formattedCnpj[i] = '/';
				break;
			case 15:
				formattedCnpj[i] = '-';
				break;
			default:
				formattedCnpj[i] = cnpj[k];
				k++;
			}
		}
		formattedCnpj[formattedCnpjLength-1] = '\0';
	}
	return formattedCnpj;
}
