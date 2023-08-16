# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eballest <eballest@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/08 17:11:25 by eballest          #+#    #+#              #
#    Updated: 2023/08/16 10:12:58 by eballest         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CFLAGS = -Wall -Wextra -Werror
SRCS = 	push_swap.c\
		src/stack_utils.c\
		src/sort_stacks.c\
		src/sort_big_stacks.c\
		src/operations.c\
		src/double_operations.c\
		src/utils.c

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
	@echo "$(GREEN)Compiled$(NC)"

$(NAME)::
	@echo -n

-include $(DEPS)

clean:
	@rm -f $(OBJS) $(DEPS)
	@$(MAKE) clean -C libft
	@echo "$(RED)Successfuly clean$(NC)"

fclean: clean
	@rm -f $(NAME) $(LIBFT)

re: fclean all

.PHONY: all clean fclean re

