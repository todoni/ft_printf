#include "ft_printf.h"

int	function print untyped character(const char *fmt, int ret)
{
	write(1, fmt, 1);
	ret++;
	return (ret);
}

void	function print padding by given length
{
	while (length--)
		write(1, "0", 1); 
}

void	function print space by given length
{
	while (length--)
		write(1, " ", 1); 
}

void	function print 1 space
{
	write(1, " ", 1);
}

void	function print sign
{
	if value < 0
		write(1, "-", 1);
	else if value > 0
		write(1, "+", 1);
	else
		return ;
}

void	function print argument by given length
{
	write(1, string, length); 
}

void	function print 0x10
{
	write(1, "0x10", 4);
}

void	function move address of fmt by given length(const char **fmt, int length)
{
	(*fmt) += length;
}

void	function set flag
{
	while (*fmt is flag type)
		if (*fmt == '0')
			flag |= zero;
		else if (*fmt == '-')
			flag |= minus;
		else if (*fmt == '+')
			flag |= plus;
		else if (*fmt == ' ')
			flag |= space;
		else if (*fmt == '#')
			flag |= sharp;
		move address of fmt by 1;
}

void	function set width
{
	if (*fmt is number and not '0')
		width = atoi(fmt);
		move address of fmt by digit;
}

void	function set precision
{
	if (*fmt == '.')
		move address of fmt by 1;
		precision = atoi(fmt);
		move address of fmt by digit;
}

void	function set type
{
	if (*fmt == 'c')
		type |= character;
	else if (*fmt == 's')
		type |= string;
	else if (*fmt == 'p')
		type |= pointer;
	else if (*fmt == 'd')
		type |= integer;
	else if (*fmt == 'i')
		type |= integer;
	else if (*fmt == 'u')
		type |= u_integer;
	else if (*fmt == 'x')
		type |= hex_low;
	else if (*fmt == 'X')
		type |= hex_up;
	else if (*fmt == '%')
		type |= percent;
	
	move address of fmt by 1;
}

void	function set minimum field width
{
	set flag;
	set width;
	set precision;
	set type;
}

void	function get argument value
{
	if (type & int_mask)
		_int = va_arg(arg_ptr, int);
	else if (type & string)
		str = va_arg(arg_ptr, char*);
	else if (type & pointer)
		_int = va_arg(arg_ptr, unsigned long long);
	else if (type & u_integer)
		_int = va_arg(arg_ptr, unsigned int);
	else if (type & percent)
		str = "%";
}

void	function make integer argument string
{
	char	*base;

	if (type & int_base_mask)
		base = "0123456789";
	else if (type & x_base_mask)
		base = "0123456789abcdef";
	else if (type & hex_up)
		base = "0123456789ABCDEF";
	
	if (!str)
		str = ft_itoa(_int, base);
}

void	function initialize function usage
{
	while (number of functions)
		functions[i] = NOT_USED;
}

void	function set function usage
{
		function print argument = USED;
		function print space = USED;

		if zero bit on
			function print zero = USED;	
		if pointer bit on || sharp bit on
			function print 0x10 = USED;
		if plus bit on
			function print sign = USED;
		if space bit on
			function print 1 space = USED;
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
