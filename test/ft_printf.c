#include "ft_printf.h"
#include "heap.h"

int	print_untyped_character(const char *fmt, int ret)
{
	write(1, fmt, 1);
	ret++;
	return (ret);
}

void	print_padding_by_length(int length, int *ret)
{
	*ret += length;
	while (length--)
		write(1, "0", 1);
}

void	print_space_by_length(int length, int *ret)
{
	*ret += length;
	while (length--)
		write(1, " ", 1);
}

void	print_one_space(int *ret)
{
	write(1, " ", 1);
	*ret += 1;
}

void	print_character(int c, int *ret)
{
	write(1, &c, 1);
	*ret += 1;
}

void	print_sign(int value, int *ret)
{
	if (value < 0)
	{	
		write(1, "-", 1);
		*ret += 1;
	}
	else if (value > 0)
	{
		write(1, "+", 1);
		*ret += 1;
	}
	else
		;
}

void	print_argument_by_length(char *str, int length, int *ret)
{
	write(1, str, length);
	*ret += length;
}

void	print_prefix_pointer(int *ret)
{
	write(1, "0x10", 4);
	*ret += 4;
}

void	print_prefix_sharp_up(int *ret)
{
	write(1, "0X", 2);
	*ret += 2;
}

void	print_prefix_sharp_low(int *ret)
{
	write(1, "0x", 2);
	*ret += 2;
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

void	set_flag(const char **fmt, int *flag)
{
	while (is_flag(**fmt))
	{
		if (**fmt == '0')
			*flag |= zero;
		else if (**fmt == '-')
			*flag |= minus;
		else if (**fmt == '+')
			*flag |= plus;
		else if (**fmt == ' ')
			*flag |= space;
		else if (**fmt == '#')
			*flag |= sharp;
		move_fmt_by_length(fmt, 1);
	}
}

int	find_digit(int num)
{
	int digit;

	digit = 0;
	if (!num)
		digit = 1;
	while (num)
	{
		num /= 10;
		digit++;
	}
	return (digit);
}

void	set_width(const char **fmt, int *width)
{
	if (ft_isdigit(**fmt) && **fmt != '0')
	{
		*width = ft_atoi(*fmt);
		move_fmt_by_length(fmt, find_digit(*width));
	}
}

void	set_precision(const char **fmt, t_component *cmp)
{
	if (**fmt == '.')
	{
		move_fmt_by_length(fmt, 1);
		cmp->width_precision = ft_atoi(*fmt);
		move_fmt_by_length(fmt, find_digit(cmp->width_precision));
		cmp->flag |= precision;
	}
}

void	set_type(const char **fmt, int *type)
{
	if (**fmt == 'c')
		*type |= character;
	else if (**fmt == 's')
		*type |= string;
	else if (**fmt == 'p')
		*type |= pointer;
	else if (**fmt == 'd')
		*type |= integer;
	else if (**fmt == 'i')
		*type |= integer;
	else if (**fmt == 'u')
		*type |= u_integer;
	else if (**fmt == 'x')
		*type |= hex_low;
	else if (**fmt == 'X')
		*type |= hex_up;
	else if (**fmt == '%')
		*type |= percent;
	move_fmt_by_length(fmt, 1);
}

void	set_minimum_field_width(const char **fmt, t_component *cmp)
{
	set_flag(fmt, &cmp->flag);
	set_width(fmt, &cmp->width_total);
	set_precision(fmt, cmp);
	set_type(fmt, &cmp->flag);
}

void	set_width_flag(t_component	*cmp)
{
	if ((cmp->flag & plus) || (cmp->flag &space))
		cmp->width_flag++;
	if (cmp->flag & sharp)
		cmp->width_flag += 2;
}

void	set_print_length(t_component *cmp)
{
	set_width_flag(cmp);
	cmp->width_str = ft_strlen(cmp->str);
	if (cmp->width_precision && cmp->width_str > cmp->width_precision)
		cmp->width_str = cmp->width_precision;
	cmp->width_padding = cmp->width_precision - cmp->width_str;
	if (cmp->width_padding < 0)
		cmp->width_padding = 0;
	cmp->width_space = cmp->width_total - cmp->width_flag - cmp->width_str;
	if (!(cmp->flag & string))
		cmp->width_space -= cmp->width_padding;
	if (cmp->flag & character)
		cmp->width_space--;
	if (cmp->flag & pointer)
		cmp->width_space -= 4;
	if (cmp->width_space < 0)
		cmp->width_space = 0;
}

void	get_argument_value(va_list arg_ptr, t_component *cmp)
{
	if (cmp->flag & int_mask)
		cmp->_int = va_arg(arg_ptr, int);
	else if (cmp->flag & string)
		cmp->str = va_arg(arg_ptr, char*);
	else if (cmp->flag & pointer)
		cmp->_int = va_arg(arg_ptr, unsigned long long);
	else if (cmp->flag & u_integer)
		cmp->_int = va_arg(arg_ptr, unsigned int);
	else if (cmp->flag & percent)
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
	if (!cmp->str && !(cmp->flag & character))
		cmp->str = ft_itoa(cmp->_int, base);
}

void	initialize_usage(t_fp function[])
{
	int index;

	index = MAX_SIZE;
	while (index--)
		function[index].usage = NOT_USED;
}

void	set_function_usage(int flag, t_fp function[])
{
		function[ARGUMENT].usage = USED;
		function[ARGUMENT].print_string = print_argument_by_length;
		function[SPACE].usage = USED;
		function[SPACE].print_space = print_space_by_length;

		if (flag & zero)
		{	
			function[ZERO].usage = USED;
			function[SPACE].usage = NOT_USED;
			function[ZERO].print_padding = print_padding_by_length;
		}
		if (flag & pointer)
		{
			function[POINTER].usage = USED;
			function[POINTER].print = print_prefix_pointer;
		}
		if (flag & plus)
		{
			function[PLUS].usage = USED;
			function[PLUS].print_sign = print_sign;
		}
		if (flag & space)
		{
			function[ONESPACE].usage = USED;
			function[ONESPACE].print = print_one_space;
		}
		if (flag & sharp)
		{
			if (flag & hex_up)
			{
				function[SHARPUP].usage = USED;
				function[SHARPUP].print = print_prefix_sharp_up;
			}
			else
			{
				function[SHARPLOW].usage = USED;
				function[SHARPLOW].print = print_prefix_sharp_low;
				
			}
		}
		if (flag & character)
		{
			function[CHAR].usage = USED;
			function[CHAR].print_char = print_character;
			function[ARGUMENT].usage = NOT_USED;
		}
		if (flag & precision)
		{
			function[PRECISION].usage = USED;
			function[PRECISION].print_precision = print_padding_by_length;
		}
		if (flag & string)
		{
			function[ZERO].usage = NOT_USED;
			function[PRECISION].usage = NOT_USED;
		}
}

int	get_used_number(t_fp function[])
{
	int index;
	int	num;

	index = MAX_SIZE;
	num = 0;
	while (index--)
	{
		if (function[index].usage == USED)
			num++;
	}
	return (num);
}

void	set_priority(t_fp function[], int flag)
{
	int priority;
	
	priority = get_used_number(function);
	function[ARGUMENT].priority = priority;
	function[CHAR].priority = priority;
	if (flag & minus)
	{
		priority = function[ARGUMENT].priority + 1;
		function[SPACE].priority = priority;
	}
	if (flag & zero)
	{
		priority = function[SPACE].priority + 1;
		function[ZERO].priority = priority;
	}
	if (flag & precision)
	{
		priority = function[ARGUMENT].priority - 1;
		function[PRECISION].priority = priority;
	}

	if (flag & pointer)
	{
		priority = function[ARGUMENT].priority - 1;
		function[POINTER].priority = priority;
	}
	if (flag & plus)
	{
		priority = function[ARGUMENT].priority - 1;
		function[PLUS].priority = priority;
		function[PRECISION].priority = priority + 1;
	}
	if (flag & space)
	{
		priority = FIRST;
		function[ONESPACE].priority = priority;
	}
	if (flag & sharp)
	{
		priority = function[PRECISION].priority - 1;
		function[SHARPUP].priority = priority;
		function[SHARPLOW].priority = priority;
	}

}

void	insert_to_heap(t_fp function[], Heap *H)
{
	int	index;

	index = MAX_SIZE;
	while (index--)
	{
		if (function[index].usage == USED)
			Insert(H, function[index]);
	}
}

void	print_by_priority(Heap *H, t_component *cmp, int *ret)
{
	t_fp *fp;

	while (H->size)
	{
		fp = Delete(H);
		if (fp->print)
			fp->print(ret);
		else if (fp->print_space)
			fp->print_space(cmp->width_space, ret);
		else if (fp->print_padding)
			fp->print_padding(cmp->width_space, ret);
		else if (fp->print_precision)
			fp->print_precision(cmp->width_padding, ret);
		else if (fp->print_string)
			fp->print_string(cmp->str, cmp->width_str, ret);
		else if (fp->print_char)
			fp->print_char(cmp->_int, ret);
		else if (fp->print_sign)
			fp->print_sign(cmp->_int, ret);
		free(fp);
	}
}

void	init(t_component *cmp)
{
	cmp->_int = 0;
	cmp->_uint = 0;
	cmp->_pointer = 0;
	cmp->flag = 0;
	cmp->str = 0;
	cmp->width_flag = 0;
	cmp->width_padding = 0;
	cmp->width_precision = 0;
	cmp->width_space = 0;
	cmp->width_total = 0;
	cmp->width_str = 0;
}

void	init_function(t_fp *fp)
{
	fp->print = 0;
	fp->print_space = 0;
	fp->print_padding = 0;
	fp->print_precision = 0;
	fp->print_string = 0;
	fp->print_char = 0;
	fp->print_sign = 0;
	fp->priority = 0;
	fp->usage = NOT_USED;
}

int	ft_printf(const char *fmt, ...)
{
	int	ret;
	va_list	arg_ptr;
	t_component cmp;
	t_fp fp[MAX_SIZE];
	Heap H;

	ret = 0;
	va_start(arg_ptr, fmt);
	while(*fmt)
	{
		if (*fmt == '%')
		{
			init(&cmp);
			move_fmt_by_length(&fmt, 1);
			set_minimum_field_width(&fmt, &cmp);
			for (int i = 0; i < MAX_SIZE; i++)
				init_function(&fp[i]);
			initialize_usage(fp);
			set_function_usage(cmp.flag, fp);
			set_priority(fp, cmp.flag);
			insert_to_heap(fp, &H);
			get_argument_value(arg_ptr, &cmp);
			integer_to_string(&cmp);
			set_print_length(&cmp);
			print_by_priority(&H, &cmp, &ret);
			if (cmp.flag & malloc_free)
				free(cmp.str);
		}
		if (*fmt == '\0')
			break;
		ret = print_untyped_character(fmt, ret);
		move_fmt_by_length(&fmt, 1);
	}
	va_end(arg_ptr);
	return (ret);
}
