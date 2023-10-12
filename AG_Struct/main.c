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
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/**
 * @brief 
 * union bei der eine char Variable eine int Variable überlagert
 */
union ANGESTELLTEN_INFO
{
	unsigned char name[15];
	int personalnummer;
};


/**
 * @brief 
 * enum für das Genre
 */
typedef enum
{
    BLUES,
    CLASSIC,
    JAZZ,
    POP,
    ROCK
} GENRE;


/**
 * @brief 
 * Struktur für das Datum
 */
typedef struct
{
    int tag;
    int monat;
    int jahr;
} DATUM;


/**
 * @brief 
 * Struktur für eine CD
 */
typedef struct
{
    char title[50];
    GENRE genre;
    DATUM edatum;
} CD;


/**
 * @brief 
 * Funktion zum vergleichen von Datums Strukturen
 * @param d1 
 * @param d2 
 * @return true 
 * @return false 
 */
static bool cmp_datum(DATUM *d1, DATUM *d2)
{
    return d1 != NULL && d2 != NULL
        && d1->tag == d2->tag
        && d1->monat == d2->monat
        && d1->jahr == d2->jahr; 
}


/**
 * @brief 
 * Funktion zum vergleichen von zwei CD Strukturen
 * @param cd1 
 * @param cd2 
 * @return true 
 * @return false 
 */
static bool cmp_cd(CD *cd1, CD *cd2)
{
    return cd1 != NULL && cd2 != NULL
        && strcmp(cd1->title, cd2->title) == 0
        && cd1->genre == cd2->genre
        && cmp_datum(&(cd1->edatum), &(cd2->edatum));
}


/**
 * @brief 
 * Funktion zum Anzeigen der CD Daten in der Konsole
 */
void print_cd(CD cd)
{
    printf("Titel: %s, Genre: %d, Datum: %2d.%2d.%4d\n", cd.title, cd.genre, cd.edatum.tag, cd.edatum.monat, cd.edatum.jahr);
}



/**
 * @brief 
 * Test der Funktionen
 * @return int 
 */
int main(void)
{
   CD cd1 = {"Revolver", POP, {22,03,2001}};
   CD cd2 = {"Revolver", POP, {22,03,2001}};
   CD cd3 = cd1;
   CD cd4 = {"Revolver", JAZZ, {22,03,2001}};

    print_cd(cd1);
    print_cd(cd2);
    print_cd(cd3);

    printf("Bool: %d\n", cmp_cd(&cd1, &cd2));
    printf("Bool: %d\n", cmp_cd(&cd2, &cd3));
    printf("Bool: %d\n", cmp_cd(&cd2, &cd4));

}
