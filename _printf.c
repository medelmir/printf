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
va_list args;
int i;
va_start(args, format);
for (i = 0; format[i] != '\0'; i++)
{
if (format[i] == '%')
{
i++;
switch (format[i])
{
case 'c':
ret += putchar(va_arg(args, int));
break;
case 's':
ret += puts(va_arg(args, char *));
break;
case '%':
ret += putchar('%');
break;
default:
ret += putchar('%');
ret += putchar(format[i]);
break;
}
}
else
{
ret += putchar(format[i]);
}
}
va_end(args);
return (ret);
}
