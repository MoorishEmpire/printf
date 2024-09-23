#include "main.h"
#include <unistd.h>

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


