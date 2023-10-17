#include "main.h"

/**
 * handle_print_format - A function that Prints a custom argument
 * @format_string: Format string with potential format specifiers.
 * @index: Current index in the format string.
 * @arguments: List of arguments to be printed.
 * @output_buffer: Buffer array to handle the print.
 * @format_flags: Active format flags.
 * @format_width: specified width.
 * @format_precision: specified precision.
 * @format_size: specified size.
 * Return: The number of characters printed, or -1 in case of an error.
 */
int handle_print_format(const char *format_string, int *index,
va_list arguments, char output_buffer[],
int format_flags, int format_width, int format_precision, int format_size)
{
int x, unknow_length = 0, pc = -1;
	format_specifier_t format_specifiers[] = {
		{'c', gen_custom_char}, {'s', gen_custom_string}, {'%', gen_custom_percent},
		{'i', gen_custom_int}, {'d', gen_custom_int}, {'b', gen_custom_binary},
		{'u', gen_custom_unsigned}, {'o', gen_custom_octal},
		{'x', gen_custom_hexadecimal},
		{'X', gen_custom_upper_hexa}, {'p', gen_custom_pointer},
		{'S', gen_custom_non_printable},
		{'r', gen_custom_reverse}, {'R', gen_custom_rot13string}, {'\0', NULL}
	};
	for (x = 0; format_specifiers[x].specifier != '\0'; x++)
		if (format_string[*index] == format_specifiers[x].specifier)
			return (format_specifiers[x].function(arguments, output_buffer,
					format_flags, format_width, format_precision, format_size));

	if (format_specifiers[x].specifier == '\0')
	{
		if (format_string[*index] == '\0')
			return (-1);
		unknow_length += write(1, "%%", 1);
		if (format_string[*index - 1] == ' ')
			unknow_length += write(1, " ", 1);
		else if (format_width)
		{
			--(*index);
			while (format_string[*index] != ' ' && format_string[*index] != '%')
				--(*index);
			if (format_string[*index] == ' ')
				--(*index);
			return (1);
		}
		unknow_length += write(1, &format_string[*index], 1);
		return (unknow_length);
	}
	return (pc);
}
