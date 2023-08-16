/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eballest <eballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:45:06 by eballest          #+#    #+#             */
/*   Updated: 2023/08/15 12:44:39 by eballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *a, char *txt)
{
	int	aux_value;
	int	aux_index;

	if (a->len <= 1)
		return ;
	aux_value = a->first->value;
	aux_index = a->first->index;
	a->first->value = a->first->next->value;
	a->first->index = a->first->next->index;
	a->first->next->value = aux_value;
	a->first->next->index = aux_index;
	write(1, txt, ft_strlen(txt));
}

void	push(t_stack *a, t_stack *b, char *txt)
{
	t_element	*aux;

	if (b->len <= 0)
		return ;
	aux = b->first;
	b->first = aux->next;
	if (b->first)
		b->first->previous = NULL;
	else
		b->last = NULL;
	if (a->len > 0)
		a->first->previous = aux;
	aux->next = a->first;
	a->first = aux;
	if (a->len == 0)
		a->last = aux;
	a->len++;
	b->len--;
	move_position(a);
	move_position(b);
	write(1, txt, ft_strlen(txt));
}

void	rotate(t_stack *a, char *txt)
{
	t_element	*aux;
	int			aux_value;
	int			aux_index;

	if (a->len <= 1)
		return ;
	aux_value = a->first->value;
	aux_index = a->first->index;
	aux = a->first;
	while (aux->next != NULL)
	{
		aux->value = aux->next->value;
		aux->index = aux->next->index;
		aux = aux->next;
	}
	aux->value = aux_value;
	aux->index = aux_index;
	write(1, txt, ft_strlen(txt));
}

void	reverse_rotate(t_stack *a, char *txt)
{
	t_element	*aux;
	int			aux_value;
	int			aux_index;

	if (a->len <= 1)
		return ;
	aux_value = a->last->value;
	aux_index = a->last->index;
	aux = a->last;
	while (aux->previous != NULL)
	{
		aux->value = aux->previous->value;
		aux->index = aux->previous->index;
		aux = aux->previous;
	}
	aux->value = aux_value;
	aux->index = aux_index;
	write(1, txt, ft_strlen(txt));
}

void	move_position(t_stack *a)
{
	t_element	*aux;
	int			i;

	aux = a->first;
	i = 0;
	while (aux)
	{
		aux->position = i;
		aux = aux->next;
		i++;
	}
}
