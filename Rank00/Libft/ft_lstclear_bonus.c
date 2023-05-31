/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eballest <eballest@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:59:46 by eballest          #+#    #+#             */
/*   Updated: 2022/10/03 17:28:53 by eballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux;
	t_list	*start;

	if (!lst)
		return ;
	start = *lst;
	while (start != NULL)
	{
		aux = start->next;
		del(start->content);
		free(start);
		start = aux;
	}
	*lst = NULL;
}
