/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eballest <eballest@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 10:56:39 by eballest          #+#    #+#             */
/*   Updated: 2022/09/23 11:33:19 by eballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*c;
	size_t	i;

	if (len == 0 || start >= ft_strlen(s))
	{
		c = (char *)malloc(1 * sizeof(char));
		if (!c)
			return (NULL);
		c[0] = '\0';
		return (c);
	}
	if (ft_strlen(s) - start > len)
		c = (char *)malloc((len + 1) * sizeof(char));
	else
		c = (char *)malloc((ft_strlen(s) + 1 - start) * sizeof(char));
	if (!c)
		return (NULL);
	i = 0;
	while (i++ < len && s[start] != '\0')
	{
		c[i - 1] = s[start];
		start++;
	}
	c[i - 1] = '\0';
	return (c);
}
