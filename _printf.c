#include <stdarg.h>
#include <stdio.h>
#include <string.h>
/**
 * _printf - function that produces output according to a format.
 * @format: param
 * @...: param
 * Return: int
 */
int _printf(const char *format, ...)
{
int ret = 0;
int i = 0;
va_list args;
va_start(args, format);
do {
i++;
} while (format[i] != '%');
if (format[i + 1] == 'c' || format[i + 1 == 's'])
{
ret = vprintf(format, args);
va_end(args);
return (ret);
}
return (0);
}
