/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eballest <eballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:45:06 by eballest          #+#    #+#             */
/*   Updated: 2023/02/09 17:24:21 by eballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *a, char *txt)
{
	t_element	*aux;

	if (a->len > 1)
	{
		aux = a->first;
		a->first = a->first->next;
		aux->next = a->first->next;
		a->first->next = aux;
		a->first->previous = NULL;
		aux->previous = a->first;
		aux->next->previous = aux;
	}
	if (a->len == 2)
		a->last = aux;
	write(1, txt, ft_strlen(txt));
}

//Primer element de b a dalt de a
void	push(t_stack *a, t_stack *b, char *txt)
{
	t_element	*aux;

	if (b->len > 0)
	{
		aux = b->first;
		b->first = b->first->next;
		b->first->previous = NULL;
		aux->next = a->first;
		a->first->previous = aux;
		a->first = aux;
		a->len += 1;
		b->len -= 1;
	}
	write(1, txt, ft_strlen(txt));
}

void	rotate(t_stack *a, char *txt)
{
	t_element	*aux;

	if (a->len > 1)
	{
		aux = a->first;
		a->first = a->first->next;
		a->first->previous = NULL;
		a->last->next = aux;
		aux->next = NULL;
		aux->previous = a->last;
		a->last = aux;
	}
	write(1, txt, ft_strlen(txt));
}

void	reverse_rotate(t_stack *a, char *txt)
{
	t_element	*aux;

	if (a->len > 1)
	{
		aux = a->last;
		a->last = aux->previous;
		aux->previous = NULL;
		a->last->next = NULL;
		a->first->previous = aux;
		aux->next = a->first;
		a->first = aux;
	}
	write(1, txt, ft_strlen(txt));
}
