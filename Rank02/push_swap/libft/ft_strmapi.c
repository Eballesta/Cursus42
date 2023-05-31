/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eballest <eballest@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 19:53:43 by eballest          #+#    #+#             */
/*   Updated: 2022/09/22 20:17:57 by eballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*c;

	if (!s || !f)
		return (0);
	c = ft_strdup(s);
	if (!c)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s))
	{
		c[i] = f(i, c[i]);
		i++;
	}
	return (c);
}
