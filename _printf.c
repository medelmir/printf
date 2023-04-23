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
int count  = 0;
char *s;
va_list args;
va_start(args, format);
if (format == NULL)
return (-1);
for (; *format; format++)
{
if (*format == '%' && *++format == '\0')
return (-1);
if (*format == '%')
switch (*++format)
{
case 'c':
putchar(va_arg(args, int));
count++;
break;
case 's':
for (s = va_arg(args, char *); *s; s++)
{
putchar(*s);
count++;
}
break;
case '%':
putchar('%');
count++;
break;
}
else
{
putchar(*format);
count++;
}
}
va_end(args);
return (count);
}
