/**
 * @file main.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-10-12
 * 
 * In dieser Datei wurde eine Funktion realisiert mit dem eine eingegebenes Zeichenkette auf das vorhanden sein einer weiteren Zeichenkette geprüft wird.
 * Wenn diese vorhanden ist wird die Zeichenkette durch eine dritte ersetzt.
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>
#include <string.h>

void *string_replace(char *s1, char *s2, char *s3);


/**
 * @brief 
 * Die Funktion prüft ob eine Zeichenkette "s2" in der Zeichenkette "s1" enthalten ist. Wenn dies der Fall ist, 
 * wird in Zeichenkette "s1" die Zeichenkette "s2" durch die Zeichenkette "s3" ersetzt.
 * @param s1 
 * @param s2 
 * @param s3 
 * @return void* 
 */
void *string_replace(char *s1, char *s2, char *s3)
{
	char new_string[] = "";
	char *new_ptr = &new_string[0];
	unsigned long lens1 = strlen(s1);
	unsigned long lens2 = strlen(s2);
	unsigned long lens3 = strlen(s3);

	int index = 0;

	// Prüfen, ob die Zeichenkette vorhanden ist oder nicht:
	if(strstr(s1, s2))
	{
		// Ersten Teil String erstellen:
		while(*s1 != *s2)
		{
			new_string[index] = *s1;
			index++;
			s1++;
		}
	}
	else
	{
		// Wenn der teilstring nicht vorhanden ist wird nur der String s2 übernommen:
		while(*s1 != '\0')
		{
			new_string[index] = *s1;
			index++;
			s1++;
		}
	}

	// Wenn der Index bereits die Länge von s2 hat, gibt es keine Änderungen:
	if(index != lens1)
	{
		s1 = s1 + lens2;

		while(*s3 != '\0')
		{
			new_string[index] = *s3;
			index++;
			s3++;
		}

		while(*s1 != '\0')
		{
			new_string[index] = *s1;
			index++;
			s1++;
		}
	}
	// Letztes Element des Vectors mit '\0' belegen damit dieser keine feste Größe braucht:
	new_string[index] = '\0';
    printf("String: %s\n", new_ptr);
	
	return new_ptr;
}


/**
 * @brief 
 * Test Funktion:
 * @return int 
 */
int main(void)
{
	char *s1 = "ABCDEF";
	char *s2 = "CD";
	char *s3 = "XYZ";

	string_replace(s1, s2, s3);
    
	char *s11 = "ABCDEF";
	char *s22 = "CD";
	char *s33 = "X";

	string_replace(s11, s22, s33);

	char *s111 = "ABCDEF";
	char *s222 = "MD";
	char *s333 = "XYZ";

	string_replace(s111, s222, s333);

	char *s1111 = "ABCDEF";
	char *s2222 = "CE";
	char *s3333 = "XYZ";

	string_replace(s1111, s2222, s3333);

}