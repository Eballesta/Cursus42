/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eballest <eballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:43:06 by eballest          #+#    #+#             */
/*   Updated: 2023/02/15 14:54:25 by eballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_element {
	struct s_element	*next;
	struct s_element	*previous;
	int					value;
	int					index;
	int					position;
}	t_element;

typedef struct s_stack {
	int					len;
	struct s_element	*first;
	struct s_element	*last;
}	t_stack;

int			main(int argc, char **argv);
int			control_errors(char **argv, int argc, t_stack *a);
int			save_stack(int *nums, int len, t_stack *a);
void		save_stack2(t_stack *a, t_element *element);
int			get_index(int *nums, int i, int len);

void		initialize_stacks(t_stack *a, t_stack *b);
t_element	*new_element(int value, int index, int position);
int			is_ordered(t_stack *a);

void		sort_stacks(t_stack *a, t_stack *b);
void		sort_stacks2(t_stack *a);
void		sort_stacks3(t_stack *a);
void		sort_stacks4(t_stack *a, t_stack *b);
void		sort_stacks5(t_stack *a, t_stack *b);

void		sort_big_stacks(t_stack *a, t_stack *b);

void		swap(t_stack *a, char *txt);
void		push(t_stack *a, t_stack *b, char *txt);
void		rotate(t_stack *a, char *txt);
void		reverse_rotate(t_stack *a, char *txt);

void    	ss(t_stack *a, t_stack *b);
void    	rr(t_stack *a, t_stack *b);
void    	rrr(t_stack *a, t_stack *b);

//Només per comprovar, s'ha d'esborrar del fitxer push_swap_utils.c
void		mostra(t_element *a);
void		proves(t_stack *a, t_stack *b);

#endif