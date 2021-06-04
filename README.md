# CnpjValidator
 One of the exercises for my Programming Language course at FATEC Mogi Mirim, which involves creating a program that checks whether or not 14 digits typed by the user represent a CNPJ (*Cadastro Nacional da Pessoa Jurídica*).
## CNPJ validation input
The user must enter 14 numeric characters. The program does not check whether the character is a number or not.
## CNPJ validation output
The program tells the user if what they entered:
- is a valid CNPJ number;
- is not a valid CNPJ number; or
- doesn't have 14 digits.
## Extra functions
Some extra functions were developed for this exercise.
### Random CNPJ generator
Given some headquarter/branch office number, which are the 9th to 12th CNPJ digits, generates a random CNPJ number.
### Validation digits generator
Given the first 12 digits of a CNPJ number, the program generates last two, which are the validation digits.