#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>


/**
  * _printf - Produces output according to a format.
  * @format: The fromat string.
  *
  * Return: The number of characters printed.
  */
int	_printf(const char *format, ...)
{
	va_list args;
	int	count;

	if (!format)
		return (-1);

	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
			{
				return (-1);
			}
			else if (*format == 'c')
			{
				count += _print_char(va_arg(args, int));
			}
			else if (*format == 's')
			{
				count += _print_str(va_arg(args, char *));
			}
			else if (*format == '%')
			{
				count += _print_char('%');
			}
			else
			{
				count += _print_char('%');
				count += _print_char(*format);
			}
		}
		else
		{
			count += _print_char(*format);
		}
		format++;
	}

	va_end(args);
	return (count);
}

