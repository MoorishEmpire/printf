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

	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
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

