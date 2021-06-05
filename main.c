#include <stdio.h>
#include <locale.h>
#include "cnpj.h"

int main() {
	setlocale(LC_ALL, "Portuguese");
	short int option;

	do {
		printMenu();
		scanf("%hd", &option);
		fflush(stdin);
		menuHandler(option);
	} while(option != 4);
    return 0;
}
