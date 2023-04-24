
#include "main.h"

/**
* print_string - a function that prints a char
* @a_types: the arguments list
* @buffer: the array to hold print
* @flags: compute active flags characters
* @width: fetch field width
* @precision: precision parameters
* @size: size type
*
* Return: the number of chars
*/

int print_char(va_list a_types, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(a_types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}

/**
* print_string - a function that prints a string
* @a_types: the arguments list
* @buffer: the array to hold print
* @flags: compute active flags characters
* @width: fetch field width
* @precision: precision parameters
* @size: size type
*
* Return: the number of chars
*/

int print_string(va_list a_types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i, len = 0;
	char *str = va_arg(a_types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == 0)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[len] != '\0')
		len++;

	if (precision >= 0 && precision < len)
		len = precision;

	if (width > len)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], len);
			for (i = width - len; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - len; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], len);
			return (width);
		}
	}

	return (write(1, str, len));
}

/**
* print_percent - a function that prints a percent sign
* @a_types: the arguments list
* @buffer: the array to hold print
* @flags: compute active flags characters
* @width: fetch field width
* @precision: precision parameters
* @size: size type
*
* Return: the number of chars
*/

int print_percent(va_list a_types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(a_types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/**
* print_int - a function that prints an integer
* @a_types: the arguments list
* @buffer: the array to hold print
* @flags: compute active flags characters
* @width: fetch field width
* @precision: precision parameters
* @size: size type
*
* Return: the number of chars
*/

int print_int(va_list a_types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(a_types, long int);
	unsigned long int numb;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	numb = (unsigned long int)n;

	if (n < 0)
	{
		numb = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (numb > 0)
	{
		buffer[i--] = (numb % 10) + '0';
		numb /= 10;
	}

	i++;

	return (write_number(is_negative, i, buffer, flags, width, precision, size));
}

/**
* print_binary - a function that prints an unsigned number in binary
* @a_types: the arguments list
* @buffer: the array to hold print
* @flags: compute active flags characters
* @width: fetch field width
* @precision: precision parameters
* @size: size type
*
* Return: the number of chars
*/
int print_binary(va_list a_types, char buffer[],
	 int flags, int width, int precision, int size)
{
	unsigned int n, max, i, total;
	unsigned int bnum[32];
	int y;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	n = va_arg(a_types, unsigned int);
	max = 2147483648;
	bnum[0] = n / max;
	for (i = 1; i < 32; i++)
	{
		max /= 2;
		bnum[i] = (n / max) % 2;
	}
	for (i = 0, total = 0, y = 0; i < 32; i++)
	{
		total += bnum[i];
		if (total || i == 31)
		{
			char z = '0' + bnum[i];

			write(1, &z, 1);
			y++;
		}
	}
	return (y);
}
