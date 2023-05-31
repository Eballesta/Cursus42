# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eballest <eballest@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/08 17:11:25 by eballest          #+#    #+#              #
#    Updated: 2023/02/09 18:34:18 by eballest         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CFLAGS = -Wall -Wextra -Werror
SRCS = push_swap.c push_swap_utils.c sort_stacks.c sort_big_stacks.c operations.c double_operations.c

OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)
LIBFT = libft/libft.a

GREEN = \033[1;92m
RED = \033[1;91m
NC = \033[0m

%.o : %.c $(LIBFT) Makefile
	@$(CC) $(CFLAGS) -MMD -I./ -c $< -o $@

all: 
	@$(MAKE) -C libft
	@$(MAKE) $(NAME)

$(NAME):: $(OBJS)
	@$(CC) $(OBJS) $(LIBFT) -o $@
	@echo "$(GREEN)push_swap compiled$(NC)"

$(NAME)::
	@echo -n

-include $(DEPS)

clean:
	@rm -f $(OBJS) $(DEPS)
	@$(MAKE) clean -C libft
	@echo "$(RED)\nDestruction successful\n$(NC)"

fclean: clean
	@rm -f $(NAME) $(LIBFT)

re: fclean all

.PHONY: all clean fclean re

