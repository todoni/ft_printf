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
#ifndef	PSUEDO_PRINTF_H
# define	PSUEDO_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# define NOT_USED -1
# define USED 0
# define FIRST 0

enum	e_mask
{
	zero = 1 << 13,
	minus = 1 << 12,
	plus = 1 << 11,
	space = 1 << 10,
	sharp = 1 << 9,
	precision = 1 << 8,
	character = 1 << 7,
	string = 1 << 6,
	pointer = 1 << 5,
	integer = 1 << 4,
	u_integer = 1 << 3,
	hex_low = 1 << 2,
	hex_up = 1 << 1,
	percent = 1 << 0,
	int_mask = 0b00000010011110,
	int_base_mask = 0b00000000011000,
	x_base_mask = 0b00000000100110,
	pointer_len_fixed = 11
};

enum	e_funtions
{
	ARGUMENT,
	SPACE,
	ONESPACE,
	PLUS,
	SHARPUP,
	SHARPLOW,
	ZERO,
	POINTER
};

typedef	struct	s_component
{
	int		width_space;
	int		width_total;
	int		width_padding;
	int		width_precision;
	int		width_flag;
	char	*str;
	long long int		_int;
	int		flag;
}				t_component;

typedef struct	s_functions
{
	void	(*print_l)(int length);
	void	(*print)();
	void		(*print_untyped)(char *fmt, int ret);
	int		usage;
	int		priority;
}				t_fp;

/*typedef struct	s_function_node
{
	t_fp	fp;
	int		priority;
}				t_heapnode;

typedef struct	s_heap
{
	t_heapnode *nodes;
	int	size;
}				t_heap;
*/
int	ft_isdigit(char c);
int	ft_atoi(const char *str);
int	ft_strlen(char *str);
int	ft_printf(const char *fmt, ...);
char *ft_itoa(int num, char *base);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);

#endif
