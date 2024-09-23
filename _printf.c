#include "main.h"

int	_print_char(char c)
{
	return (write(1, &c, 1));
}

int	_print_str(char *str)
{
	int count;

	count = 0;
	while (*str)
	{
		_print_char(*str++);
		count++;
	}
	return (count);
}

int	_print_format(char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += _print_char(va_arg(ap, int));
	else if (specifier == 's')
		count += _print_str(va_arg(ap, char *));
	else
		count += write(1, &specifier, 1);
	return (count);
}

int	_printf(const char *format, ...)
{
	va_list ap;
	int	count;

	va_start(ap, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
			count += _print_format(*(++format), ap);
		else
			count += write(1, format, 1);
		format++;
	}

	return (count);
}



