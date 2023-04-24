#include <stdarg.h>
#include <stdio.h>
#include <string.h>
/**
 * print_string - print string
 * @str: param
 * Return: int
*/
int print_string(char *str)
{
int ret = 0;
int i;
if (!str)
{
ret += print_string("(null)");
return (ret);
}
for (i = 0; str[i] != '\0'; i++)
{
if (str[i] >= ' ' && str[i] < 127)
{
putchar(str[i]);
ret++;
}
else
{
putchar('\\');
putchar('x');
putchar("0123456789ABCDEF"[str[i] / 16]);
putchar("0123456789ABCDEF"[str[i] % 16]);
ret += 4;
}
}
return (ret);
}

