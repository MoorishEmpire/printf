#include "main.h"

/**
  * _print_int - Converts an integer to string and prints it.
  * @n: The integer to be printed.
  *
  * Return: Number of characters printed.
  */
int	_print_int(int n)
{
	int	count = 0;
	char	buffer[20];
	int	i;
	unsigned int	num;

	i = 0;
	if (n < 0)
	{
		count += _print_char('-');
		num = -n;
	}
	else
	{
		num = n;
	}

	if (num == 0)
	{
		buffer[i++] = '0';
	}
	else
	{
		while (num > 0)
		{
			buffer[i++] = (num % 10) + '0';
			num /= 10;
		}
	}

	while (i > 0)
	{
		count += _print_char(buffer[--i]);
	}

	return (count);
}
