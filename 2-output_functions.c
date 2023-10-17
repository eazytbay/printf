#include "main.h"
/**
 * gen_custom_pointer - Prints the value of a pointer variable
 * @types: List of arguments
 * @buffer: Buffer array for printing
 * @flags: Active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters printed
 */
int gen_custom_pointer(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
char extra_char = 0, padding_char = ' ';
int index = BUFFER_SIZE - 2, length = 2, padding_start
= 1; /* Length=2 for '0x' */
unsigned long address;
char map_to[] = "0123456789abcdef";
void *ptr = va_arg(types, void *);
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
 * gen_custom_non_printable - Prints ASCII codes in
 * hexadecimal of non-printable characters
 * @types: List of arguments
 * @buffer: Buffer array for printing
 * @flags: Active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters printed
 */
int gen_custom_non_printable(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int i = 0, offset = 0;
char *str = va_arg(types, char *);
UNUSED_VAR(flags);
UNUSED_VAR(width);
UNUSED_VAR(precision);
UNUSED_VAR(size);
if (str == NULL)
return (write(1, "(null)", 6));
while (str[i] != '\0')
{
if (custom_print(str[i]))
buffer[i + offset] = str[i];
else
offset += add_custom_hexa_code(str[i], buffer, i + offset);
i++;
}
buffer[i + offset] = '\0';
return (write(1, buffer, i + offset));
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
char *str;
int i, count = 0;
UNUSED_VAR(buffer);
UNUSED_VAR(flags);
UNUSED_VAR(width);
UNUSED_VAR(size);
str = va_arg(types, char *);
if (str == NULL)
{
UNUSED_VAR(precision);
str = ")Null(";
}
for (i = 0; str[i]; i++)
;
for (i = i - 1; i >= 0; i--)
{
char character = str[i];
write(1, &character, 1);
count++;
}
return (count);
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
