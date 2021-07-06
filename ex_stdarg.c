#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"

void	va_print(int argc, ...)
{
	va_list	ap;
	char	*value;
	
	va_start(ap, argc);
	while (argc--)
	{
		value = va_arg(ap, char*);
		printf("%s ", value);
	}
	printf("\n");
}

int	main()
{
	va_print(1, "a");
	va_print(2, "abc", "def");
	va_print(3, "a", "b", "c");
	return (0);
}
