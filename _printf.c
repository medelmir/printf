#include <stdarg.h>
#include <stdio.h>
#include <string.h>
/**
 * _printf - function that produces output according to a format.
 * @format: param
 * @...: param
 * Return: int
 */
char _printf(const char *format, ...)
{
int ret;
int i = 0;
char buffer[1024];
va_list args;
va_start(args, format);
if (format == NULL)
return (-1);
else
{
while (format != NULL)
{
if (format[i] == '%')
{
if (format[i + 1] == 'c' || format[i + 1] == 's')
{
vsprintf(buffer, format, args);
ret = fputs(buffer, stdout);
va_end(args);
return (ret);
}
}
i++;
}
}
return (0);
}
