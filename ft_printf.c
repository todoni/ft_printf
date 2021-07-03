#include <stdarg.h>
#include <unistd.h>
#include "libft.h"
#include "ft_printf.h"

void	print_space(int width_space)
{
	while (width_space--)
		write(1, " ", 1);
}

void	print_padding(int width_padding)
{
	while (width_padding--)
		write(1, "0", 1);
}

int	ft_printf(const char *fmt, ...)
{
	t_component	arg;

	arg.flag = 0;
	va_start(arg.ptr, fmt);
	while (*fmt)
	{
		while (*fmt != '%' && *fmt)
		{
			write(1, fmt, 1);
			fmt++;
		}
		if (*fmt)
			fmt++;
		if (*fmt == '0')
			arg.flag |= zero;
		else if (*fmt == '-')
			arg.flag |= minus;
		if ((arg.flag & zero) || (arg.flag & minus))
			fmt++;
		arg.width_total = ft_atoi(fmt);
		while (ft_isdigit(*fmt))
			fmt++;
		if (*fmt == '.')
		{
			arg.flag |= precision;
			fmt++;
		}
		arg.width_prec = ft_atoi(fmt);
		while (ft_isdigit(*fmt))
			fmt++;
		if (*fmt == 'c')
			arg.flag |= character;
		else if (*fmt == 's')
			arg.flag |= string;
		else if (*fmt == 'p')
			arg.flag |= pointer;
		else if (*fmt == 'd')
			arg.flag |= integer;
		else if (*fmt == 'i')
			arg.flag |= integer;
		else if (*fmt == 'u')
			arg.flag |= u_integer;
		else if (*fmt == 'x')
			arg.flag |= hex_low;
		else if (*fmt == 'X')
			arg.flag |= hex_up;
		else if (*fmt == '%')
			arg.flag |= percent;
		fmt++;
		if (arg.flag & character)
		{
			arg._int = va_arg(arg.ptr, int);
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
			arg._int = va_arg(arg.ptr, int);
			arg.str = ft_itoa(arg._int, "0123456789");
			arg.width_space = arg.width_total - ft_strlen(arg.str);
			if (arg.flag & zero)
			{
				arg.width_padding = arg.width_space;
				print_padding(arg.width_padding);
				write(1, arg.str, ft_strlen(arg.str));
			}
			else if (arg.flag & minus)
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
		else if (arg.flag & string)
		{
			arg.str = va_arg(arg.ptr, char *);
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
			arg._int = va_arg(arg.ptr, unsigned long long);
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
			arg._int = va_arg(arg.ptr, int);
			arg.str = ft_itoa(arg._int, "0123456789ABCDEF");
			arg.width_space = arg.width_total - ft_strlen(arg.str);
			if (arg.flag & zero)
			{
				arg.width_padding = arg.width_space;
				print_padding(arg.width_padding);
				write(1, arg.str, ft_strlen(arg.str));
			}
			else if (arg.flag & minus)
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
		else if (arg.flag & hex_low)
		{
			arg._int = va_arg(arg.ptr, int);
			arg.str = ft_itoa(arg._int, "0123456789abcdef");
			arg.width_space = arg.width_total - ft_strlen(arg.str);
			if (arg.flag & zero)
			{
				arg.width_padding = arg.width_space;
				print_padding(arg.width_padding);
				write(1, arg.str, ft_strlen(arg.str));
			}
			else if (arg.flag & minus)
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
	}
	va_end(arg.ptr);
	write(1, "\n", 1);
	return (arg.width_total);
}
