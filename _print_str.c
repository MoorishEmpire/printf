#include "main.h"
#include <stdlib.h>

/**
  * _print_str - Prints a string to stdout.
  * @str: The string to print.
  *
  * Return: Number of characters printed.
  */
int	_print_str(char *str)
{
	int count;

	if (!str)
		str = "(null)";
	count = 0;
	while (*str)
	{
		_print_char(*str++);
		count++;
	}
	return (count);
}


