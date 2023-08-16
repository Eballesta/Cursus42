/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eballest <eballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:19:42 by eballest          #+#    #+#             */
/*   Updated: 2023/06/02 15:58:12 by eballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack *a, t_stack *b)
{
	swap(a, "");
	swap(b, "");
	write(1, "ss\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a, "");
	rotate(b, "");
	write(1, "rr\n", 3);
}

void	rrr(t_stack *a, t_stack *b)
{
	reverse_rotate(a, "");
	reverse_rotate(b, "");
	write(1, "rrr\n", 4);
}
