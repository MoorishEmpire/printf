#include "main.h"

/**
  * _print_char - Prints a character to stdout
  * @c: The character to print.
  *
  * Return: Number of characters printed.
  */
int	_print_char(char c)
{
	return (write(1, &c, 1));
}

/**
  * _print_str - Prints a string to stdout.
  * @str: The string to print.
  *
  * Return: Number of characters printed.
  */
int	_print_str(char *str)
{
	int count;

	count = 0;
	while (str && *str)
	{
		_print_char(*str++);
		count++;
	}
	return (count);
}
int	_print_format(char specifier, va_list args)
{
	int	count;

	count = 0;
	if (specifier == 'c')
	{
		count += _print_char(va_arg(args, int));
	}
	else if (specifier == 's')
	{
		count += _print_str(va_arg(args, char *));
	}
	else if (specifier == '%')
	{
		count += _print_char('%');
	}
	else
	{
		count += _print_char('%');
		count += _print_char(specifier);
	}
	return (count);
}

int	_printf(const char *format, ...)
{
	va_list args;
	int	count;

	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += _print_format(*format, args);
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



