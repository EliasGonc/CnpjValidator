#ifndef CNPJ_H_INCLUDED
#define CNPJ_H_INCLUDED

#define LENGTH 14
#define WEIGHTS_1 "543298765432"
#define WEIGHTS_2 "6543298765432"

/**
 * Gera o primeiro d�gito verificador de um CNPJ se forem passados 12 d�gitos
 * ou o segundo d�gito verificador se forem passados 13 d�gitos.
 *
 * @param incompleteCnpj O 12 ou 13 primeiros d�gitos de um CNPJ.
 *
 * @return O primeiro ou segundo d�gito verificar de um CNPJ.
 */
char generateValidationDigit(char *incompleteCnpj);

/**
 * Gera ambos os d�gitos de verificadores de um CNPJ.
 *
 * @param Os 12 primeiros d�gitos de um CNPJ.
 *
 * @return Os 2 d�gitos verificadores de um CNPJ.
 */
char* generateValidationDigits(char *incompleteCnpj);

/**
 * Pede para o usu�rio o n�mero da matriz/filial e gera um CNPJ aleat�rio.
 *
 * @return Um CNPJ aleat�rio.
 */
char* generateRandomCnpj();

/**
 * Verifica se um CNPJ informado � v�lido ou n�o.
 *
 * @param Os 14 d�gitos de um CNPJ.
 *
 * @return 1 se for v�lido, 0 caso contr�rio.
 */
short int validadeCnpj(char *cnpj);

/**
 * Imprime o menu principal.
 */
void printMenu();

/**
 * Faz o tratamento do menu principal.
 *
 * @param menuOption A op��o do menu principal que o usu�rio selecionou.
 */
void menuHandler(short int menuOption);

/**
 * Exibe um CNPJ com suas pontua��es.
 *
 * @param cnpj Os 14 d�gitos de um CNPJ.
 *
 * @return Uma string da forma 12.345.678/0001-95.
 */
const char *formatCnpj(char *cnpj);

#endif // CNPJ_H_INCLUDED
