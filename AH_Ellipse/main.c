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
#include <stdarg.h>


/**
 * @brief 
 * Die Funktion bestimmt die Summe der übergebenen Werte
 * @param count 
 * @param ... 
 * @return int 
 */
int add_numbers(int count, ...)
{
	int index;
	int sum = 0;
	va_list p_args;
	int current_number;
	va_start(p_args, count);
	for (index = 0; index < count; index++)
	{
		current_number = va_arg(p_args, int);
		sum = sum + current_number;
	}
	va_end(p_args);
	return sum;
}


/**
 * @brief 
 * Die Funktion bestimmt den Durchschnitt der übergebenen Argumente. 
 * Das letzte Argument dient als Makierung für das Ende, dieser muss -1 sein.
 * @param number 
 * @param ... 
 * @return double 
 */
double average(int number, ...)
{
    va_list p_args;
    int current_number;
    int sum = 0;
    int count = 0;

    va_start(p_args, number);

    current_number = number;
    do
    {
        sum = sum + current_number;
        count++;

        current_number = va_arg(p_args, int); 
    } 
    while (current_number != -1);
    
    va_end(p_args);

    return (double)(sum / count);
}


/**
 * @brief 
 * 
 * @return int 
 */
int main(void)
{    
    printf("Summe: %d\n", add_numbers(5, 1,2,3,4,5));
    printf("%f\n", average(1,2,3,4,55,-1));
}