#include "ft_printf.h"

int	print_untyped_character(const char *fmt, int ret)
{
	write(1, fmt, 1);
	ret++;
	return (ret);
}

void	print_padding_by_length(int length)
{
	while (length--)
		write(1, "0", 1);
}

void	print_space_by_length(int length)
{
	while (length--)
		write(1, " ", 1);
}

void	print_one_space()
{
	write(1, " ", 1);
}

void	print_sign()
{
	if value < 0
		write(1, "-", 1);
	else if value > 0
		write(1, "+", 1);
	else
		return ;
}

void	print_argument_by_length(int length)
{
	write(1, string, length);
}

void	print_prefix_pointer();
{
	write(1, "0x10", 4);
}

void	print_prefix_sharp_up()
{
	write(1, "0X", 2);
}

void	print_prefix_sharp_low()
{
	write(1, "0X", 2);
}

void	move_fmt_by_length(const char **fmt, int length)
{
	(*fmt) += length;
}

int	is_flag(char c)
{
	if (c == '0' || c == '-' || c == '+' || c == ' ' || c == '#')
		return (1);
	return (0);
}

void	set_flag(const char *fmt, int *flag)
{
	while (is_flag(*fmt))
	{
		if (*fmt == '0')
			*flag |= zero;
		else if (*fmt == '-')
			*flag |= minus;
		else if (*fmt == '+')
			*flag |= plus;
		else if (*fmt == ' ')
			*flag |= space;
		else if (*fmt == '#')
			*flag |= sharp;
		move_fmt_by_length(&fmt, 1);
	}
}

int	find_digit(int num)
{
	int digit;

	while (num)
	{
		num /= 10;
		digit++;
	}
	return (digit);
}

void	set_width(const char *fmt, int *width)
{
	if (ft_isdigit(*fmt) && *fmt != '0')
	{
		*width = ft_atoi(fmt);
		move_fmt_by_length(find_digit(*width));
	}
}

void	set_precision(const char *fmt, int *precision)
{
	if (*fmt == '.')
	{
		move_fmt_by_length(&fmt, 1);
		*precision = ft_atoi(fmt);
		move_fmt_by_length(fint_digit(*precision));
	}
}

void	set_type(const char *fmt, int *type)
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
	move_fmt_by_length(&fmt, 1);
}

void	set_minimum_field_width(const char *fmt, t_component *cmp)
{
	set_flag(&fmt, &cmp->flag);
	set_width(&fmt, &cmp->width_total);
	set_precision(&fmt, &cmp->width_precision);
	set_type(&fmt, &cmp->flag);
}

void	set_print_length(t_component *cmp)
{
	cmp->width_space = cmp->width_total - plus flag length(1) - space flag length(1) - sharp flag length(2) - precision flag length(width of precision);
	total width = width;
	cmp->width_padding = cmp->width_precision - length of value;

	if all lengths < 0
		lengths = 0;
}

void	get_argument_value(va_list arg_ptr, t_component *cmp)
{
	if (type & int_mask)
		cmp->_int = va_arg(arg_ptr, int);
	else if (type & string)
		cmp->str = va_arg(arg_ptr, char*);
	else if (type & pointer)
		cmp->_int = va_arg(arg_ptr, unsigned long long);
	else if (type & u_integer)
		cmp->_int = va_arg(arg_ptr, unsigned int);
	else if (type & percent)
		cmp->str = "%";
}

void	integer_to_string(t_component *cmp)
{
	char	*base;

	if (cmp->flag & int_base_mask)
		base = "0123456789";
	else if (cmp->flag & x_base_mask)
		base = "0123456789abcdef";
	else if (cmp->flag & hex_up)
		base = "0123456789ABCDEF";
	if (!cmp->str)
		cmp->str = ft_itoa(_int, base);
}

void	initialize_usage(t_fp *function[])
{
	while (number of functions)
		functions[i] = NOT_USED;
}

void	function set function usage
{
		function print argument = USED;
		function print space = USED;

		if zero bit on || precision bit on
			function print zero = USED;	
		if pointer bit on
			function print 0x10 = USED;
		if plus bit on
			function print sign = USED;
		if space bit on
			function print 1 space = USED;
		if sharp bit on
			function print 0x10 = USED;
			function print 0X = USED;
		if string bit on
			function print zero = NOT_USED;
}

void	function numbering functions
{
	
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
