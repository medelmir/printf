#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include "main.h"
/**
 * _printf - print function
 * @format: param
 * @...: param
 * Return: int
*/
int _printf(const char *format, ...)
{
int ret = 0;
va_list ap;
char *p;
char *str;
unsigned int i;
char c;
if (format == NULL)
return (-1);
va_start(ap, format);
for (p = (char *)format; *p != '\0'; p++)
{
if (*p != '%')
{
putchar(*p);
ret++;
continue;
}
p++;
 if (*p == '\0')
{
ret = -1;
break;
}
switch (*p)
{
case 'b':
i = va_arg(ap, unsigned int);
ret += print_binary(i);
break;
case 'u':
i = va_arg(ap, unsigned int);
ret += print_unsigned_decimal(i);
break;
case 'o':
i = va_arg(ap, unsigned int);
ret += print_octal(i);
break;
case 'x':
i = va_arg(ap, unsigned int);
ret += print_hexadecimal(i, 0);
break;
case 'X':
i = va_arg(ap, unsigned int);
ret += print_hexadecimal(i, 1);
break;
case 'c':
c = (char) va_arg(ap, int);
ret += print_char(c);
break;
case 'S':
str = va_arg(ap, char *);
ret += print_string(str);
break;
case 's':
str =  va_arg(ap, char *);
ret += print_strings(str);
break;
default:
putchar('%');
putchar(*p);
ret += 2;
break;
}
}
va_end(ap);
return (ret);
}

