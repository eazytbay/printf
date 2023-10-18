#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED_VAR(x) (void)(x)
#define BUFFER_SIZE 1024

/* FLAGS */
#define FLAG_MINUS 1
#define FLAG_PLUS 2
#define FLAG_ZERO 4
#define FLAG_HASH 8
#define FLAG_SPACE 16

/* SIZES */
#define SIZE_LONG 2
#define SIZE_SHORT 1

/**
 * struct format_specifier - Structure to represent a format specifier.
 *
 * @specifier: The format specifier character.
 * @function: The function associated with the specifier.
 */
struct format_specifier
{
char specifier;
int (*function)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct format_specifier format_specifier_t - Typedef
 * for the format_specifier structure.
 *
 * @specifier: The format specifier character.
 * @function: The function associated with the specifier.
 */
typedef struct format_specifier format_specifier_t;

int _printf(const char *format, ...);
int handle_print_format(const char *fmt, int *index, va_list args,
char buffer[], int flags, int width, int precision, int size);


int gen_custom_char(va_list args, char buffer[], int flags,
int width, int precision, int size);
int gen_custom_string(va_list args, char buffer[], int flags,
int width, int precision, int size);
int gen_custom_percent(va_list args, char buffer[], int flags,
int width, int precision, int size);

int gen_custom_int(va_list args, char buffer[], int flags,
int width, int precision, int size);
int gen_custom_binary(va_list args, char buffer[], int flags,
int width, int precision, int size);
int gen_custom_unsigned(va_list args, char buffer[], int flags,
int width, int precision, int size);
int gen_custom_octal(va_list args, char buffer[], int flags,
int width, int precision, int size);
int gen_custom_hexadecimal(va_list args, char buffer[], int flags,
int width, int precision, int size);
int gen_custom_upper_hexa(va_list args, char buffer[], int flags,
int width, int precision, int size);

int gen_custom_hexa(va_list args, char map_to[], char buffer[], int flags,
char flag_ch, int width, int precision, int size);

int gen_custom_non_printable(va_list args, char buffer[], int flags,
int width, int precision, int size);

int gen_custom_pointer(va_list args, char buffer[], int flags,
int width, int precision, int size);

int fetch_custom_flags(const char *format, int *index);
int fetch_custom_width(const char *format, int *index, va_list args);
int fetch_custom_precision(const char *format, int *index, va_list args);
int fetch_custom_size(const char *format, int *index);

int gen_custom_reverse(va_list args, char buffer[], int flags,
int width, int precision, int size);

int gen_custom_rot13string(va_list args, char buffer[], int flags,
int width, int precision, int size);

int add_custom_char(char character, char buffer[], int flags,
int width, int precision, int size);
int add_custom_number(int is_postive, int index, char buffer[], int flags,
int width, int precision, int size);
int add_custom_num(int index, char buffer[], int flags, int width,
int precision, int length, char padding, char extra_char);
int add_custom_pointer(char buffer[], int index, int length,
int width, int flags, char padding, char extra_char, int padding_start);
int add_custom_unsined(int is_negative, int index, char buffer[], int flags,
int width, int precision, int size);

int custom_print(char character);
int add_custom_hexa_code(char c, char buffer[], int index);
int custom_digit(char character);

long int change_custom_numsize(long int num, int size);
long int change_customsize_unsined(unsigned long int num, int size);

#endif /* MAIN_H */
