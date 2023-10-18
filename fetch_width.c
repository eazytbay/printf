#include "main.h"

/**
 * fetch_custom_width - A function that Determines the width for printing
 * @format_string: Format string with potential width specification.
 * @index: Current index in the format string.
 * @arguments: arguments list
 *
 * Return: The determined or calculated width.
 */
int fetch_custom_width(const char *format_string,
int *index, va_list arguments)
{
int current_index = *index + 1;
int w = 0;
while (format_string[current_index] != '\0')
{
if (custom_digit(format_string[current_index]))
{
w *= 10;
w += format_string[current_index] - '0';
}
else if (format_string[current_index] == '*')
{
current_index++;
w = va_arg(arguments, int);
break;
}
else
{
break;
}
current_index++;
}
*index = current_index - 1;
return (w);
}
