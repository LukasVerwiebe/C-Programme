/**
 * @file aufgaben.h
 * @author Lukas Verwiebe
 * @brief 
 * @version 0.1
 * @date 2023-10-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef AK_HEADER_AUFGABEN_H
#define AK_HEADER_AUFGABEN_H


/**
 * @brief 
 * Makro das nur Positive Zahlen zurückgeben soll
 */
#define ABS(A) ({ ((A) < 0) ? 0-(A) : (A); })


/**
 * @brief 
 * Test Makro
 */
#define DEBUG(A)


/**
 * @brief 
 * Das Makro DPRINT wird abhängigvon DEBUG definiert
 */
#ifdef DEBUG
#define DPRINT(P) printf(#P " = %d\n", P) // Das Makro gibt sowohl den übergebenen Term als auch das Ergebnis in der Konsole aus.
#else
#define DPRINT(P) printf("DEBUG wurde nicht definiert!")
#endif


/**
 * @brief 
 * Erweiterung des DPRINT-Makros für alle Datentypen
 */
#define DPRINT_NEW(EXP, FORMAT) printf(#EXP " = %"#FORMAT "\n", EXP)


/**
 * @brief 
 * Die Funktion gibt einen eingegebenen Byte Wert in Binär Schreibweise in der Konsole aus.
 * @param byte 
 */
extern void print_binary(unsigned char byte);


/**
 * @brief 
 * Die Funktion soll prüfen ob ein String alphabetisch vor oder nach einer Zeichenkette steht
 * @param str1 
 * @param str2 
 * @return int 
 */
extern int alphabet(char *str1, char *str2);


#endif 