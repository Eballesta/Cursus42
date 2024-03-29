# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eballest <eballest@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/19 19:16:39 by eballest          #+#    #+#              #
#    Updated: 2023/02/09 18:34:31 by eballest         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
FLAGS = -Wall -Wextra -Werror
SRCS = ft_isalpha.c\
	   ft_isdigit.c\
	   ft_isalnum.c\
	   ft_isascii.c\
	   ft_isprint.c\
	   ft_strlen.c\
	   ft_memset.c\
	   ft_bzero.c\
	   ft_memcpy.c\
	   ft_memmove.c\
	   ft_strlcpy.c\
	   ft_strlcat.c\
	   ft_toupper.c\
	   ft_tolower.c\
	   ft_strchr.c\
	   ft_strrchr.c\
	   ft_strncmp.c\
	   ft_memchr.c\
	   ft_memcmp.c\
	   ft_strnstr.c\
	   ft_atoi.c\
	   ft_calloc.c\
	   ft_strdup.c\
	   ft_striteri.c\
	   ft_strmapi.c\
	   ft_putchar_fd.c\
	   ft_putstr_fd.c\
	   ft_putendl_fd.c\
	   ft_putnbr_fd.c\
	   ft_substr.c\
	   ft_strjoin.c\
	   ft_strtrim.c\
	   ft_split.c\
	   ft_itoa.c

BONUSSRCS = ft_lstnew_bonus.c\
			ft_lstadd_front_bonus.c\
			ft_lstsize_bonus.c\
			ft_lstlast_bonus.c\
			ft_lstadd_back_bonus.c\
			ft_lstdelone_bonus.c\
			ft_lstclear_bonus.c\
			ft_lstiter_bonus.c\
			ft_lstmap_bonus.c

OBJS = $(SRCS:.c=.o)
OBJSBONUS = $(BONUSSRCS:.c=.o)
DEPS = $(SRCS:.c=.d)
DEPSBONUS = $(BONUSSRCS:.c=.d)

GREEN = \033[1;92m
RED = \033[1;91m
NC = \033[0m

%.o : %.c Makefile
	@$(CC) $(FLAGS) -MMD -I./ -c $< -o $@

all: $(NAME)

$(NAME):: $(OBJS)
	@ar -rcs $(NAME) $(OBJS)
	@echo "$(GREEN)libft compiled$(NC)"

$(NAME)::
	@echo -n

-include $(DEPS)
	
bonus:   $(OBJS) $(OBJSBONUS)
		@ar -rcs $(NAME) $(OBJS) $(OBJSBONUS)
		@touch $@

-include $(DEPSBONUS)

clean:
	@rm -f $(OBJS) $(OBJSBONUS) $(DEPS) $(DEPSBONUS)

fclean: clean
	@rm -f $(NAME)
	@rm -f bonus

re: fclean all

.PHONY: all clean fclean re
