#include "main.h"
/**
 * gen_custom_unsigned - A function that Prints an unsigned number
 * @args: List of arguments
 * @buffer: Buffer array for printing
 * @flags: Active format flags
 * @width: specified width
 * @precision: specified precision
 * @size: specified size
 *
 * Return: Total Number of characters printed
 */
int gen_custom_unsigned(va_list args, char buffer[], int flags,
int width, int precision, int size)
{
int index = BUFFER_SIZE - 2;
unsigned long int dig = va_arg(args, unsigned long int);
dig = change_customsize_unsined(dig, size);
if (dig == 0)
buffer[index--] = '0';
buffer[BUFFER_SIZE - 1] = '\0';
while (dig > 0)
{
buffer[index--] = (dig % 10) + '0';
dig /= 10;
}
index++;
return (add_custom_unsined(0, index, buffer, flags, width, precision, size));
}
/**
 * gen_custom_octal - A function that Prints an unsigned
 * number in octal notation
 * @args: List of arguments
 * @buffer: Buffer array for printing
 * @flags: Active format flags
 * @width: Width specified width
 * @precision: specified precision
 * @size: specified size
 *
 * Return: Total Number of characters printed
 */
int gen_custom_octal(va_list args, char buffer[], int flags,
int width, int precision, int size)
{
int index = BUFFER_SIZE - 2;
unsigned long int dig = va_arg(args, unsigned long int);
unsigned long int beg_dig = dig;
if (size == SIZE_LONG)
{
if ((long int)dig < 0)
{
buffer[index--] = (dig % 8) * -1 + '0';
dig /= 8;
}
else
{
buffer[index--] = (dig % 8) + '0';
dig /= 8;
}
}
if (dig == 0)
buffer[index--] = '0';
buffer[BUFFER_SIZE - 1] = '\0';
while (dig > 0)
{
buffer[index--] = (dig % 8) + '0';
dig /= 8;
}
if ((flags & FLAG_HASH) && beg_dig != 0)
buffer[index--] = '0';
index++;
return (add_custom_unsined(0, index, buffer, flags, width, precision, size));
}
/**
 * gen_custom_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @args: List of arguments
 * @buffer: Buffer array for printing
 * @flags: Active format flags
 * @width: specified width
 * @precision: specified precision
 * @size: specified size
 *
 * Return: Total Number of characters printed
 */
int gen_custom_hexadecimal(va_list args, char buffer[], int flags,
int width, int precision, int size)
{
return (gen_custom_hexa(args, "0123456789abcdef", buffer, flags,
'x', width, precision, size));
}
/**
 * gen_custom_upper_hexa - Prints an unsigned number in
 * upper hexadecimal notation
 * @args: List of arguments
 * @buffer: Buffer array for printing
 * @flags: Active format flags
 * @width: Width specified width
 * @precision: specified precision
 * @size: specified size
 *
 * Return: Total Number of characters printed
 */
int gen_custom_upper_hexa(va_list args, char buffer[],
int flags, int width, int precision, int size)
{
return (gen_custom_hexa(args, "0123456789ABCDEF", buffer, flags,
'X', width, precision, size));
}
/**
 * gen_custom_hexa -A function that Prints a hexadecimal
 * number in lower or upper case
 * @args: List of arguments
 * @map_to: Array of values to map the number to
 * @buffer: Buffer array for printing
 * @flags: Active format flags
 * @flag_ch: Active format flags
 * @width: specified width
 * @precision: specified precision
 * @size: specified size
 *
 * Return: Total Number of characters printed
 */
int gen_custom_hexa(va_list args, char map_to[], char buffer[],
int flags, char flag_ch, int width, int precision, int size)
{
int index = BUFFER_SIZE - 2;
unsigned long int dig = va_arg(args, unsigned long int);
unsigned long int beg_dig = dig;
if (size == SIZE_LONG)
{
if ((long int)dig < 0)
{
buffer[index--] = map_to[(dig % 16) * -1];
dig /= 16;
}
else
{
buffer[index--] = map_to[dig % 16];
dig /= 16;
}
}
if (dig == 0)
buffer[index--] = '0';
buffer[BUFFER_SIZE - 1] = '\0';
while (dig > 0)
{
buffer[index--] = map_to[dig % 16];
dig /= 16;
}
if ((flags & FLAG_HASH) && beg_dig != 0)
{
buffer[index--] = flag_ch;
buffer[index--] = '0';
}
index++;
return (add_custom_unsined(0, index, buffer, flags, width, precision, size));
}
