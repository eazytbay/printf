#include "main.h"

/**
 * fetch_custom_flags -A function that Calculates format flags that are active
 * @format_string: Format string with potential flags.
 * @index: Current index in the format string.
 * Return: The calculated flags.
 */
int fetch_custom_flags(const char *format_string, int *index)
{
char flag_chars[] = {'-', '+', '0', '#', ' ', '\0'};
int flag_values[] = {FLAG_MINUS, FLAG_PLUS, FLAG_ZERO,
FLAG_HASH, FLAG_SPACE, 0};
int flags = 0;
int current_index = *index + 1;
int x, flag_found;
while (format_string[current_index] != '\0')
{
x = 0;
flag_found = 0;
while (flag_chars[x] != '\0')
{
if (format_string[current_index] == flag_chars[x])
{
flags |= flag_values[x];
flag_found = 1;
break;
}
x++;
}
if (!flag_found)
{
break;
}
current_index++;
}
*index = current_index - 1;
return (flags);
}
