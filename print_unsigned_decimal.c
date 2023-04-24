#include <stdarg.h>
#include <stdio.h>
#include <string.h>
/**
 * print_unsigned_decimal - print decimal
 * @num: param
 * Return: int
*/
int print_unsigned_decimal(unsigned int num)
{
int ret = 0;
if (num >= 10)
ret += print_unsigned_decimal(num / 10);
putchar('0' + num % 10);
ret++;
return (ret);
}

