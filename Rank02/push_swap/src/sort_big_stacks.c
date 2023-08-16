/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stacks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eballest <eballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:08:32 by eballest          #+#    #+#             */
/*   Updated: 2023/08/15 16:04:35 by eballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_to_b(t_stack *a, t_stack *b, int max_index, int chunk_size)
{
	push(b, a, "pb\n");
	if (chunk_size > 20)
	{
		if (b->first->index < (max_index - (chunk_size / 2)))
			rotate(b, "rb\n");
	}
}

void	move_to_a(t_stack *a, t_stack *b)
{
	while (b->first)
	{
		if (b->len == 1)
			push(a, b, "pa\n");
		else if (relative_pos(b, b->len - 2) < relative_pos(b, b->len - 1))
		{
			push_element(b, b->len - 2, 'b');
			push(a, b, "pa\n");
			push_element(b, b->len, 'b');
			push(a, b, "pa\n");
			swap(a, "sa\n");
		}
		else
		{
			push_element(b, b->len - 1, 'b');
			push(a, b, "pa\n");
		}
	}
}

void	push_element(t_stack *stack, int index, char s)
{
	int	position;

	position = pos_element(stack, index);
	if (position == -1)
		return ;
	while (position != 0)
	{
		if (position < stack->len / 2 && s == 'a')
			rotate(stack, "ra\n");
		else if (position < stack->len / 2 && s == 'b')
			rotate(stack, "rb\n");
		else if (s == 'a')
			reverse_rotate(stack, "rra\n");
		else if (s == 'b')
			reverse_rotate(stack, "rrb\n");
		position = pos_element(stack, index);
	}
}

int	relative_pos(t_stack *a, int index)
{
	int	rel_pos;
	int	position;

	position = pos_element(a, index);
	if (position < a->len / 2)
		rel_pos = position;
	else
		rel_pos = a->len - position;
	return (rel_pos);
}

int	pos_element(t_stack *a, int index)
{
	t_element	*aux;

	aux = a->first;
	while (aux)
	{
		if (aux->index == index)
			return (aux->position);
		aux = aux->next;
	}
	return (-1);
}
