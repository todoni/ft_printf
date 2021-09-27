CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SOURCES = ft_printf.c ft_atoi.c ft_strlen.c ft_isdigit.c ft_itoa.c ft_calloc.c ft_memset.c heap.c
SRCBONUS = ft_printf.c ft_atoi.c ft_strlen.c ft_isdigit.c ft_itoa.c ft_calloc.c ft_memset.c heap.c

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

