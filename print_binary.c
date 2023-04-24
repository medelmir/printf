#include <stdarg.h>
#include <stdio.h>
#include <string.h>
/**
 * print_binary - print binary number
 * @num: param
 * Return: int
*/
int print_binary(unsigned int num)
{
int ret = 0;
if (num > 1)
ret += print_binary(num / 2);
putchar('0' + num % 2);
ret++;
return (ret);
}

