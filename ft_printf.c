#include <stdarg.h>
#include <unistd.h>
#include "libft.h"
#include "ft_printf.h"

void	print_space(int width_space)
{
	while (width_space-- && width_space >= 0)
		write(1, " ", 1);
}

void	print_padding(int width_padding)
{
	while (width_padding-- && width_padding >= 0)
		write(1, "0", 1);
}

void	set_flag_prefixed(const char **fmt, t_component *arg)
{
	if (**fmt == '+')
		arg->flag |= plus;
	else if (**fmt == ' ')
		arg->flag |= space;
	else if (**fmt == '#')
		arg->flag |= sharp;
}

void	set_flag_align(const char **fmt, t_component *arg)
{
	if (**fmt == '0')
		arg->flag |= zero;
	else if (**fmt == '-')
		arg->flag |= minus;
}

void	set_flag_asterisk1(const char **fmt, t_component *arg)
{
	if (**fmt == '*')
		arg->flag |= asterisk1;
}

void	set_flag_asterisk2(const char **fmt, t_component *arg)
{
	if (**fmt == '*')
		arg->flag |= asterisk2;
}

void	set_flag_precision(const char **fmt, t_component *arg)
{
	if (**fmt == '.')
		arg->flag |= precision;
}

void	move_to_next_field(const char **fmt)
{
	while (ft_isdigit(**fmt))
		(*fmt)++;
}

void	get_width(const char **fmt, int *width)
{
	*width = ft_atoi(*fmt);
}

void	set_flag_type(const char **fmt, t_component *arg)
{
	if (**fmt == 'c')
		arg->flag |= character;
	else if (**fmt == 's')
		arg->flag |= string;
	else if (**fmt == 'p')
		arg->flag |= pointer;
	else if (**fmt == 'd')
		arg->flag |= integer;
	else if (**fmt == 'i')
		arg->flag |= integer;
	else if (**fmt == 'u')
		arg->flag |= u_integer;
	else if (**fmt == 'x')
		arg->flag |= hex_low;
	else if (**fmt == 'X')
		arg->flag |= hex_up;
	else if (**fmt == '%')
		arg->flag |= percent;
	(*fmt)++;
}

void	print_untyped_string(const char **fmt)
{
	while (**fmt != '%' && **fmt)
	{
		write(1, *fmt, 1);
		(*fmt)++;
	}
	if (**fmt)
		(*fmt)++;
}

void	set_width(t_component *arg, va_list *arg_ptr)
{
	if (arg->flag & asterisk1)
		arg->width_total = va_arg(*arg_ptr, int);
	if (arg->flag & asterisk2)
		arg->width_precision = va_arg(*arg_ptr, int);
}

int	get_arg_value(t_component *arg, va_list *arg_ptr)
{
	if (arg->flag & character)
		arg->_int = va_arg(*arg_ptr, int);
	else if ((arg->flag & integer) || (arg->flag & u_integer))
	{
		arg->_int = va_arg(*arg_ptr, int);
		arg->str = ft_itoa(arg->_int, "0123456789");
		if (arg->str == 0)
			return (-1);
	}
	else if (arg->flag & string)
		arg->str = va_arg(*arg_ptr, char *);
	else if (arg->flag & pointer)
	{
		arg->_int = va_arg(*arg_ptr, unsigned long long);
		arg->str = ft_itoa(arg->_int, "0123456789abcdef");
		if (arg->str == 0)
			return (-1);
	}
	else if (arg->flag & hex_up)
	{
		arg->_int = va_arg(*arg_ptr, int);
		arg->str = ft_itoa(arg->_int, "0123456789ABCDEF");
		if (arg->str == 0)
			return (-1);
	}
	else if (arg->flag & hex_low)
	{
		arg->_int = va_arg(*arg_ptr, int);
		arg->str = ft_itoa(arg->_int, "0123456789abcdef");
		if (arg->str == 0)
			return (-1);
	}
	return (0);
}

int	flag_on(int calculation)
{
	if (calculation != 0)
		return (1);
	return (calculation);
}
/*int	ft_vsprintf(char *str, const char *fmt, va_list arg_ptr)
{

}*/
void	initialize_component(t_component *arg)
{
	arg->width_space = 0;
	arg->width_total = 0;
	arg->width_padding = 0;
	arg->width_precision = 0;
	arg->str = 0;
	arg->_int = 0;
	arg->flag = 0;
}

int	ft_printf(const char *fmt, ...)
{
	t_component	arg;
	va_list	arg_ptr;

	va_start(arg_ptr, fmt);
	while (*fmt)
	{
		initialize_component(&arg);
		print_untyped_string(&fmt);
		set_flag_prefixed(&fmt, &arg);
		fmt += flag_on(arg.flag & space);
		fmt += flag_on(arg.flag & plus);
		fmt += flag_on(arg.flag & sharp);
		set_flag_align(&fmt, &arg);
		fmt += flag_on(arg.flag & zero);
		fmt += flag_on(arg.flag & minus);
		set_flag_asterisk1(&fmt, &arg);
		fmt += flag_on(arg.flag & asterisk1);
		get_width(&fmt, &arg.width_total);
		move_to_next_field(&fmt);
		set_flag_precision(&fmt, &arg);
		fmt += flag_on(arg.flag & precision);
		set_flag_asterisk2(&fmt, &arg);
		fmt += flag_on(arg.flag & asterisk2);
		get_width(&fmt, &arg.width_precision);
		move_to_next_field(&fmt);
		set_flag_type(&fmt, &arg);
		set_width(&arg, &arg_ptr);
		if (get_arg_value(&arg, &arg_ptr) == -1)
			return (-1);
		if (arg.width_total < (int)ft_strlen(arg.str))
			arg.width_total = ft_strlen(arg.str);
		arg.width_space = arg.width_total - ft_strlen(arg.str) - (flag_on(arg.flag & space) + (2 * flag_on(arg.flag & sharp)) + flag_on(arg.flag & plus) + flag_on(arg.flag & percent));
		arg.width_padding = arg.width_precision - (flag_on(arg.flag & asterisk2) * ft_strlen(arg.str));
		arg.width_space -= arg.width_padding;
		write(1, " ", 1 * flag_on(arg.flag & space));
		write(1, "0x", 2 * flag_on(arg.flag & sharp) * flag_on(arg.flag & zero));
		write(1, "+", 1 * flag_on(arg.flag & plus) * flag_on(arg.flag & zero));
		if (arg.flag & zero)
			print_padding(arg.width_space);
		else
			print_space(arg.width_space * (1 - flag_on(arg.flag & minus)));
		write(1, "+", (flag_on(arg.flag & plus) * (1 - flag_on(arg.flag & zero))));
		write(1, "0x", 2 * (flag_on(arg.flag & sharp) * (1 - flag_on(arg.flag & zero))));
		write(1, &arg._int, 1 * flag_on(arg.flag & character));
		write(1, "0x10", 4 * flag_on(arg.flag & pointer));
		print_padding(arg.width_padding - (4 * flag_on(arg.flag & pointer)));
		write(1, arg.str, ft_strlen(arg.str));
		write(1, "%", flag_on(arg.flag & percent));
		print_space(arg.width_space * flag_on(arg.flag & minus));
		if (arg.flag & malloc_free)
			free(arg.str);
		print_untyped_string(&fmt);
	}
	va_end(arg_ptr);
	return (arg.width_total);
}
