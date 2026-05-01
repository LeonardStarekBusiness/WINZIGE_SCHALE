NAME = minishell
LIBNAME = libft/libft.a

CFLAGGEN = -Wall -Wextra -Werror -g

CC = cc

QUELLE_DATEIEN = utils.c builtins1.c builtins2.c minishell.c

OBJEKT_DATEIEN = $(QUELLE_DATEIEN:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGGEN) -c $< -o $@

libft/libft.a:
	cd libft && make

$(NAME): $(OBJEKT_DATEIEN) libft/libft.a
	$(CC) $(CFLAGGEN) $(OBJEKT_DATEIEN) $(LIBNAME) -o $(NAME)

clean: 
	rm -f $(OBJEKT_DATEIEN)
	cd libft && make clean

fclean: clean 
	rm -f $(NAME)
	rm -f $(LIBNAME)

re: fclean all

.PHONY: all clean flcean re
