#include "libft.h"
#include <stdio.h>

int	main()
{
	int n = 38;
	int	result[n];
	
	result[0] = ft_printf("%10s\n", "asdf");
	result[1] = ft_printf("%10d\n", 123);
	result[2] = ft_printf("%010d\n", 123);
	result[3] = ft_printf("%-10d\n", 123);
	result[4] = ft_printf("%10x\n", 123);
	result[5] = ft_printf("%010x\n", 123);
	result[6] = ft_printf("%-10x\n", 123);
	result[7] = ft_printf("%10u\n", 123);
	result[8] = ft_printf("%010u\n", 123);
	result[9] = ft_printf("%-10u\n", 123);
	result[10] = ft_printf("my  :%11p\n", "123");
	printf("lib :%11p\n", "123");
	result[11] = ft_printf("my  :%-11p\n", "123");
	printf("lib :%-11p\n", "123");
	result[12] = ft_printf("%c\n", 'a');
	result[13] = ft_printf("%-c\n", 'a');
	result[14] = ft_printf("%s\n", "asdf");
	result[15] = ft_printf("%d\n", 123);
	result[16] = ft_printf("%d\n", 123);
	result[17] = ft_printf("%-d\n", 123);
	result[18] = ft_printf("%x\n", 123);
	result[19] = ft_printf("%x\n", 123);
	result[20] = ft_printf("%-x\n", 123);
	result[21] = ft_printf("%u\n", 123);
	result[22] = ft_printf("%u\n", 123);
	result[23] = ft_printf("%-u\n", 123);
	result[24] = ft_printf("%*.*d\n", 7, 5, 123);
	result[25] = ft_printf("%*.*x\n", 7, 5, 123);
	result[26] = ft_printf("%*.*u\n", 7, 5, 123);
	result[27] = ft_printf("%-*.*d\n", 7, 5, 123);
	result[28] = ft_printf("%-*.*x\n", 7, 5, 123);
	result[29] = ft_printf("%-*.*u\n", 7, 5, 123);
	result[30] = ft_printf("%#09x\n", 42);
	result[31] = ft_printf("%#-*.*x\n", 9, 5, 42);
	result[32] = ft_printf("%#*.*x\n", 9, 5, 42);
	result[33] = ft_printf("%+-10d\n", 42);
	result[34] = ft_printf("%+10d\n", 42);
	result[35] = ft_printf("% -010d\n", 42);
	result[36] = ft_printf("%- 010d\n", 42);
	result[37] = ft_printf("%-5%\n");
	/*result[30] = ft_printf("integer: %d, string: %s, hex lower: %x, pointer: %p ", 123, "456", 123, "456");
	result[31] = ft_printf("integer: %10d, string: %10s, hex lower: %10x, pointer: %p", 123, "456", 123, "456");
	result[32] = ft_printf("integer: %-10d, string: %-10s, hex lower: %-10x, pointer: %p", 123, "456", 123, "456");
	result[33] = ft_printf("integer: %-*.*d, string: %s, hex lower: %-*.*x, pointer: %p", 7, 5, 123, "456", 7, 5, 123, "456");
	result[34] = ft_printf("integer: %*.*d, string: %s, hex lower: %*.*x, pointer: %p", 7, 5, 123, "456", 7, 5, 123, "456");
	*/
	//for(int i = 0; i < n; i++)
	//	printf("%d\n", result[i]);
	//while(1){;};
}
