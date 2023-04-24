#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
int _printf(const char *format, ...);
int print_char(char c);
int print_binary(unsigned int num);
int print_hexadecimal(unsigned int num, int uppercase);
int print_unsigned_decimal(unsigned int num);
int print_string(char *str);
int print_octal(unsigned int num);
int print_strings(char *str);
#endif /* MAIN_H */

