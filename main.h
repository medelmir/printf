#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

/* unused macro */
#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* Flags macro */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* Sizes types macro */
#define S_LONG 2
#define S_SHORT 1

/* functions structure */

/**
 * struct fmt - Struct op
 *
 * @fmt: the format(char variable)
 * @fn: the function associated
 */

struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: the format(char variable)
 * @fm_t: the function associated
 */
typedef struct fmt fmt_t;


/* Functions prototypes */
int _printf(const char *format, ...);

/* Funtions prototypes that handles the chars and string */
int print_char(va_list a_types, char buffer[],
	int flags, int width, int precision, int size);
int print_string(va_list a_types, char buffer[],
	int flags, int width, int precision, int size);
int print_percent(va_list a_types, char buffer[],
	int flags, int width, int precision, int size);

/* Functions prototypes that handles the numbers */
int print_int(va_list a_types, char buffer[],
	int flags, int width, int precision, int size);
int print_binary(va_list a_types, char buffer[],
	int flags, int width, int precision, int size);
int print_unsigned(va_list a_types, char buffer[],
	int flags, int width, int precision, int size);
int print_octal(va_list a_types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexadecimal(va_list a_types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexa_upper(va_list a_types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexa(va_list a_types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);

/* Function prototype that handles the memory address */
int print_pointer(va_list a_types, char buffer[],
	int flags, int width, int precision, int size);

/* Function prototype that handles string in reverse */
int print_reverse(va_list a_types, char buffer[],
	int flags, int width, int precision, int size);

/* Function prototype that handles rot 13 */
int print_rot13string(va_list a_types, char buffer[],
	int flags, int width, int precision, int size);

#endif
