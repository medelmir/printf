#include <stdarg.h>
#include <stdio.h>
#include <string.h>
/**
 * print_hexadecimal - print hexadecimal number
 * @num: param
 * @uppercase: param
 * Return: int
*/
int print_hexadecimal(unsigned int num, int uppercase)
{
int ret = 0;
if (num > 15)
ret += print_hexadecimal(num / 16, uppercase);
if (num % 16 < 10)
putchar('0' + num % 16);
else if (uppercase)
putchar('A' + (num % 16 - 10));
else
putchar('a' + (num % 16 - 10));
ret++;
return (ret);
}

