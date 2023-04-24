
#include "main.h"

/**
* print_unsigned - a function that prints an unsigned number
* @a_types: the arguments list
* @buffer: the array to hold print
* @flags: compute active flags characters
* @width: fetch field width
* @precision: precision parameters
* @size: size type
*
* Return: the number of chars
*/

int print_unsigned(va_list a_types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int numb = va_arg(a_types, unsigned long int);

	numb = convert_size_unsgnd(numb, size);

	if (numb == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (numb > 0)
	{
		buffer[i--] = (numb % 10) + '0';
		numb /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/**
* print_octal - a function that prints an unsigned number in octal
* @a_types: the arguments list
* @buffer: the array to hold print
* @flags: compute active flags characters
* @width: fetch field width
* @precision: precision parameters
* @size: size type
*
* Return: the number of chars
*/

int print_octal(va_list a_types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int numb = va_arg(a_types, unsigned long int);
	unsigned long int init_numb = numb;

	UNUSED(width);

	numb = convert_size_unsgnd(numb, size);

	if (numb == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (numb > 0)
	{
		buffer[i--] = (numb % 8) + '0';
		numb /= 8;
	}

	if (flags & F_HASH && init_numb != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/**
* print_hexadecimal - a function that prints an unsigned number in hexadecimal
* @a_types: the arguments list
* @buffer: the array to hold print
* @flags: compute active flags characters
* @width: fetch field width
* @precision: precision parameters
* @size: size type
*
* Return: the number of chars
*/

int print_hexadecimal(va_list a_types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(a_types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/**
* print_hexa_upper - a function that prints an unsigned number in hexadecimal
* in uppercase
* @a_types: the arguments list
* @buffer: the array to hold print
* @flags: compute active flags characters
* @width: fetch field width
* @precision: precision parameters
* @size: size type
*
* Return: the number of chars
*/

int print_hexa_upper(va_list a_types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(a_types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/**
* print_hexadecimal - a function that prints an unsigned number in hexadecimal
* in upper or lowercase
* @a_types: the arguments list
* @map_to: the array of value maping the number
* @buffer: the array to hold print
* @flags: compute active flags characters
* @flag_ch: compute active flags characters
* @width: fetch field width
* @precision: precision parameters
* @size: size type
*
* Return: the number of chars
*/

int print_hexa(va_list a_types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int numb = va_arg(a_types, unsigned long int);
	unsigned long int init_numb = numb;

	UNUSED(width);

	numb = convert_size_unsgnd(numb, size);

	if (numb == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (numb > 0)
	{
		buffer[i--] = map_to[numb % 16];
		numb /= 16;
	}

	if (flags & F_HASH && init_numb != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
