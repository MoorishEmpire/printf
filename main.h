#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>


int	_printf(const char *fomart, ...);
int	_print_format(char specefier, va_list ap);
int	_print_str(char *str);
int	_print_char(char c);

#endif
