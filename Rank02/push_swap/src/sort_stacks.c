/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eballest <eballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:58:15 by eballest          #+#    #+#             */
/*   Updated: 2023/07/28 20:04:59 by eballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stacks(t_stack *a, t_stack *b)
{
	if (a->len == 1 || is_ordered(a) == 0)
		return ;
	if (a->len == 2)
	{
		if (a->first->index > a->last->index)
			swap(a, "sa\n");
	}
	else if (a->len == 3)
		sort_stacks3(a);
	else if (a->len == 4)
		sort_stacks4(a, b);
	else if (a->len == 5)
		sort_stacks5(a, b);
	else if (a->len < 200)
		sort_big_stacks(a, b, 3, a->len);
	else
		sort_big_stacks(a, b, 8, a->len);
}

void	sort_stacks3(t_stack *a)
{
	if (a->first->index == max_stack(a))
		rotate(a, "ra\n");
	else if (a->first->next->index == max_stack(a))
		reverse_rotate(a, "rra\n");
	if (a->first->index < max_stack(a) && \
	a->first->index > min_stack(a))
		swap(a, "sa\n");
}

void	sort_stacks4(t_stack *a, t_stack *b)
{
	if (a->first->next->index == min_stack(a))
		swap(a, "sa\n");
	else if (a->first->next->next->index == min_stack(a))
		reverse_rotate(a, "rra\n");
	if (a->last->index == min_stack(a))
		reverse_rotate(a, "rra\n");
	if (is_ordered(a) == 0)
		return ;
	push(b, a, "pb\n");
	sort_stacks3(a);
	push(a, b, "pa\n");
}

void	sort_stacks5(t_stack *a, t_stack *b)
{
	if (a->first->next->index == min_stack(a))
		swap(a, "sa\n");
	else if (a->first->next->next->index == min_stack(a))
		reverse_rotate(a, "rra\n");
	if (a->first->next->next->next->index == min_stack(a))
		reverse_rotate(a, "rra\n");
	if (a->first->next->next->next->next->index == min_stack(a))
		reverse_rotate(a, "rra\n");
	push(b, a, "pb\n");
	sort_stacks4(a, b);
	push(a, b, "pa\n");
}

void	sort_big_stacks(t_stack *a, t_stack *b, int chunks, int size)
{
	int		i;
	int		j;
	int		size_aux;
	int		max_index;
	int		chunk_size;

	chunk_size = size / chunks;
	i = 1;
	while (a->first)
	{
		size_aux = a->len;
		max_index = (chunk_size) * i;
		j = 0;
		while (a->first && j < size_aux)
		{
			if (a->first->index < max_index)
				move_to_b(a, b, max_index, chunk_size);
			else
				rotate(a, "ra\n");
			j++;
		}
		i++;
	}
	move_to_a(a, b);
}
