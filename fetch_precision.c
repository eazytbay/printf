#include "main.h"
/**
 * fetch_custom_precision - Determine the precision for printing
 * @format_string: Formatted string containing arguments
 * @index: Current index in the format string
 * @arg_list: List of arguments
 *
 * Return: Calculated precision value.
 */
int fetch_custom_precision(const char *format_string,
int *index, va_list arg_list)
{
int current_index = *index + 1;
int precision = -1;
if (format_string[current_index] != '.')
return (precision);
precision = 0;
while (format_string[current_index] != '\0')
{
if (custom_digit(format_string[current_index]))
{
precision *= 10;
precision += format_string[current_index] - '0';
}
else if (format_string[current_index] == '*')
{
current_index++;
precision = va_arg(arg_list, int);
break;
}
else
{
break;
}
current_index++;
}
*index = current_index - 1;
return (precision);
}
