#include "psuedo_printf.h"
#include "heap.h"

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

void	print_sign(int value)
{
	if (value < 0)
		write(1, "-", 1);
	else if (value > 0)
		write(1, "+", 1);
	else
		return ;
}

void	print_argument_by_length(char *str, int length)
{
	write(1, str, length);
}

void	print_prefix_pointer()
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

void	set_precision(const char **fmt, int *precision)
{
	if (**fmt == '.')
	{
		move_fmt_by_length(fmt, 1);
		*precision = ft_atoi(*fmt);
		move_fmt_by_length(fmt, find_digit(*precision));
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
	set_precision(fmt, &cmp->width_precision);
	set_type(fmt, &cmp->flag);
}

void	set_width_flag(t_component	*cmp)
{
	if (cmp->flag & (plus || space))
		cmp->width_flag++;
	if (cmp->flag & sharp)
		cmp->width_flag += 2;
}

void	set_print_length(t_component *cmp)
{
	set_width_flag(cmp);
	cmp->width_space = cmp->width_total - cmp->width_flag - cmp->width_precision;
	cmp->width_padding = cmp->width_precision - ft_strlen(cmp->str);
	if (cmp->width_space < 0)
		cmp->width_space = 0;
	if (cmp->width_padding < 0)
		cmp->width_padding = 0;
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
	if (!cmp->str)
		cmp->str = ft_itoa(cmp->_int, base);
}

void	initialize_usage(t_fp function[])
{
	int index;

	index = 8;
	while (index--)
		function[index].usage = NOT_USED;
}

void	set_function_usage(int flag, t_fp function[])
{
		function[ARGUMENT].usage = USED;
		function[SPACE].usage = USED;

		if ((flag & zero) || (flag & precision))
			function[ZERO].usage = USED;
		if (flag & pointer)
			function[POINTER].usage = USED;
		if (flag & plus)
			function[PLUS].usage = USED;
		if (flag & space)
			function[SPACE].usage = USED;
		if (flag & sharp)
		{
			function[SHARPUP].usage = USED;
			function[SHARPLOW].usage = USED;
		}
		if (flag & string)
			function[ZERO].usage = NOT_USED;
}

void	set_function_number(t_fp funtion[])
{
	funtion[ARGUMENT].print_untyped = print_argument_by_length;
	funtion[SPACE].print_l = print_space_by_length;
	funtion[ONESPACE].print = print_one_space;
	funtion[PLUS].print = print_sign;
	funtion[SHARPUP].print = print_prefix_sharp_up;
	funtion[SHARPLOW].print = print_prefix_sharp_low;
	funtion[ZERO].print_l = print_padding_by_length;
	funtion[POINTER].print_l = print_prefix_pointer;
}

void	set_priority(t_fp function[], int flag)
{
	int priority;
	
	priority = 5;
	function[ARGUMENT].priority = priority;
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
	if (flag & (pointer || sharp))
	{
		priority = function[ARGUMENT].priority + 1;
		function[POINTER].priority = priority;
	}
	if (flag & plus)
	{
		priority = function[ARGUMENT].priority + 1;
		function[PLUS].priority = priority;
	}
	if (flag & space)
	{
		priority = FIRST;
		function[ONESPACE].priority = priority;
	}
}

void	insert_to_heap(t_fp function[], Heap *H)
{
	int	index;

	index = 8;
	while (index--)
	{
		if (function[index].usage == USED)
			HEAP_Insert(H, function[index], function[index].priority);
	}
}

void	print_by_priority(Heap *H, t_component cmp)
{
	HeapNode func;

	while (H->UsedSize)
	{
		HEAP_DeleteMin(H, &func);
		if (func.fp.print_l)
			func.fp.print_l(2);
		if (func.fp.print)
			func.fp.print();
		if (func.fp.print_untyped)
			func.fp.print_untyped(cmp.str, cmp.width_total);
	}
}

void	init(t_component *cmp)
{
	cmp->_int = 0;
	cmp->flag = 0;
	cmp->str = 0;
	cmp->width_flag = 0;
	cmp->width_padding = 0;
	cmp->width_precision = 0;
	cmp->width_space = 0;
	cmp->width_total = 0;
}

void	init_function(t_fp *fp)
{
	fp->print = 0;
	fp->print_l = 0;
	fp->print_untyped = 0;
	fp->priority = 0;
	fp->usage = 0;
}

int	ft_printf(const char *fmt, ...)
{
	//int	total printed length;
	//int each printed length;
	int	ret;
	t_component cmp;
	t_fp fp[8];
	Heap *H;
	va_list arg_ptr;
	va_start(arg_ptr, fmt);

			for (int i = 0; i < 8; i++)
				init_function(&fp[i]);
	set_function_number(fp);
	init(&cmp);
	//H = HEAP_Create(8);
	//fp = (t_fp *)malloc(sizeof(t_fp) * 8);
	while(*fmt)
	{
		if (*fmt == '%')
		{

			H = HEAP_Create(8);
			move_fmt_by_length(&fmt, 1);
			set_minimum_field_width(&fmt, &cmp);
			initialize_usage(fp);
			set_function_usage(cmp.flag, fp);
			set_priority(fp, cmp.flag);
			insert_to_heap(fp, H);
			get_argument_value(arg_ptr, &cmp);
			integer_to_string(&cmp);
			set_print_length(&cmp);
			print_by_priority(H, cmp);
			//total printed length += each printed length;
			//continue;
			HEAP_Destroy(H);
			init(&cmp);
			for (int i = 0; i < 8; i++)
				init_function(&fp[i]);
		}
		ret += print_untyped_character(fmt, ret);
		move_fmt_by_length(&fmt, 1);
		if (*fmt == '\0')
			break;
	}
	va_end(arg_ptr);
	return (ret);
}

/*int	ft_printf(const char *fmt, ...)
{
	int ret;

	va_list arg_ptr;
	va_start(arg_ptr, fmt);
	ret = ft_vprintf(fmt, arg_ptr);
	va_end(arg_ptr);
	return (ret);
}*/
