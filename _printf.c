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
int ret;
va_list ap;
va_start(ap, format);
ret = vfprintf(stdout, format, ap);
va_end(ap);
return (ret);
}
