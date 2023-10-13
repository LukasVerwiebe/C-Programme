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
#include "aufgaben.h"


#define DEBUG(A)


/**
 * @brief 
 * Die Funktion gibt einen eingegebenen Byte Wert in Binär Schreibweise in der Konsole aus.
 * @param byte 
 */
extern void print_binary(unsigned char byte)
{
    for(unsigned char mask = 0x80u; mask > 0; mask >>= 1)
    {
        printf("%d", ((byte & mask) == mask) ? 1 : 0);
    }
    printf("\n");
}


/**
 * @brief 
 * - Die Funktion liefert -1 wenn str1 alphabetisch vor str2 liegt
 * - Die Funktion liefert 1 wenn str2 alphabetisch vor str1 liegt
 * - Die Funktion liefert 0 wenn beide gleich sind 
 * @param str1 
 * @param str2 
 * @return int 
 */
extern int alphabet(char *str1, char *str2)
{
    int result = 0;
    if(*str1 < *str2)
    {
        result = -1;
    }
    else if(*str1 > *str2)
    {
        result = 1;
    }
    return result;
}



/**
 * @brief 
 * Test der Funktionen
 * @return int 
 */
int main()
{
    print_binary(22);

    DPRINT(5 + 4);

    DPRINT_NEW("text", s);
    DPRINT_NEW(1 + 4, d);
    DPRINT_NEW(1.0 + 4.5, f);


    printf("%d\n", alphabet("zabc", "def"));
	printf("%d\n", alphabet("abc", "def"));
	printf("%d\n", alphabet("def", "def"));
}