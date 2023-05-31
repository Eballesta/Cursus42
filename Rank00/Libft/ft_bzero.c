/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eballest <eballest@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:24:09 by eballest          #+#    #+#             */
/*   Updated: 2022/09/20 16:34:52 by eballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t len)
{
	unsigned long	i;
	unsigned char	*c;

	i = 0;
	c = (unsigned char *)s;
	while (i < len)
	{
		c[i] = 0;
		i++;
	}
}
