#include <stdarg.h>
#include <stdio.h>
/**
 * _printf - function that produces output according to a format.
 * @format: param
 * @...: param
 * Return: int
*/
int _printf(const char *format, ...)
{
int ret;
va_list args;
va_start(args, format);
ret = vfprintf(stdout, format, args);
va_end(args);
return (ret);
}
