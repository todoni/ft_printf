#include <stdio.h>

int	main()
{
	int n = 48;
	int	result[n];
	
	result[0] = printf("%10s\n", "asdf");
	printf("ret : %d\n", result[0]);
	result[1] = printf("%10d\n", 123);
	result[2] = printf("%010d\n", 123);
	result[3] = printf("%-10d\n", 123);
	result[4] = printf("%10x\n", 123);
	result[5] = printf("%010x\n", 123);
	result[6] = printf("%-10x\n", 123);
	result[7] = printf("%10u\n", 123);
	result[8] = printf("%010u\n", 123);
	result[9] = printf("%-10u\n", 123);
	result[10] = printf("%10c\n", 'a');
	result[11] = printf("%-10c\n", 'a');
	result[12] = printf("%15p\n", "123");
	printf("%d\n", result[12]);
	result[13] = printf("my  :%-15p\n", "123");
	//printf("lib :%-11p\n", "123");
	result[14] = printf("%c\n", 'a');
	result[15] = printf("%-c\n", 'a');
	result[14] = printf("%s\n", "asdf");
	result[15] = printf("%d\n", 123);
	result[16] = printf("%d\n", 123);
	result[17] = printf("%-d\n", 123);
	result[18] = printf("%x\n", 123);
	result[19] = printf("%x\n", 123);
	result[20] = printf("%-x\n", 123);
	result[21] = printf("%u\n", 123);
	result[22] = printf("%u\n", 123);
	result[23] = printf("%-u\n", 123);
	//result[24] = printf("%*.*d\n", 7, 10, 123);
	//result[25] = printf("%*.*x\n", 7, 5, 123);
	//result[26] = printf("%*.*u\n", 7, 5, 123);
	//result[27] = printf("%-*.*d\n", 7, 5, 123);
	//result[28] = printf("%-*.*x\n", 7, 5, 123);
	//result[29] = printf("%-*.*u\n", 7, 5, 123);
	result[30] = printf("%#09x\n", 42);
	printf("ret : %d\n", result[30]);
	result[30] = printf("%#09X\n", 42);
	result[30] = printf("%#13.9x\n", 42);
	printf("ret : %d\n", result[30]);
	//result[31] = printf("%#-*.*x\n", 9, 5, 42);
	//result[32] = printf("%#*.*x\n", 9, 5, 42);
	result[33] = printf("%+-10d\n", 42);
	printf("ret : %d\n", result[33]);
	result[34] = printf("%+10d\n", 42);
	result[35] = printf("% -10d\n", 42);
	result[36] = printf("%- 10d\n", 42);
	result[37] = printf("%-5%\n");
	//result[37] = printf("%-5%\n");
	result[38] = printf("%-.0d\n", 42);
	result[39] = printf("\n\n\n\n");
	result[40] = printf("%+5.3d %0.0x %10s\n", 42, 42, "42");
	printf("ret : %d\n", result[40]);
	result[41] = printf("%7.10s %0.0x %10s\n", "424242", 42, "42");
	printf("ret : %d\n", result[41]);
	result[42] = printf("%-7.3s\n", "hello");
	result[43] = printf("%7.3s\n", "hello");
	result[44] = printf("%7.10s\n", "hello");
	result[45] = printf("%++7d\n", 42);
	//result[46] = printf("%d\n", argv[1]);
	//result[46] = printf("%d\n", argv[2]);
	result[30] = printf("integer: %d, string: %s, hex lower: %x, pointer: %p \n", 123, "456", 123, "456");
	result[31] = printf("integer: %10d, string: %10s, hex lower: %10x, pointer: %p\n", 123, "456", 123, "456");
	result[32] = printf("integer: %-10d, string: %-10s, hex lower: %-10x, pointer: %p\n", 123, "456", 123, "456");
	//result[33] = printf("integer: %-*.*d, string: %s, hex lower: %-*.*x, pointer: %p", 7, 5, 123, "456", 7, 5, 123, "456");
	//result[34] = printf("integer: %*.*d, string: %s, hex lower: %*.*x, pointer: %p", 7, 5, 123, "456", 7, 5, 123, "456");
	
	//for(int i = 0; i < n; i++)
	//	printf("%d\n", result[i]);
	//while(1){;};
}
