#include "libft.h"
#include <stdio.h>

int	main()
{
	int n = 14;
	int	result[n];
	
	result[0] = ft_printf("%10s", "asdf");
	result[1] = ft_printf("%10d", 123);
	result[2] = ft_printf("%010d", 123);
	result[3] = ft_printf("%-10d", 123);
	result[4] = ft_printf("%10x", 123);
	result[5] = ft_printf("%010x", 123);
	result[6] = ft_printf("%-10x", 123);
	result[7] = ft_printf("%10u", 123);
	result[8] = ft_printf("%010u", 123);
	result[9] = ft_printf("%-10u", 123);
	result[10] = ft_printf("my  :%11p", "123");
	printf("lib :%11p\n", "123");
	result[11] = ft_printf("my  :%-11p", "123");
	printf("lib :%-11p\n", "123");
	result[12] = ft_printf("%10c", 'a');
	result[13] = ft_printf("%-10c", 'a');
	for(int i = 0; i < n; i++)
		printf("%d\n", result[i]);
}
