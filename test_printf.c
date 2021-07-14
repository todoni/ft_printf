/*                                                        :::      ::::::::   */
/*   test_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohan <sohan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 17:13:35 by sohan             #+#    #+#             */
/*   Updated: 2021/06/29 17:13:37 by sohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	arr[6] = {1234, 3, 1, 123, 12, 1};
	int	flags;
	int flag = 4112;
	int test = 1 << 12;
	char *str = "123\nasf";
	char str2 = 'a';

	flags = 0b0011;
	printf("%d\n", (flag & test));
	printf("%d\n", (int)strlen(str));
	printf("%d\n", (flag & test) * (int)strlen(str));
	printf("%d\n", flags << 4);
	printf("%-10c\n", str2);
	printf("%015d\n", 1234);
	printf("%0*d\n", 5, arr[1]);
	printf("%5d\n", arr[2]);
	printf("%.5d\n", arr[3]);
	printf("%-*.0d\n", 10, arr[4]);
	printf("%-.5d\n", arr[5]);
	printf("%#10.5X\n", 42);
	printf("%s\n", "asdfg");
	printf("%*.*d\n", 7, 5, 123);
	printf("%*.*x\n", 7, 5, 123);
	printf("%*.*u\n", 7, 5, 123);
	printf("-*.*abc%+-*.*defg*.*%#-10.5xhi%+-7.5%\n", 7, 5, 123, 42);
	printf("%.d", 123);
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	printf("\\");
	return (0);
}
