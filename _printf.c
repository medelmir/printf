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
char buffer[1024];
va_list args;
va_start(args, format);
if (format == NULL)
return (-1);
else
{
vsprintf(buffer, format, args);
ret = fputs(buffer, stdout);
va_end(args);
return (ret);
}
