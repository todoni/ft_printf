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
# define USED 1
# define FIRST -1

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
	x_base_mask = 0b00000000100100,
	malloc_free = 0b00000000111110,
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
	POINTER,
	CHAR,
	PRECISION
};

typedef	struct	s_component
{
	int		width_space;
	int		width_total;
	int		width_padding;
	int		width_precision;
	int		width_flag;
	int		width_str;
	char	*str;
	int		_int;
	int		_uint;
	unsigned long long int		_pointer;
	int		flag;
}				t_component;

typedef struct	s_functions
{
	void	(*print_space)(int length, int *ret);
	void	(*print_padding)(int length, int *ret);
	void	(*print_precision)(int length, int *ret);
	void	(*print)(int *ret);
	void	(*print_string)(char *fmt, int length, int *ret);
	void	(*print_char)(int c, int *ret);
	void	(*print_sign)(int sign, int *ret);
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
int	ft_vprintf(const char *fmt, va_list arg_ptr, int ret);
char *ft_itoa(int num, char *base);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);

#endif
