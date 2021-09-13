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

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# define NOT_USED -1
# define USED 0

enum	e_mask
{
	zero = 1 << 12,
	minus = 1 << 11,
	plus = 1 << 10,
	space = 1 << 9,
	sharp = 1 << 8,
	character = 1 << 7,
	string = 1 << 6,
	pointer = 1 << 5,
	integer = 1 << 4,
	u_integer = 1 << 3,
	hex_low = 1 << 2,
	hex_up = 1 << 1,
	percent = 1 << 0,
	int_mask = 0b0000010011110,
	int_base_mask = 0b0000000011000,
	x_base_mask = 0b0000000100110,
	pointer_len_fixed = 11
};

typedef	struct	s_component
{
	int		width_space;
	int		width_total;
	int		width_padding;
	int		width_precision;
	char	*str;
	long long int		_int;
	int		flag;
}				t_component;

typedef struct	s_function_node
{
	struct t_fp fp;
	int		priority;
}				t_heapnode;

typedef struct	s_heap
{
	t_heapnode *nodes;
	int	size;
}				t_heap;

typedef struct	s_functions
{
	void	(*print l)(int length);
	void	(*print);
	int		(*print untyped)(const char *fmt, int ret);
	int		usage;
}				t_fp;

#endif
