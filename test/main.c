#include "ft_printf.h"
#include "heap.h"

int	main()
{
	int n = 48;
	int	result[n];
	
	result[0] = ft_printf("%10s\n", "asdf");
	ft_printf("ret : %d\n", result[0]);
	//printf("ret : %d\n", result[0]);
	result[1] = ft_printf("%10d", 123);
	result[2] = ft_printf("%010d", 123);
	result[3] = ft_printf("%-10d\n", 123);
	result[4] = ft_printf("%10x\n", 123);
	result[5] = ft_printf("%010x\n", 123);
	result[6] = ft_printf("%-10x\n", 123);
	result[7] = ft_printf("%10u\n", 123);
	result[8] = ft_printf("%010u\n", 123);
	result[9] = ft_printf("%-10u\n", 123);
	result[10] = ft_printf("%10c\n", 'a');
	result[11] = ft_printf("%-10c\n", 'a');
	result[12] = ft_printf("%15p\n", "123");
	ft_printf("%d\n", result[12]);
	result[13] = ft_printf("my  :%-15p\n", "123");
	//ft_printf("lib :%-11p\n", "123");
	result[14] = ft_printf("%c\n", 'a');
	result[15] = ft_printf("%-c\n", 'a');
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
	//result[24] = ft_printf("%*.*d\n", 7, 10, 123);
	//result[25] = ft_printf("%*.*x\n", 7, 5, 123);
	//result[26] = ft_printf("%*.*u\n", 7, 5, 123);
	//result[27] = ft_printf("%-*.*d\n", 7, 5, 123);
	//result[28] = ft_printf("%-*.*x\n", 7, 5, 123);
	//result[29] = ft_printf("%-*.*u\n", 7, 5, 123);
	result[30] = ft_printf("%#09x\n", 42);
	ft_printf("ret : %d\n", result[30]);
	result[30] = ft_printf("%#09X\n", 42);
	result[30] = ft_printf("%#13.9x\n", 42);
	ft_printf("ret : %d\n", result[30]);
	//result[31] = ft_printf("%#-*.*x\n", 9, 5, 42);
	//result[32] = ft_printf("%#*.*x\n", 9, 5, 42);
	result[33] = ft_printf("%+-10d\n", 42);
	ft_printf("ret : %d\n", result[33]);
	result[34] = ft_printf("%+10d\n", 42);
	result[35] = ft_printf("% -10d\n", 42);
	result[36] = ft_printf("%- 10d\n", 42);
	result[37] = ft_printf("%-5%\n");
	//result[37] = ft_printf("%-5%\n");
	result[38] = ft_printf("%-.0d\n", 42);
	result[39] = ft_printf("\n\n\n\n");
	result[40] = ft_printf("%+5.3d %0.0x %10s\n", 42, 42, "42");
	ft_printf("ret : %d\n", result[40]);
	result[41] = ft_printf("%7.10s %0.0x %10s\n", "424242", 42, "42");
	ft_printf("ret : %d\n", result[41]);
	result[42] = ft_printf("%-7.3s\n", "hello");
	result[43] = ft_printf("%7.3s\n", "hello");
	result[44] = ft_printf("%7.10s\n", "hello");
	result[45] = ft_printf("%++7d\n", 42);
	//result[46] = ft_printf("%d\n", argv[1]);
	//result[46] = ft_printf("%d\n", argv[2]);
	result[30] = ft_printf("integer: %d, string: %s, hex lower: %x, pointer: %p \n", 123, "456", 123, "456");
	result[31] = ft_printf("integer: %10d, string: %10s, hex lower: %10x, pointer: %p\n", 123, "456", 123, "456");
	result[32] = ft_printf("integer: %-10d, string: %-10s, hex lower: %-10x, pointer: %p\n", 123, "456", 123, "456");
	//result[33] = ft_printf("integer: %-*.*d, string: %s, hex lower: %-*.*x, pointer: %p", 7, 5, 123, "456", 7, 5, 123, "456");
	//result[34] = ft_printf("integer: %*.*d, string: %s, hex lower: %*.*x, pointer: %p", 7, 5, 123, "456", 7, 5, 123, "456");
	
	//for(int i = 0; i < n; i++)
	//	ft_printf("%d\n", result[i]);
	//while(1){;};
	system("leaks a.out");
}
