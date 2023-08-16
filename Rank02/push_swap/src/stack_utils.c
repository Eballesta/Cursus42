/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eballest <eballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:23:34 by eballest          #+#    #+#             */
/*   Updated: 2023/07/12 16:24:41 by eballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize_stacks(t_stack *a, t_stack *b)
{
	a->len = 0;
	a->first = NULL;
	a->last = NULL;
	b->len = 0;
	b->first = NULL;
	b->last = NULL;
}

t_element	*new_element(int value, int index, int position)
{
	t_element	*element;

	element = NULL;
	element = malloc(sizeof(t_element));
	if (!element)
		return (NULL);
	element->value = value;
	element->index = index;
	element->position = position;
	element->previous = NULL;
	element->next = NULL;
	return (element);
}

int	is_ordered(t_stack *a)
{
	t_element	*aux;

	aux = a->first;
	while (aux->next != NULL)
	{
		if (aux->value > aux->next->value)
			return (-1);
		aux = aux->next;
	}
	return (0);
}

int	min_stack(t_stack *a)
{
	t_element	*aux;
	int			min;

	min = a->first->index;
	aux = a->first->next;
	while (aux != NULL)
	{
		if (aux->index < min)
			min = aux->index;
		aux = aux->next;
	}
	return (min);
}

int	max_stack(t_stack *a)
{
	t_element	*aux;
	int			max;

	max = a->first->index;
	aux = a->first->next;
	while (aux != NULL)
	{
		if (aux->index > max)
			max = aux->index;
		aux = aux->next;
	}
	return (max);
}
