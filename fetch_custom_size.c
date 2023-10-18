#include "main.h"

/**
 * fetch_custom_size - Determine the size specifier for an argument.
 * @format: The format string to analyze.
 * @index: The current index in the format string.
 *
 * Return: The argument size.
 */
int fetch_custom_size(const char *format, int *index)
{
int new_index = *index + 1;
int s = 0;
if (format[new_index] == 'l')
s = SIZE_LONG;
else if (format[new_index] == 'h')
s = SIZE_SHORT;
if (s == 0)
*index = new_index - 1;
else
*index = new_index;
return (s);
}
