#include "ft_printf.h"

void	function move address of fmt by given length(const char **fmt, int length)
{
	(*fmt) += length;
}

void	function set minimum field width
{
	set flag;
	set width;
	set precision;
	set type;
}



void	function set priority
{
	get num = number of bit on;

	priority = num + 1;
	function print argument priority = priority;
	
	if minus bit on
		priority = function print argument priority + 1;
		function print space priority = priority;
	if zero bit on
		priority = function print space priority + 1;
		function print zero priority = priority;
	if pointer bit on || sharp bit on
		priority = function print argument priority - 1;
		function print 0x10 priority = priority;
	if plus bit on
		priority = function print argument priority - 1;
		function print sign priority = priority;
	if space bit on
		priority = FIRST;
		function print 1 space priority = priority;
	
}

void	function insert to heap
{
	while (number of funtions)
		if function usage == USED
			insert function to min heap;
}

void	function print by its priority
{
	while (heap is not empty)
		pop from heap;
		execute function;
}

int	ft_vprintf(const char *fmt, va_list arg_ptr)
{
	int	total printed length;
	int each printed length;

	while(fmt)
	{
		if '%' appears
		{
			move address of fmt by 1;
			set minimum field width;
			set priority;
			insert to heap;
			print by its priority;
			total printed length += each printed length;
			continue;
		}
		print untyped character;
		move address of fmt by 1;
	}
	return (total printed length);
}

int	ft_printf(const char *fmt, ...)
{
	va_list arg_ptr;
	va_start(arg_ptr, fmt);
	ft_vprintf(fmt, arg_ptr);
	va_end(arg_ptr);
}
