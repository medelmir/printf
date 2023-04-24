#include <stdarg.h>
#include <stdio.h>
#include <string.h>
/**
 * print_octal - print octal number
 * @num : param
 * Return: int
*/
int print_octal(unsigned int num)
{
int ret = 0;
if (num > 7)
ret += print_octal(num / 8);
putchar('0' + num % 8);
ret++;
return (ret);
}

