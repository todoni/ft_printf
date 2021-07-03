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
	zero = 1 << 11,
	minus = 1 << 10,
	precision = 1 << 9,
	asterisk = 1 << 8,
	character = 1 << 7,
	string = 1 << 6,
	pointer = 1 << 5,
	integer = 1 << 4,
	u_integer = 1 << 3,
	hex_low = 1 << 2,
	hex_up = 1 << 1,
	percent = 1 << 0,
	addr_len_fixed = 11
};

typedef	struct s_component
{
	int		width_space;
	int		width_total;
	int		width_padding;
	int		width_prec;
	char	*str;
	int		_int;
	int		flag;
	va_list	ptr;
}				t_component;

#endif
