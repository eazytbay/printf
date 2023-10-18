#include "main.h"

void clear_output_buffer(char output_buffer[], int *buffer_index);

/**
 * _printf - Customized Printf function
 * @format_string: The format string.
 * Return: The number of characters printed.
 */
int _printf(const char *format_string, ...)
{
int format_index = 0, characters_printed = 0;
int format_flags, format_width, format_precision,
format_size, buffer_index = 0;
va_list arguments;
int printed_chars;
char output_buffer[BUFFER_SIZE];
if (format_string == NULL)
return (-1);
va_start(arguments, format_string);
while (format_string[format_index] != '\0')
{
if (format_string[format_index] != '%')
{
output_buffer[buffer_index++] = format_string[format_index];
if (buffer_index == BUFFER_SIZE)
clear_output_buffer(output_buffer, &buffer_index);
characters_printed++;
format_index++;
}
else
{
clear_output_buffer(output_buffer, &buffer_index);
format_flags = fetch_custom_flags(format_string, &format_index);
format_width = fetch_custom_width(format_string, &format_index, arguments);
format_precision = fetch_custom_precision
(format_string, &format_index, arguments);
format_size = fetch_custom_size(format_string, &format_index);
format_index++;
printed_chars = handle_print_format(format_string, &format_index,
arguments, output_buffer, format_flags, format_width,
format_precision, format_size);
if (printed_chars == -1)
return (-1);
characters_printed += printed_chars;
}
}
clear_output_buffer(output_buffer, &buffer_index);
va_end(arguments);
return (characters_printed);
}

/**
 * clear_output_buffer - Prints the contents of the output buffer if it exists
 * @output_buffer: Array of characters.
 * @buffer_index: Index at which to add the next character,
 * representing the buffer length.
 */
void clear_output_buffer(char output_buffer[], int *buffer_index)
{
if (*buffer_index > 0)
{
write(1, &output_buffer[0], *buffer_index);
}
*buffer_index = 0;
}

