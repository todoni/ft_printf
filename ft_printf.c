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

void	set_flag_align(const char **fmt, t_component *arg)
{
	if (**fmt == '0')
		arg->flag |= zero;
	else if (**fmt == '-')
		arg->flag |= minus;
	if ((arg->flag & zero) || (arg->flag & minus))
		(*fmt)++;
}

void	set_flag_asterisk1(const char **fmt, t_component *arg)
{
	if (**fmt == '*')
	{
		arg->flag |= asterisk1;
		(*fmt)++;
	}
}

void	set_flag_asterisk2(const char **fmt, t_component *arg)
{
	if (**fmt == '*')
	{
		arg->flag |= asterisk2;
		(*fmt)++;
	}
}

void	set_flag_precision(const char **fmt, t_component *arg)
{
	if (**fmt == '.')
	{
		arg->flag |= precision;
		(*fmt)++;
	}
}

void	get_width(const char **fmt, int *width)
{
	*width = ft_atoi(*fmt);
	while (ft_isdigit(**fmt))
		(*fmt)++;
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
		arg->width_prec = va_arg(*arg_ptr, int);
}

/*int	ft_vsprintf(char *str, const char *fmt, va_list arg_ptr)
{

}*/
void	initialize_component(t_component *arg)
{
	arg->width_space = 0;
	arg->width_total = 0;
	arg->width_padding = 0;
	arg->width_prec = 0;
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
		set_flag_align(&fmt, &arg);
		set_flag_asterisk1(&fmt, &arg);
		if (!(arg.flag & asterisk1))
			get_width(&fmt, &arg.width_total);
		set_flag_precision(&fmt, &arg);
		set_flag_asterisk2(&fmt, &arg);
		if (!(arg.flag & asterisk2))
			get_width(&fmt, &arg.width_prec);
		set_flag_type(&fmt, &arg);
		set_width(&arg, &arg_ptr);
		if (arg.flag & character)
		{
			arg._int = va_arg(arg_ptr, int);
			arg.width_space = arg.width_total - 1;
			if (arg.flag & minus)
			{
				write(1, &arg._int, 1);
				print_space(arg.width_space);
			}
			else
			{
				print_space(arg.width_space);
				write(1, &arg._int, 1);
			}
		}
		if ((arg.flag & integer) || (arg.flag & u_integer))
		{
			arg._int = va_arg(arg_ptr, int);
			arg.str = ft_itoa(arg._int, "0123456789");	
			arg.width_space = arg.width_total - ft_strlen(arg.str);
			if (arg.flag & asterisk2)
			{
				arg.width_padding = arg.width_prec - ft_strlen(arg.str);
				arg.width_space -= arg.width_padding;
			}
			if (arg.flag & zero)
			{
				arg.width_padding = arg.width_space;
				print_padding(arg.width_padding);
				write(1, arg.str, ft_strlen(arg.str));
			}
			else if (arg.flag & minus)
			{
				print_padding(arg.width_padding);
				write(1, arg.str, ft_strlen(arg.str));
				print_space(arg.width_space);
			}
			else
			{
				print_space(arg.width_space);
				print_padding(arg.width_padding);
				write(1, arg.str, ft_strlen(arg.str));
			}
		}
		else if (arg.flag & string)
		{
			arg.str = va_arg(arg_ptr, char *);
			if (arg.width_total < ft_strlen(arg.str))
				arg.width_total = ft_strlen(arg.str);
			arg.width_space = arg.width_total - ft_strlen(arg.str);
			if (arg.flag & minus)
			{
				write(1, arg.str, ft_strlen(arg.str));
				print_space(arg.width_space);
			}
			else
			{
				print_space(arg.width_space);
				write(1, arg.str, ft_strlen(arg.str));
			}	
		}
		else if (arg.flag & pointer)
		{
			arg._int = va_arg(arg_ptr, unsigned long long);
			arg.str = ft_itoa(arg._int, "0123456789abcdef");
			if (arg.width_total < addr_len_fixed)
				arg.width_total = addr_len_fixed;
			arg.width_padding = addr_len_fixed - ft_strlen(arg.str) - 4;
			arg.width_space = arg.width_total - addr_len_fixed;
			if (arg.flag & minus)
			{
				write(1, "0x10", 4);
				print_padding(arg.width_padding);
				write(1, arg.str, ft_strlen(arg.str));
				print_space(arg.width_space);
			}
			else
			{
				print_space(arg.width_space);
				write(1, "0x10", 4);
				print_padding(arg.width_padding);
				write(1, arg.str, ft_strlen(arg.str));
			}	
		}
		else if (arg.flag & hex_up)
		{
			arg._int = va_arg(arg_ptr, int);
			arg.str = ft_itoa(arg._int, "0123456789ABCDEF");
			arg.width_space = arg.width_total - ft_strlen(arg.str);
			if (arg.flag & asterisk2)
			{
				arg.width_padding = arg.width_prec - ft_strlen(arg.str);
				arg.width_space -= arg.width_padding;
			}
			if (arg.flag & zero)
			{
				arg.width_padding = arg.width_space;
				print_padding(arg.width_padding);
				write(1, arg.str, ft_strlen(arg.str));
			}
			else if (arg.flag & minus)
			{
				print_padding(arg.width_padding);
				write(1, arg.str, ft_strlen(arg.str));
				print_space(arg.width_space);
			}
			else
			{
				print_space(arg.width_space);
				print_padding(arg.width_padding);
				write(1, arg.str, ft_strlen(arg.str));
			}
		}
		else if (arg.flag & hex_low)
		{
			arg._int = va_arg(arg_ptr, int);
			arg.str = ft_itoa(arg._int, "0123456789abcdef");
			arg.width_space = arg.width_total - ft_strlen(arg.str);
			if (arg.flag & asterisk2)
			{
				arg.width_padding = arg.width_prec - ft_strlen(arg.str);
				arg.width_space -= arg.width_padding;
			}
			if (arg.flag & zero)
			{
				arg.width_padding = arg.width_space;
				print_padding(arg.width_padding);
				write(1, arg.str, ft_strlen(arg.str));
			}
			else if (arg.flag & minus)
			{
				print_padding(arg.width_padding);
				write(1, arg.str, ft_strlen(arg.str));
				print_space(arg.width_space);
			}
			else
			{
				print_space(arg.width_space);
				print_padding(arg.width_padding);
				write(1, arg.str, ft_strlen(arg.str));
			}	
		}
	}
	va_end(arg_ptr);
	write(1, "\n", 1);
	return (arg.width_total);
}
