/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eballest <eballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:23:34 by eballest          #+#    #+#             */
/*   Updated: 2023/02/09 18:07:56 by eballest         ###   ########.fr       */
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

int		is_ordered(t_stack *a)
{
    t_element   *aux;

    aux = a->first;
    while (aux->next != NULL)
    {
        if (aux->index < aux->next->index)
            return (-1);
        aux = aux->next;
    }
    return (0);
}

void	proves(t_stack *a, t_stack *b)
{
	write(1, "stack a:\n", 9);
	mostra(a->first);
	write(1, "stack b:\n", 9);
	mostra(b->first);
}

void	mostra(t_element *a)
{
	while (a)
	{
		printf("\nelement: %d\n", a->value);
		printf("ind = %i\n", a->index);
		printf("pos = %i\n", a->position);
		printf("next = %p\n", a->next);
		a = a->next;
	}
	if (a == NULL)
		printf("\n\nHas aplegat al final de la llista\n\n");
}
