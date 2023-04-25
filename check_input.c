#include "main.h"

/**
 * check_input - check format and arg according requirements.
 * @format: string holding characters and format of arguments to be checked.
 * @original: original list of arguments
 * Return: (0) success, (2) error
 */

int check_input(const char *format, va_list *original)
{
	int i = 0, n_printed = 0;

	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;

			if (format[i] == '%')
			{
				i++;
			}
			else if (format[i]) /* correct format spec? */
			{
				check_for_format(format[i], original, 0, &n_printed);
			}
			else /* error "%" */
			{
				return (1);
			}
		}

		i++;
	}
	return (0);
}
