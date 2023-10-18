#include "main.h"
/**
 * gen_custom_char -A function that Prints a character
 * @list: List of arguments
 * @buffer: Buffer array for printing
 * @flags: Active format flags
 * @width: specified width
 * @precision: specified precision
 * @size: specified size
 *
 * Return: Total Number of characters that's printed
 */
int gen_custom_char(va_list list, char buffer[], int flags,
int width, int precision, int size)
{
char c = va_arg(list, int);
return (add_custom_char(c, buffer, flags, width, precision, size));
}
/**
 * gen_custom_string - Prints a string
 * @list: List of arguments
 * @buffer: Buffer array for printing
 * @flags: Active format flag
 * @width: specified Width
 * @precision: specified precision
 * @size: specified size
 *
 * Return: Number of characters printed
 */
int gen_custom_string(va_list list, char buffer[], int flags,
int width, int precision, int size)
{
int lent = 0, x;
char *str = va_arg(list, char *);
UNUSED_VAR(buffer);
UNUSED_VAR(flags);
UNUSED_VAR(width);
UNUSED_VAR(precision);
UNUSED_VAR(size);
if (str == NULL)
{
str = "(null)";
if (precision >= 6)
str = "      ";
}
while (str[lent] != '\0')
lent++;
if (precision >= 0 && precision < lent)
lent = precision;
if (width > lent)
{
if (flags & FLAG_MINUS)
{
write(1, &str[0], lent);
for (x = width - lent; x > 0; x--)
write(1, " ", 1);
return (width);
}
else
{
for (x = width - lent; x > 0; x--)
write(1, " ", 1);
write(1, &str[0], lent);
return (width);
}
}
return (write(1, str, lent));
}
/**
 * gen_custom_percent - A function that Prints a percent sign
 * @list: List of arguments
 * @buffer: Buffer array for printing
 * @flags: Active format flags
 * @width: specified width
 * @precision: specified precision
 * @size: specified size
 *
 * Return: Total Numbers of characters printed
 */
int gen_custom_percent(va_list list, char buffer[], int flags,
int width, int precision, int size)
{
UNUSED_VAR(list);
UNUSED_VAR(buffer);
UNUSED_VAR(flags);
UNUSED_VAR(width);
UNUSED_VAR(precision);
UNUSED_VAR(size);
return (write(1, "%%", 1));
}
/**
 * gen_custom_int - A function that Prints an integer
 * @list: List of arguments
 * @buffer: Buffer array for printing
 * @flags: Active format flags
 * @width: specified Width
 * @precision: specificied precision
 * @size: specified size
 *
 * Return: Total Number of characters printed
 */
int gen_custom_int(va_list list, char buffer[], int flags,
int width, int precision, int size)
{
int index = BUFFER_SIZE - 2;
int is_negative = 0;
long int y = va_arg(list, long int);
unsigned long int dig;
y = change_custom_numsize(y, size);
if (y == 0)
buffer[index--] = '0';
buffer[BUFFER_SIZE - 1] = '\0';
dig = (unsigned long int)y;
if (y < 0)
{
dig = (unsigned long int)((-1) * y);
is_negative = 1;
}
while (dig > 0)
{
buffer[index--] = (dig % 10) + '0';
dig /= 10;
}
index++;
return (add_custom_number(is_negative, index, buffer, flags,
width, precision, size));
}
/**
 * gen_custom_binary - Prints an unsigned number in binary
 * @list: List of arguments
 * @buffer: Buffer array for printing
 * @flags: Active format flags
 * @width: specificatied width
 * @precision: specified precision
 * @size: specified size
 *
 * Return: Number of characters printed
 */
int gen_custom_binary(va_list list, char buffer[], int flags,
int width, int precision, int size)
{
unsigned int y, m, x, sum;
unsigned int a[32];
char z;
int cnt;
UNUSED_VAR(buffer);
UNUSED_VAR(flags);
UNUSED_VAR(width);
UNUSED_VAR(precision);
UNUSED_VAR(size);
y = va_arg(list, unsigned int);
m = 2147483648; /* (2 ^ 31) */
a[0] = y / m;
for (x = 1; x < 32; x++)
{
m /= 2;
a[x] = (y / m) % 2;
}
for (x = 0, sum = 0, cnt = 0; x < 32; x++)
{
sum += a[x];
if (sum || x == 31)
{
z = '0' + a[x];
write(1, &z, 1);
cnt++;
}
}
return (cnt);
}
