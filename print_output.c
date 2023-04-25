#include "main.h"
/**
 * print_output - prints according to the check_input status
 * @format: string holding characters and format of arguments to be checked.
 * @copy: copy of the list of arguments
 * Return: number of charaters printed.
 */

int print_output(const char *format, va_list *copy)
{

	int i = 0, n_printed = 0;

	while (format[i])
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			n_printed = n_printed + 1;
		}

		if (format[i] == '%')
		{
			i++;
			if (format[i] == '%')
			{
				_putchar('%');
				n_printed = n_printed + 1;
			}
			else
			{
				if (check_for_format(format[i], copy, 1, &n_printed))
				{
					_putchar('%');
					_putchar(format[i]);
					n_printed = n_printed + 2;
				}
			}
		}
		if (format[i] != '\0')
			i++;
	}

	return (n_printed);
}
