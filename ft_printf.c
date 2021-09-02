#include "ft_printf.h"

int	ft_vprintf(const char *fmt, va_list arg_ptr)
{

	return (0);
}

int	ft_printf(const char *fmt, ...)
{
	va_list arg_ptr;
	va_start(arg_ptr, fmt);
	ft_vprintf(fmt, arg_ptr);
}
