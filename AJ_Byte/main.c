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
#include <stdbool.h>


void print_binary(unsigned char byte);
bool is_set(unsigned char byte, short pos);

/**
 * @brief 
 * Die Funktion gibt einen eingegebenen Byte Wert in Binär Schreibweise in der Konsole aus.
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
 * Die Funktion liefert true, wenn das Bit an der übergebenen Position gesetzt ist und false sonst.
 * @param byte 
 * @param pos 
 * @return true 
 * @return false 
 */
bool is_set(unsigned char byte, short pos)
{
    return ((0x01 << pos) & byte) > 0; 
}


/**
 * @brief Set the bit object
 * Die Funktion setzt im übergebenen Byte das Bit an der übergebenen Position
 * @param byte 
 * @param pos 
 * @return unsigned char 
 */
unsigned char set_bit(unsigned char byte, short pos)
{
    return (0x01 << pos) | byte;
}


/**
 * @brief 
 * Die Funktion löscht im übergebenen Byte an der übergebenen Position
 * @param byte 
 * @param pos 
 * @return unsigned char 
 */
unsigned char delete_bit(unsigned char byte, short pos)
{
    return ~(0x01 << pos) & byte;
}


/**
 * @brief 
 * Die Funktion invertiert im übergebenen Byte alle Bits außer das Bit an der übergebenen Stelle
 * @param byte 
 * @param pos 
 * @return unsigned char 
 */
unsigned char invert_bits(unsigned char byte, short pos)
{
    return ~(0x01 << pos) ^ byte;
}


/**
 * @brief 
 * Die Funktion rotiert die Bits im übergebenen Byte um eine übergebene Anzahl von Bits nach rechts
 * @param byte 
 * @param count 
 * @return unsigned char 
 */
unsigned char rotate_bits(unsigned char byte, short count)
{
    return (byte >> count) | (byte << (8 - count));
}


/**
 * @brief 
 * Die Funktion prüft ob eine eingegebene Zahl eine Zweierpotenz ist
 * @param n 
 * @return true 
 * @return false 
 */
bool is_power_of_two(unsigned int n)
{
    return n != 0 && ((n & (n - 1)) == 0x00);
}



/**
 * @brief 
 * Test Funktion
 * @return int 
 */
int main(void)
{
    
}