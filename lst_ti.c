#include "main.h"
/**
 * custom_print - Checks if a character is printable
 * @c: The character being checked.
 *
 * Return: 1 if c was printed and 0 if not.
 */
int custom_print(char c)
{
if (c >= 32 && c < 127)
return (1);
return (0);
}
/**
 * add_custom_hexa_code - Appends ASCII in hexadecimal code to the buffer.
 * @buffer: The buffer to append to.
 * @i: The appending index
 * @ascii_code: ASCII code to append.
 *
 * Return: Always 3.
 */
int add_custom_hexa_code(char ascii_code, char buffer[], int i)
{
char map_to[] = "0123456789ABCDEF";
if (ascii_code < 0)
ascii_code *= -1;
buffer[i++] = '\\';
buffer[i++] = 'x';
buffer[i++] = map_to[ascii_code / 16];
buffer[i] = map_to[ascii_code % 16];
return (3);
}
/**
 * custom_digit - Checks if a character is a digit.
 * @c: The character to check.
 *
 * Return: 1 if c is a digit, 0 otherwise.
 */
int custom_digit(char c)
{
if (c >= '0' && c <= '9')
return (1);
return (0);
}
/**
 * change_custom_numsize - Casts a number to the specified size.
 * @num: The number to be casted.
 * @size: The size indicating the type to be casted.
 *
 * Return: Casted value of num.
 */
long int change_custom_numsize(long int num, int size)
{
if (size == SIZE_LONG)
return (num);
else if (size == SIZE_SHORT)
return ((short)num);
return ((int)num);
}
/**
 * change_customsize_unsined - Casts an unsigned number to the specified size.
 * @num: The unsigned number to be casted.
 * @size: The size indicating the type to be casted.
 *
 * Return: Casted value of num.
 */
long int change_customsize_unsined(unsigned long int num, int size)
{
if (size == SIZE_LONG)
return (num);
else if (size == SIZE_SHORT)
return ((unsigned short)num);
return ((unsigned int)num);
}
