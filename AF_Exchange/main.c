/**
 * @file main.c
 * @author Lukas Verwiebe
 * @brief 
 * @version 0.1
 * @date 2023-10-12
 * In der Datei wurde eine Funktion realisiert die zwei Werte vertauscht.
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>


/**
 * @brief 
 * Das Makro gibt den Speicherblock einer Variable frei.
 */
#define FREE(A) ({ free(A); A = NULL; })


/**
 * @brief 
 * Die Funktion vertaucht zwei Werte miteinander.
 * @param x 
 * @param y 
 */
void tausch(int *x, int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}



/**
 * @brief 
 * Test der Funktion
 * @return int 
 */
int main(void)
{
    int a = 10;
    int b = 22;
    tausch(&a, &b);

    printf("a: %d\n", a);
    printf("b: %d\n", b);
}