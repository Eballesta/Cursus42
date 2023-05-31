/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eballest <eballest@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:05:09 by eballest          #+#    #+#             */
/*   Updated: 2022/09/21 17:25:19 by eballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*r;
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			r = (char *)&s[i];
			return (r);
		}
		i++;
	}
	if (s[i] == (char)c)
	{
		r = (char *)&s[i];
		return (r);
	}
	return (NULL);
}
