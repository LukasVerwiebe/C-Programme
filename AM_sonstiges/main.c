/**
 * @file main.c
 * @author Lukas Verwiebe
 * @brief 
 * @version 0.1
 * @date 2023-10-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>
#include <math.h>


/** Version 1:
 * @brief 
 * Makro zum Runden der Nachkommastellen
 * Es muss eine Kommazahl und die Position bis zu der gerundet werden soll angegeben werden.
 * Bis zu der Angegebenen Position wird die Zahl dann gerundet. Dazu wird die Stelle vor der Position ermittelt und entsprechend
 * des Ergebnisses Gerundet.
 */
#define ROUND(NUMBER, POS) ({ double result = NUMBER; 										\
double power = pow(10,POS);                               \
double power_2 = pow(10,POS+1); 								\
double p_number_1 = power * NUMBER;                    \
double p_number_2 = power_2 * NUMBER;           \
int p_number_int_1 = (int)p_number_1;                  \
int p_number_int_2 = (int)p_number_2;         \
double test1 = p_number_int_2 / 10.0;   \
double neu = test1 - p_number_int_1;          \
int neuezahl = neu * 10;\
if(neuezahl >= 5)                                      \
{result = (p_number_int_1 / power) + (1.0 / power);}               \
else{result = p_number_int_1 / power+1;}  \
result;																				\
})


/** Version 2:
 * @brief 
 * Makro zum Runden der Nachkommastellen
 * Es muss eine Kommazahl und die Position bis zu der gerundet werden soll angegeben werden.
 * Bis zu der Angegebenen Position wird die Zahl dann gerundet. Dazu wird die Stelle vor der Position ermittelt und entsprechend
 * des Ergebnisses Gerundet.
 */
#define ROUND2(NUMBER, POS) ({ double result; 						\
double power_1 = pow(10, POS); 										\
double p_number_1 = power_1 * NUMBER;         						\
double p_number_2 = pow(10, POS + 1) * NUMBER;                         \
double new_digit = ((int)p_number_2 / 10.0) - (int)p_number_1;         \
int digit = new_digit * 10;									\
if(digit >= 5)                                      				\
{result = ((int)p_number_1 / power_1) + (1.0 / power_1);}           \
else{result = (int)p_number_1 / power_1;}  							\
result;																\
})


/** Version 3:
 * @brief 
 * Makro zum Runden der Nachkommastellen
 * Es muss eine Kommazahl und die Position bis zu der gerundet werden soll angegeben werden.
 * Bis zu der Angegebenen Position wird die Zahl dann gerundet. Dazu wird die Stelle vor der Position ermittelt und entsprechend
 * des Ergebnisses Gerundet.
 */
#define ROUND3(NUMBER, POS) ({ double result; \
double new_digit = ((int)(NUMBER * pow(10, POS + 1)) / 10.0) - (int)(NUMBER * pow(10, POS)); \
int digit = new_digit * 10; \
if(digit >= 5){ result = (int)(NUMBER * pow(10, POS)) / pow(10,POS) + (1.0 / pow(10, POS)); } \
else{ result = (int)(NUMBER * pow(10, POS)) / pow(10,POS); }                           \
result;\
})


/**
 * @brief 
 * Die Funktion zählt die Anzahl eines Buchstaben in einer Zeichenkette
 * @param string 
 * @param buchstabe 
 * @return int 
 */
int count_char(char *string, char buchstabe)
{
	int count = 0;

	while(*string != '\0')
	{
		if(*string == buchstabe)
		{
			count++;
		}
		string++;
	}

	return count;
}


/**
 * @brief 
 * Die Funktion zählt die Anzahl von einsen in einem Byte
 * @param byte 
 * @return int 
 */
int byte_number(char byte)
{
	int count = 0;
	unsigned char mask;
	for(mask = 0x01; mask > 0; mask <<= 1)
	{
		if((byte & mask) > 0)
		{
			count++;
		}
	}
	return count;
}






/**
 * @brief 
 * 
 * @return int 
 */
int main(void)
{
    printf("ROUND 1: %f\n", ROUND(1.56789, 1));
	printf("ROUND 2: %f\n", ROUND(1.56789, 2));
	printf("ROUND 3: %f\n", ROUND(1.56789, 3));
	printf("ROUND 4: %f\n", ROUND(1.56789, 4));
	printf("ROUND 5: %f\n", ROUND(1.56789, 5));
	printf("ROUND 6: %f\n", ROUND(1.56789, 6));
	printf("\n");

	printf("ROUND 1: %f\n", ROUND(1.56409, 1));
	printf("ROUND 2: %f\n", ROUND(1.56409, 2));
	printf("ROUND 3: %f\n", ROUND(1.56409, 3));
	printf("ROUND 4: %f\n", ROUND(1.56409, 4));
	printf("ROUND 5: %f\n", ROUND(1.56409, 5));
	printf("ROUND 6: %f\n", ROUND(1.56409, 6));
	printf("\n");

	printf("ROUND 1: %f\n", ROUND2(1.56789, 1));
	printf("ROUND 2: %f\n", ROUND2(1.56789, 2));
	printf("ROUND 3: %f\n", ROUND2(1.56789, 3));
	printf("ROUND 4: %f\n", ROUND2(1.56789, 4));
	printf("ROUND 5: %f\n", ROUND2(1.56789, 5));
	printf("ROUND 6: %f\n", ROUND2(1.56789, 6));
	printf("\n");

	printf("ROUND 1: %f\n", ROUND2(1.56409, 1));
	printf("ROUND 2: %f\n", ROUND2(1.56409, 2));
	printf("ROUND 3: %f\n", ROUND2(1.56409, 3));
	printf("ROUND 4: %f\n", ROUND2(1.56409, 4));
	printf("ROUND 5: %f\n", ROUND2(1.56409, 5));
	printf("ROUND 6: %f\n", ROUND2(1.56409, 6));
	printf("\n");

	printf("ROUND3 1: %f\n", ROUND3(1.56409, 1));
    printf("\n");  


    printf("%d\n", count_char("01abc0a", 'a'));
	printf("%d\n", count_char("00abc01ea", 'd'));
	printf("\n");

	printf("%d\n", byte_number(5));
	printf("%d\n", byte_number(55));
	printf("\n");

}