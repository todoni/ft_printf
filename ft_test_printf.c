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
#include "ft_printf.h"

int	main(int argc, char **argv)
{
	int	arr[6] = {1234, 3, 1, 123, 12, 1};
	int	flags;
	int flag = 4112;
	int test = 1 << 12;
	char *str = "123";
	char str2 = 'a';

	flags = 0b0011;
	ft_printf("%-10c\n", str2);
	ft_printf("%015d\n", 1234);
	ft_printf("%0*d\n", 5, arr[1]);
	ft_printf("%5d\n", arr[2]);
	ft_printf("%.5d\n", arr[3]);
	ft_printf("%-*.0d\n", 10, arr[4]);
	ft_printf("%-.5d\n", arr[5]);
	ft_printf("%#10.5X\n", 42);
	ft_printf("%s\n", "asdfg");
	ft_printf("%*.*d\n", 7, 5, 123);
	ft_printf("%*.*x\n", 7, 5, 123);
	ft_printf("%*.*u\n", 7, 5, 123);
	ft_printf("-*.*abc%+-*.*defg*.*%#-10.5xhi%+-7.5%\n", 7, 5, 123, 42);
	ft_printf("%.d", 123);
	return (0);
}
