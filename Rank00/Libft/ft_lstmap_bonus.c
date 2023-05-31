/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eballest <eballest@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:12:19 by eballest          #+#    #+#             */
/*   Updated: 2022/10/03 18:03:46 by eballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*cpy;
	t_list	*node;
	void	*aux;

	if (!lst)
		return (NULL);
	cpy = NULL;
	while (lst)
	{
		aux = f(lst->content);
		node = ft_lstnew(aux);
		if (node == NULL)
		{
			del(aux);
			ft_lstclear(&cpy, del);
			return (NULL);
		}
		ft_lstadd_back(&cpy, node);
		lst = lst->next;
	}
	return (cpy);
}
