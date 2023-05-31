# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eballest <eballest@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/06 16:56:54 by eballest          #+#    #+#              #
#    Updated: 2022/10/15 19:34:37 by eballest         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRCS = ft_printf.c ft_putchar.c ft_putstr.c ft_putvoid.c ft_putnbr.c ft_putusnbr.c ft_puthex.c

OBJS = $(SRCS:.c=.o)
HEADER = ft_printf.h

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME);

$(NAME) : $(OBJS) $(HEADER)
	ar -rcs $(NAME) $(OBJS)
	
clean:
	rm -f $(OBJS) $(OBJSBONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
