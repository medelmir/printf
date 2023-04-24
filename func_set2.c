
#include "main.h"

/**
 * print_pointer - a function that prints the value of a pointer
 * @a_types: the arguments list
 * @buffer: the array to hold print
 * @flags: compute active flags characters
 * @width: fetch field width
 * @precision: precision parameters
 * @size: size type
 *
 * Return: the number of chars
*/
int print_pointer(va_list a_types, char buffer[],
	int flags, int width, int precision, int size)
{
	char extra_ch = 0, padd = ' ';
	int i = BUFF_SIZE - 2, len = 2, padd_start = 1; /* length=2, for '0x' */
	unsigned long n_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(a_types, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == 0)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	n_addrs = (unsigned long)addrs;

	while (n_addrs > 0)
	{
		buffer[i--] = map_to[n_addrs % 16];
		n_addrs /= 16;
		len++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		extra_ch = '+', len++;
	else if (flags & F_SPACE)
		extra_ch = ' ', len++;

	i++;

	return (write_pointer(buffer, i, len,
		width, flags, padd, extra_ch, padd_start));
}

/**
 * print_non_printable - a function that prints ascii codes
 * in hexadecimal of non printable characters
 * @a_types: the arguments list
 * @buffer: the array to hold print
 * @flags: compute active flags characters
 * @width: fetch field width
 * @precision: precision parameters
 * @size: size type
 *
 * Return: the number of chars
*/

int print_non_printable(va_list a_types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = 0, offset = 0;
	char *str;

	str = va_arg(a_types, char*);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == 0)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (is_printable(str[i]))
			buffer[i + offset] = str[i];
		else
			offset += append_hexa_code(str[i], buffer, i + offset);

		i++;
	}

	buffer[i + offset] = '\0';

	return (write(1, buffer, i + offset));
}

/**
 * print_reverse - a function that prints a string in reverse
 * @a_types: the arguments list
 * @buffer: the array to hold print
 * @flags: compute active flags characters
 * @width: fetch field width
 * @precision: precision parameters
 * @size: size type
 *
 * Return: the number of chars
*/

int print_reverse(va_list a_types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str;
	int i, y = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(a_types, char *);

	if (str == 0)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (i = 0; str[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &z, 1);
		y++;
	}
	return (y);
}

/**
 * print_rot13string - a function that prints a string
 * in ROT13 using letter substitution
 * @a_types: the arguments list
 * @buffer: the array to hold print
 * @flags: compute active flags characters
 * @width: fetch field width
 * @precision: precision parameters
 * @size: size type
 *
 * Return: the number of chars
*/

int print_rot13string(va_list a_types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int i, j;
	int y = 0;
	char x;
	char *str;
	char input[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char output[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(a_types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == 0)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; input[j]; j++)
		{
			if (input[j] == str[i])
			{
				x = output[j];
				write(1, &x, 1);
				y++;
				break;
			}
		}
		if (!input[j])
		{
			x = str[i];
			write(1, &x, 1);
			y++;
		}
	}
	return (y);
}
