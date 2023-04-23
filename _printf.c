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
char buffer[1024];
va_list args;
va_start(args, format);
ret = vsprintf(buffer, format, args);
va_end(args);
fputs(buffer, stdout);
return (ret);
}
