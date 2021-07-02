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
	va_list	arg_ptr;
	int		flag;
	int		len_printed;
	int		width_space;
	int		width_total;
	int		width_padding;
	char	*str;
	char	_char;
	int		_int;
	
	flag = 0;
	va_start(arg_ptr, fmt);
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
			flag |= zero;
		else if (*fmt == '-')
			flag |= minus;
		if ((flag & zero) || (flag & minus))
			fmt++;
		width_total = ft_atoi(fmt);
		while (ft_isdigit(*fmt))
			fmt++;
		if (*fmt == '.')
		{
			flag |= precision;
			fmt++;
		}
		while (ft_isdigit(*fmt))
			fmt++;
		if (*fmt == 'c')
			flag |= character;
		else if (*fmt == 's')
			flag |= string;
		else if (*fmt == 'p')
			flag |= pointer;
		else if (*fmt == 'd')
			flag |= integer;
		else if (*fmt == 'i')
			flag |= integer;
		else if (*fmt == 'u')
			flag |= u_integer;
		else if (*fmt == 'x')
			flag |= hex_low;
		else if (*fmt == 'X')
			flag |= hex_up;
		else if (*fmt == '%')
			flag |= percent;
		fmt++;
		if (flag & character)
		{
			_int = va_arg(arg_ptr, int);
			width_space = width_total - 1;
			if (flag & minus)
			{
				write(1, &_int, 1);
				print_space(width_space);
			}
			else
			{
				print_space(width_space);
				write(1, &_int, 1);
			}
		}
		if ((flag & integer) || (flag & u_integer))
		{
			_int = va_arg(arg_ptr, int);
			str = ft_itoa(_int, "0123456789");
			width_space = width_total - ft_strlen(str);
			if (flag & zero)
			{
				width_padding = width_space;
				print_padding(width_padding);
				write(1, str, ft_strlen(str));
			}
			else if (flag & minus)
			{
				write(1, str, ft_strlen(str));
				print_space(width_space);
			}
			else
			{
				print_space(width_space);	
				write(1, str, ft_strlen(str));
			}
		}
		else if (flag & string)
		{
			str = va_arg(arg_ptr, char *);
			if (width_total < ft_strlen(str))
				width_total = ft_strlen(str);
			width_space = width_total - ft_strlen(str);
			if (flag & minus)
			{
				write(1, str, ft_strlen(str));
				print_space(width_space);
			}
			else
			{
				print_space(width_space);
				write(1, str, ft_strlen(str));
			}	
		}
		else if (flag & pointer)
		{
			_int = va_arg(arg_ptr, unsigned long long);
			str = ft_itoa(_int, "0123456789abcdef");
			if (width_total < 11)
				width_total = 11;
			width_padding = 11 - ft_strlen(str) - 4;
			width_space = width_total - 11;
			if (flag & minus)
			{
				write(1, "0x10", 4);
				print_padding(width_padding);
				write(1, str, ft_strlen(str));
				print_space(width_space);
			}
			else
			{
				print_space(width_space);
				write(1, "0x10", 4);
				print_padding(width_padding);
				write(1, str, ft_strlen(str));
			}	
		}
		else if (flag & hex_up)
		{
			_int = va_arg(arg_ptr, int);
			str = ft_itoa(_int, "0123456789ABCDEF");
			width_space = width_total - ft_strlen(str);
			if (flag & zero)
			{
				width_padding = width_space;
				print_padding(width_padding);
				write(1, str, ft_strlen(str));
			}
			else if (flag & minus)
			{
				write(1, str, ft_strlen(str));
				print_space(width_space);
			}
			else
			{
				print_space(width_space);	
				write(1, str, ft_strlen(str));
			}
		}
		else if (flag & hex_low)
		{
			_int = va_arg(arg_ptr, int);
			str = ft_itoa(_int, "0123456789abcdef");
			width_space = width_total - ft_strlen(str);
			if (flag & zero)
			{
				width_padding = width_space;
				print_padding(width_padding);
				write(1, str, ft_strlen(str));
			}
			else if (flag & minus)
			{
				write(1, str, ft_strlen(str));
				print_space(width_space);
			}
			else
			{
				print_space(width_space);	
				write(1, str, ft_strlen(str));
			}
		}
	}
	va_end(arg_ptr);
	write(1, "\n", 1);
	return (width_total);
}
