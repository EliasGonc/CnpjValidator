#ifndef CNPJ_H_INCLUDED
#define CNPJ_H_INCLUDED

#define LENGTH 14
#define WEIGHTS_1 "543298765432"
#define WEIGHTS_2 "6543298765432"

/**
 * Gera o primeiro dígito verificador de um CNPJ se forem passados 12 dígitos
 * ou o segundo dígito verificador se forem passados 13 dígitos.
 *
 * @param incompleteCnpj O 12 ou 13 primeiros dígitos de um CNPJ.
 *
 * @return O primeiro ou segundo dígito verificar de um CNPJ.
 */
char generateValidationDigit(char *incompleteCnpj);

/**
 * Gera ambos os dígitos de verificadores de um CNPJ.
 *
 * @param Os 12 primeiros dígitos de um CNPJ.
 *
 * @return Os 2 dígitos verificadores de um CNPJ.
 */
char* generateValidationDigits(char *incompleteCnpj);

/**
 * Pede para o usuário o número da matriz/filial e gera um CNPJ aleatório.
 *
 * @return Um CNPJ aleatório.
 */
char* generateRandomCnpj();

/**
 * Verifica se um CNPJ informado é válido ou não.
 *
 * @param Os 14 dígitos de um CNPJ.
 *
 * @return 1 se for válido, 0 caso contrário.
 */
short int validadeCnpj(char *cnpj);

/**
 * Imprime o menu principal.
 */
void printMenu();

/**
 * Faz o tratamento do menu principal.
 *
 * @param menuOption A opção do menu principal que o usuário selecionou.
 */
void menuHandler(short int menuOption);

/**
 * Exibe um CNPJ com suas pontuações.
 *
 * @param cnpj Os 14 dígitos de um CNPJ.
 *
 * @return Uma string da forma 12.345.678/0001-95.
 */
const char *formatCnpj(char *cnpj);

#endif // CNPJ_H_INCLUDED
