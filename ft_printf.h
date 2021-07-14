/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohan <sohan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 13:40:41 by sohan             #+#    #+#             */
/*   Updated: 2021/07/02 13:40:42 by sohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_PRINTF_H
# define	FT_PRINTF_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

enum	e_flags
{
	zero = 1 << 15,
	minus = 1 << 14,
	plus = 1 << 13,
	space = 1 << 12,
	sharp = 1 << 11,
	precision = 1 << 10,
	asterisk1 = 1 << 9,
	asterisk2 = 1 << 8,
	character = 1 << 7,
	string = 1 << 6,
	pointer = 1 << 5,
	integer = 1 << 4,
	u_integer = 1 << 3,
	hex_low = 1 << 2,
	hex_up = 1 << 1,
	percent = 1 << 0,
	malloc_free = 0b0000000000111110,
	pointer_len_fixed = 11
};

typedef	struct s_component
{
	int		width_space;
	int		width_total;
	int		width_padding;
	int		width_precision;
	char	*str;
	int		_int;
	int		flag;
}				t_component;

int	ft_printf(const char *fmt, ...);
#endif
