#include "main.h"
/**
 * add_custom_char - A custom function that Prints a character
 * @character: Character to print
 * @buffer: The Buffer array that handles printing
 * @flags: Active formatting flags
 * @width: specifies the width
 * @precision: specifies the precision
 * @size: specifies the size
 *
 * Return: printed Number of characters
 */
int add_custom_char(char character, char buffer[],
int flags, int width, int precision, int size)
{
int printed_chars = 0;
int x;
char padding = ' ';
UNUSED_VAR(precision);
UNUSED_VAR(size);
if (flags & FLAG_ZERO)
padding = '0';
buffer[0] = character;
buffer[1] = '\0';
if (width > 1)
{
buffer[BUFFER_SIZE - 1] = '\0';
x = 0;
while (x < width - 1)
{
buffer[BUFFER_SIZE - x - 2] = padding;
x++;
}
if (flags & FLAG_MINUS)
{
printed_chars = write(1, &buffer[0], 1) +
write(1, &buffer[BUFFER_SIZE - x - 1], width - 1);
}
else
{
printed_chars = write(1, &buffer[BUFFER_SIZE - x - 1], width - 1) +
write(1, &buffer[0], 1);
}
}
else
{
printed_chars = write(1, &buffer[0], 1);
}
return (printed_chars);
}
