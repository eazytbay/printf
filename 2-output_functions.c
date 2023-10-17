#include "main.h"
/**
 * gen_custom_pointer -A function that displays the value of a pointer variable
 * @args: List of arguments
 * @buffer: Buffer array for printing
 * @flags: Active flags
 * @width: Width
 * @precision: specified precision
 * @size: specified size
 * Return: Number of characters printed
 */
int gen_custom_pointer(va_list args, char buffer[], int flags,
int width, int precision, int size)
{
char extra_char = 0, padding_char = ' ';
int index = BUFFER_SIZE - 2, length = 2, padding_start
= 1; /* Length=2 for '0x' */
unsigned long address;
char map_to[] = "0123456789abcdef";
void *ptr = va_arg(args, void *);
UNUSED_VAR(width);
UNUSED_VAR(size);
if (ptr == NULL)
return (write(1, "(nil)", 5));
buffer[BUFFER_SIZE - 1] = '\0';
UNUSED_VAR(precision);
address = (unsigned long)ptr;
while (address > 0)
{
buffer[index--] = map_to[address % 16];
address /= 16;
length++;
}
if ((flags & FLAG_ZERO) && !(flags & FLAG_MINUS))
padding_char = '0';
if (flags & FLAG_PLUS)
extra_char = '+', length++;
else if (flags & FLAG_SPACE)
extra_char = ' ', length++;
index++;
return (add_custom_pointer(buffer, index, length,
width, flags, padding_char, extra_char, padding_start));
}
/**
 * gen_custom_non_printable -  A function that Prints ASCII codes in
 * hexadecimal of non-printable characters
 * @types: List of arguments
 * @buffer: Buffer array for printing
 * @flags: Active flags
 * @width: Width
 * @precision: specified precision
 * @size: specified size
 * Return: Total printed characters
 */
int gen_custom_non_printable(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int x = 0, o = 0;
char *ptr = va_arg(types, char *);
UNUSED_VAR(flags);
UNUSED_VAR(width);
UNUSED_VAR(precision);
UNUSED_VAR(size);
if (ptr == NULL)
return (write(1, "(null)", 6));
while (ptr[x] != '\0')
{
if (custom_print(ptr[x]))
buffer[x + o] = ptr[x];
else
o += add_custom_hexa_code(ptr[x], buffer, x + o);
x++;
}
buffer[x + o] = '\0';
return (write(1, buffer, x + o));
}
/**
 * gen_custom_reverse - Prints a reversed string.
 * @types: List of arguments
 * @buffer: Buffer array for printing
 * @flags: Active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters printed
 */
int gen_custom_reverse(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
char *ptr;
int x, cnt = 0;
UNUSED_VAR(buffer);
UNUSED_VAR(flags);
UNUSED_VAR(width);
UNUSED_VAR(size);
ptr = va_arg(types, char *);
if (ptr == NULL)
{
UNUSED_VAR(precision);
ptr = ")Null(";
}
for (x = 0; ptr[x]; x++)
;
for (x = x - 1; x >= 0; x--)
{
char character = ptr[x];
write(1, &character, 1);
cnt++;
}
return (cnt);
}
/**
 * gen_custom_rot13string - A function that Print a string in ROT13.
 * @types: List of arguments
 * @buffer: Buffer array for printing
 * @flags: Active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters printed
 */
int gen_custom_rot13string(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
char x;
char *str;
unsigned int a, b;
int cnt = 0;
char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
str = va_arg(types, char *);
UNUSED_VAR(buffer);
UNUSED_VAR(flags);
UNUSED_VAR(width);
UNUSED_VAR(precision);
UNUSED_VAR(size);
if (str == NULL)
str = "(AHYY)";
for (a = 0; str[a]; a++)
{
for (b = 0; in[b]; b++)
{
if (in[b] == str[a])
{
x = out[b];
write(1, &x, 1);
cnt++;
break;
}
}
if (!in[b])
{
x = str[a];
write(1, &x, 1);
cnt++;
}
}
return (cnt);
}
