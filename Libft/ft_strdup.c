/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eballest <eballest@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 18:38:04 by eballest          #+#    #+#             */
/*   Updated: 2022/09/22 19:02:09 by eballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*r;
	size_t	i;

	r = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!r)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s1) + 1)
	{
		r[i] = s1[i];
		i++;
	}
	return (r);
}
