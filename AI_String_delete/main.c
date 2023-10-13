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


/**
 * @brief 
 * Die Funktion Löscht einen Buchastaben aus einer Zeichenkette
 * @param string 
 * @param buchstabe 
 */
void delete_char(char string[], char buchstabe)
{
	int i = 0;
	int j = 0;
	for(i = 0; string[i] != '\0'; i++)
	{
		if(string[i] != buchstabe)
		{
			string[j] = string[i];
			j++;
		}
	}
	string[j] = '\0';
}



/**
 * @brief 
 * 
 * @return int 
 */
int main(void)
{
    char buchstabe_a = 'a';
	char string_a[] = "Das ist ein Test mit a: aber, dass, aufgabe, tabelle.";
	delete_char(string_a, buchstabe_a);
	printf("String Delete: %s\n", string_a);

}
