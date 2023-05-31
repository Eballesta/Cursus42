/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eballest <eballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:58:15 by eballest          #+#    #+#             */
/*   Updated: 2023/02/15 14:56:04 by eballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stacks(t_stack *a, t_stack *b)
{
	if (a->len == 2)
		sort_stacks2(a);
	else if (a->len == 3)
		sort_stacks3(a);
	//else if (a->len == 4)
		//sort_stacks4(a, b);
	//else if (a->len == 5)
		//sort_stacks5(a, b);
	else
		write(1, "sort big\n", 9);
		//sort_big_stacks(a, b);
	proves(a, b);
}

void	sort_stacks2(t_stack *a)
{
	if (a->first->index > a->last->index)
		swap(a, "sa\n");
}

void	sort_stacks3(t_stack *a)
{
	if (a->first->index == 3)
		rotate(a, "ra\n");
	else if (a->first->next->index == 3)
		reverse_rotate(a, "rra\n");
	if (a->first->index == 2)
		swap(a, "sa\n");
}

void	sort_stacks4(t_stack *a, t_stack *b)
{
	proves(a, b);
}

void	sort_stacks5(t_stack *a, t_stack *b)
{
	proves(a, b);
}
