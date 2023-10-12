/**
 * @file main.c
 * @author Lukas Verwiebe
 * @brief 
 * @version 0.1
 * @date 2023-10-12
 * In dieser Datei wurde eine Funktion realisiert, die prüft ob eine Zeichenkette am Anfang einer zweiten Zeichenkette steht.
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>
#include <stdbool.h>


bool str_prefix(char *string, char *prefix);


/**
 * @brief 
 * Die Funktion prüft ob die zweite Zeichenkette "prefix" der beginn der ersten Zeichenkette "string" ist.
 * @param string 
 * @param prefix 
 * @return true 
 * @return false 
 */
bool str_prefix(char *string, char *prefix)
{    	
	while(*string != '\0' && *prefix != '\0')
	{
		if(*string != *prefix)
		{
			return false;
		}
		string++;
		prefix++;
	}
	return *prefix == '\0';
}


/**
 * @brief 
 * Test der Funktion
 * @return int 
 */
int main(void)
{
    printf("Bool: %d\n", str_prefix("2345", "23"));
	printf("Bool: %d\n", str_prefix("2345", "23456"));
	printf("Bool: %d\n", str_prefix("2345", "34"));
}