/**
 * @file main.c
 * @author Lukas Verwiebe
 * @brief 
 * @version 0.1
 * @date 2023-10-12
 * 
 * In dieser Datei wurde ein Makro realisiert mit dem ein eingegebenes Byte bis zu einer angebenen Position invertiert wird.
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>


void print_binary(unsigned char byte);

 
/**
 * @brief 
 * Makro mit Übergabe als Variable und nicht als Wert:
 * Das Makro invertiert ein Byte bis zu der angegebenen Position.
 */
#define INVERT_BIT(C, POS) ({ unsigned char mask = 0x01u; for(int i = 0; i < POS; i++){C = C ^ mask; mask <<= 1;} C = ~(C);})

 
/**
 * @brief 
 * Lösung mit Übergabe als Wert und nicht als Variable:
 * Das Makro invertiert ein Byte bis zu der angegebenen Position.
 */
#define INVERT_BIT2(C, POS) ({ unsigned char hex = C; unsigned char mask = 0x01u; \
for(int i = 0; i < POS; i++) {hex = hex ^ mask; mask <<= 1; }                    \
hex = ~(hex);})


/**
 * @brief 
 * Die Funktion print_binary gibt ein übergebnes Byte binär in einer Zeile aus.
 * Beginn mit dem höchstwertigen Bit bis zum niedrigswertigen Bit.
 * @param byte 
 */
void print_binary(unsigned char byte)
{
    for(unsigned char mask = 0x80u; mask > 0; mask >>= 1)
    {
        printf("%d", ((byte & mask) == mask) ? 1 : 0);
    }
    printf("\n");
}



/**
 * @brief 
 * Test der definnierten Funktionen und Makros
 * @return int 
 */
int main(void)
{
    unsigned char hex1 = 0xFF;
    unsigned char hex2 = 0x00;

    printf("Test Makro INVERT BIT\n");

    printf("Ursprungswert 1: ");
    print_binary(0xFF);
    printf("INVERT BIT 1: ");
    print_binary(INVERT_BIT(hex1, 2));
    printf("\n");

    printf("Ursprungswert 2: ");
    print_binary(0x00);
    printf("INVERT BIT 2: ");
    print_binary(INVERT_BIT(hex2, 6));
    printf("\n\n\n");


    printf("Test Makro INVERT BIT2\n");

    printf("Ursprungswert 1: ");
    print_binary(0xFF);
    printf("INVERT BIT2 1: ");
    print_binary(INVERT_BIT2(0xFF, 2));
    printf("\n");

    printf("Ursprungswert 2: ");
    print_binary(0x00);
    printf("INVERT BIT2 2: ");
    print_binary(INVERT_BIT2(0x00, 6));
    printf("\n");

}
