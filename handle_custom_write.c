#include "main.h"
/**
 * add_custom_char - Handles the character format specifier
 * @c: Character to print.
 * @buffer: Buffer to handle the print.
 * @flags: Active formatting flags.
 * @width: Width specifier.
 * @precision: Precision specifier.
 * @size: Size specifier.
 * Return: Number of characters printed.
 */
int add_custom_char(char c, char buffer[], int flags,
int width, int precision, int size)
{
int x = 0;
char padding = ' ';
UNUSED_VAR(precision);
UNUSED_VAR(size);
if (flags & FLAG_ZERO)
padding = '0';
buffer[x++] = c;
buffer[x] = '\0';
if (width > 1)
{
buffer[BUFFER_SIZE - 1] = '\0';
for (x = 0; x < width - 1; x++)
buffer[BUFFER_SIZE - x - 2] = padding;
if (flags & FLAG_MINUS)
return (write(1, &buffer[0], 1) +
write(1, &buffer[BUFFER_SIZE - x - 1], width - 1));
else
return (write(1, &buffer[BUFFER_SIZE - x - 1], width - 1) +
write(1, &buffer[0], 1));
}
return (write(1, &buffer[0], 1));
}
/**
 * add_custom_number - Handles the number format specifier
 * @is_negative: Indicates if the number is negative.
 * @ind: Index where the number starts in the buffer.
 * @buffer: Buffer for handling the print.
 * @flags: Active formatting flags.
 * @width: Width specifier.
 * @precision: Precision specifier.
 * @size: Size specifier.
 * Return: Number of characters printed.
 */
int add_custom_number(int is_negative, int ind, char buffer[],
int flags, int width, int precision, int size)
{
int length = BUFFER_SIZE - ind - 1;
char padding = ' ', extra_char = 0;
UNUSED_VAR(size);
if (precision == 0 && ind == BUFFER_SIZE - 2 && buffer[ind] == '0')
return (0);
if (precision > 0 && precision < length)
padding = ' ';
while (precision > length)
{
buffer[--ind] = '0';
length++;
}
if (flags & FLAG_ZERO && !(flags & FLAG_MINUS))
padding = '0';
if (is_negative)
extra_char = '-';
else if (flags & FLAG_PLUS)
extra_char = '+';
else if (flags & FLAG_SPACE)
extra_char = ' ';
return (add_custom_num(ind, buffer, flags, width,
precision, length, padding, extra_char));
}
/**
 * add_custom_num - Handles the number formatting and padding.
 * @ind: Index where the number starts in the buffer.
 * @buffer: Buffer for handling the print.
 * @flags: Active formatting flags.
 * @width: Width specifier.
 * @precision: Precision specifier.
 * @length: Length of the number.
 * @padding: Padding character.
 * @extra_char: Extra character.
 * Return: Number of characters printed.
 */
int add_custom_num(int ind, char buffer[], int flags, int width, int precision,
int length, char padding, char extra_char)
{
int x, padding_start = 1;
if (precision == 0 && ind == BUFFER_SIZE - 2 && buffer[ind] == '0'
&& width == 0)
return (0);
if (precision == 0 && ind == BUFFER_SIZE - 2 && buffer[ind] == '0')
buffer[ind] = padding = ' ';
if (precision > 0 && precision < length)
padding = ' ';
while (precision > length)
buffer[--ind] = '0', length++;
if (extra_char != 0)
length++;
if (width > length)
{
for (x = 1; x < width - length + 1; x++)
buffer[x] = padding;
buffer[x] = '\0';
if (flags & FLAG_MINUS && padding == ' ')
{
if (extra_char)
buffer[--ind] = extra_char;
return (write(1, &buffer[ind], length) + write(1, &buffer[1], x - 1));
}
else if (!(flags & FLAG_MINUS) && padding == ' ')
{
if (extra_char)
buffer[--ind] = extra_char;
return (write(1, &buffer[1], x - 1) + write(1, &buffer[ind], length));
}
else if (!(flags & FLAG_MINUS) && padding == '0')
{
if (extra_char)
buffer[--padding_start] = extra_char;
return (write(1, &buffer[padding_start], x - padding_start) +
write(1, &buffer[ind], length - (1 - padding_start)));
}
}
if (extra_char)
buffer[--ind] = extra_char;
return (write(1, &buffer[ind], length));
}
/**
 * add_custom_unsined - Handles the unsigned number format specifier
 * @is_negative: Indicates if the number is negative.
 * @ind: Index where the number starts in the buffer.
 * @buffer: Buffer for handling the print.
 * @flags: Active formatting flags.
 * @width: Width specifier.
 * @precision: Precision specifier.
 * @size: Size specifier.
 *
 * Return: Number of characters printed.
 */
int add_custom_unsined(int is_negative, int ind, char buffer[], int flags,
int width, int precision, int size)
{
int length = BUFFER_SIZE - ind - 1, x;
char padding = ' ';
UNUSED_VAR(is_negative);
UNUSED_VAR(size);
if (precision == 0 && ind == BUFFER_SIZE - 2 && buffer[ind] == '0')
return (0);
if (precision > 0 && precision < length)
padding = ' ';
while (precision > length)
{
buffer[--ind] = '0';
length++;
}
if (flags & FLAG_ZERO && !(flags & FLAG_MINUS))
padding = '0';
if (width > length)
{
for (x = 0; x < width - length; x++)
{
buffer[x] = padding;
}
buffer[x] = '\0';
if (flags & FLAG_MINUS)
{
return (write(1, &buffer[ind], length) + write(1, &buffer[0], x));
}
else
{
return (write(1, &buffer[0], x) + write(1, &buffer[ind], length));
}
}
return (write(1, &buffer[ind], length));
}
#include "main.h"
/**
 * add_custom_pointer - Write a memory address
 * @buffer: Array of characters
 * @ind: Index at which the number starts in the buffer
 * @length: Length of the number
 * @width: Width specifier
 * @flags: Flags specifier
 * @padding: Character representing the padding
 * @extra_char: Character representing an extra character
 * @padding_start: Index at which padding should start
 *
 * Return: Number of written characters.
 */
int add_custom_pointer(char buffer[], int ind, int length,
int width, int flags, char padding, char extra_char, int padding_start)
{
int x;
while (width > length)
{
buffer[x + 3] = padding;
x++;
}
buffer[x + 3] = '\0';
if (flags & FLAG_MINUS && padding == ' ')
{
buffer[ind - 1] = 'x';
buffer[ind - 2] = '0';
if (extra_char)
buffer[ind - 3] = extra_char;
return (write(1, &buffer[ind - 3], length) + write(1, &buffer[3], x));
}
else if (!(flags & FLAG_MINUS) && padding == ' ')
{
buffer[ind - 1] = 'x';
buffer[ind - 2] = '0';
if (extra_char)
buffer[ind - 3] = extra_char;
return (write(1, &buffer[3], x) + write(1, &buffer[ind - 3], length));
}
else if (!(flags & FLAG_MINUS) && padding == '0')
{
if (extra_char)
buffer[padding_start] = extra_char;
buffer[1] = '0';
buffer[2] = 'x';
return (write(1, &buffer[padding_start], x - padding_start) +
write(1, &buffer[ind - 3], length - (1 - padding_start) - 2));
}
buffer[ind - 1] = 'x';
buffer[ind - 2] = '0';
if (extra_char)
buffer[ind - 3] = extra_char;
return (write(1, &buffer[ind - 3], BUFFER_SIZE - ind - 1));
}
