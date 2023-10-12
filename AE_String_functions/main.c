/**
 * @file main.c
 * @author Lukas Verwiebe
 * @brief 
 * @version 0.1
 * @date 2023-10-12
 * In dieser Datei wurden unterschiedliche Funktionen zum Umgang mit Strings umgesetzt.
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>


/**
 * @brief 
 * Die Funktion entfernt aus einem Text einen Buchstaben und gibt den geänderten Text zurück.
 * @param p_string 
 * @param a 
 * @param filter_string 
 */
void string_filter(char *p_string, char a, char *filter_string)
{
	while(*p_string != '\0')
	{
		if(*p_string != a)
		{
			*filter_string = *p_string;
			filter_string++;
		}
		p_string++;
	}
	*filter_string = '\0';
}


/**
 * @brief 
 * Die Funktion dreht einen String um
 * @param string 
 */
void reverse_string(char string[])
{
	int i, j;
	int len = 0;
	char c;
	while(string[len] != '\0')
	{
		len++;
	}

	for(i = 0, j = len -1; i < j; i++, j--)
	{
		c = string[i];
		string[i] = string[j];
		string[j] = c;
	}
}


/**
 * @brief 
 * Die Funktion Kopiert einen String von Parameter 1 zu Parameter 2
 * @param from 
 * @param to 
 */
void copy_string(const char from[], char to[])
{
	int index;
	for(index = 0; from[index] != '\0'; index++)
	{
		to[index] = from[index];
	}
	to[index] = '\0';
}


/**
 * @brief 
 * Die Funktion ermittelt die Länge eines Strings ohne '\0'
 * @param string 
 * @return int 
 */
int len(char string[])
{
	int len = 0;
	while(string[len] != '\0')
	{
		len++;
	}
	return len;
}


/**
 * @brief 
 * 
 * @return int 
 */
int main(void)
{
    /*
	 * Test Funktion: string_filter
	 */
	char buchstabe = 'a';
	char string[] = "Das ist eine Test Text mit a und ohne a.";
	char filter[100];
	string_filter(string, buchstabe,filter);
	printf("String: %s\n", filter);

	/*
	 *Test Funktion: reverse_string
	 */
	char reverse[] = "Hallo";
	reverse_string(reverse);
	printf("String reverse: %s\n", reverse);

	/*
	 * Test Funktion: copy_string
	 */
	char copy[100];
	copy_string("Hello\0", copy);
	printf("String Copy: %s\n", copy);

    /*
     * Test Funktion: len
    */
   char string_len[] = "Test Text";
   printf("Länge: %d\n", len(string_len));
}