#include <stdarg.h>
#include <stdio.h>
#include <string.h>
/**
 * print_string - print a string
 * @str: the string to print
 *
 * Return: the number of characters printed
 */
int print_strings(char *str)
{
int i, count = 0;
if (str == NULL)
str = "(null)";
for (i = 0; str[i] != '\0'; i++)
{
if (str[i] == '\n')
{
putchar('\n');
putchar('\r');
}
else
	putchar(str[i]);

   count++;
}
 return (count);
}
