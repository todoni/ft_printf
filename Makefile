# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sohan <sohan@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/15 05:04:18 by sohan             #+#    #+#              #
#    Updated: 2021/07/15 05:06:02 by sohan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
SOURCES = ft_printf.c
SRCBONUS = ft_printf_bonus.c

all: $(NAME)

bonus:
	make BONUS=1 all

OBJECTS = $(SOURCES:.c=.o)

OBJBONUS = $(SRCBONUS:.c=.o)

ifdef BONUS
$(NAME): $(OBJBONUS)
	ar rc $@ $(OBJBONUS)
else
$(NAME): $(OBJECTS)
	ar rc $@ $(OBJECTS)
endif

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJECTS)
	rm -rf $(OBJBONUS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean
