/**
 * @file main.c
 * @author Lukas Verwiebe
 * @brief 
 * @version 0.1
 * @date 2023-10-12
 * In der Datei wurden Funktionen und Makros realisiert die unterschiedliche Berechnungen ausführen.
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>


/**
 * @brief 
 * Das Makro gibt die Größere von zwei Zahlen zurück
 */
#define MAX(A, B) ((A > B) ? A : B)


/**
 * @brief 
 * Das Makro berechnet die Fakultät einer Zahl. * 
 */
#define FAKULTEAT(A) ({int new_number = 1; int index = 1; \
if(A > 1){                                                \
while(index < A){new_number = new_number * (index +1); index++;} \
} A = new_number;})


/**
 * @brief 
 * Das Makro berechnet die Fakultät einer Zahl.
 */
#define FAKULTEAT2(A) ({int number = A; int new_number = 1; int index = 1; \
if(A > 1){                                                                 \
while(index < A){new_number = new_number * (index +1); index++;}           \
} number = new_number;})


/**
 * @brief 
 * Das Makro rechnet eine Fahreheitwert in Celsius um
 */
#define FAHRENHEIT_RECHNER(A) ({ double celsius; celsius = ((A - 32) * 5.0/9.0); })


/**
 * @brief 
 * Die Funktion Berechnet die Fakultät einer Zahl
 * @param number 
 * @return int 
 */
int fakultaet(int number)
{
	int new_number = 1;
	int index = 1;

	if(number > 1)
	{
		while(index < number)
		{
			new_number = new_number * (index + 1);
			index++;
		}
	}
	return new_number;
}


/**
 * @brief 
 * Die Funktion rechnet einen Fahreheit Wert in Celsius um
 * @param fahrenheit 
 * @return double 
 */
double fahrenheit_rechner(int fahrenheit)
{
	return (double)(fahrenheit - 32) * 5/9;
}



/**
 * @brief 
 * Test der Funktionen und Makros
 * @return int 
 */
int main(void)
{
    // Test Funktion: fakultaet
    printf("Test Funktion: fakultaet\n");
    printf("Fakulteat 0: %d\n", fakultaet(0));
	printf("Fakulteat 1: %d\n", fakultaet(1));
	printf("Fakulteat 2: %d\n", fakultaet(2));
	printf("Fakulteat 3: %d\n", fakultaet(3));
	printf("Fakulteat 4: %d\n", fakultaet(4));
	printf("Fakulteat 5: %d\n", fakultaet(5));
	printf("\n");

    // Test Makro: FAKULTEAT
    printf("Test Makro: FAKULTEAT\n");
	int a = 0, b = 1, c = 2, d = 3, e = 4 , f = 5;
	FAKULTEAT(a);
	FAKULTEAT(b);
	FAKULTEAT(c);
	FAKULTEAT(d);
	FAKULTEAT(e);
	FAKULTEAT(f);
	int test = FAKULTEAT2(6);    
	printf("Fakulteat 0: %d\n", a);
	printf("Fakulteat 1: %d\n", b);
	printf("Fakulteat 2: %d\n", c);
	printf("Fakulteat 3: %d\n", d);
	printf("Fakulteat 4: %d\n", e);
	printf("Fakulteat 5: %d\n", f);
	printf("\n");


    // Test Makro: FAKULTEAT2 
    printf("Test Makro: FAKULTEAT2\n");
	printf("Fakulteat 0: %d\n", FAKULTEAT2(0));
	printf("Fakulteat 1: %d\n", FAKULTEAT2(1));
	printf("Fakulteat 2: %d\n", FAKULTEAT2(2));
	printf("Fakulteat 3: %d\n", FAKULTEAT2(3));
	printf("Fakulteat 4: %d\n", FAKULTEAT2(4));
	printf("Fakulteat 5: %d\n", FAKULTEAT2(5));
    printf("\n");

	// Test Funktion: fahrenheit_rechner
    printf("Test Funktion: fahrenheit_rechner\n");
	printf("Celsius: %1.1f\n", fahrenheit_rechner(55));
	printf("Celsius: %1.1f\n", fahrenheit_rechner(32));
	printf("Celsius: %1.1f\n", fahrenheit_rechner(86));
	printf("\n");


    // Test Makro: FAHRENHEIT_RECHNER
    printf("Test Makro: FAHRENHEIT_RECHNER\n");
	printf("Celsius: %1.1f\n", FAHRENHEIT_RECHNER(55));
	printf("Celsius: %1.1f\n", FAHRENHEIT_RECHNER(32));
	printf("Celsius: %1.1f\n", FAHRENHEIT_RECHNER(87));
    printf("\n");

    // Test Makro: MAX
    printf("Test Makro: MAX\n");
    printf("MAX: %d\n", MAX(10, 5));
    printf("\n");
}
