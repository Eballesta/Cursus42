/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eballest <eballest@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 11:37:07 by eballest          #+#    #+#             */
/*   Updated: 2022/09/23 11:59:44 by eballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*r;
	size_t	size;
	size_t	f1;

	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	r = (char *)malloc(sizeof(char) * size);
	if (!r)
		return (NULL);
	f1 = ft_strlcpy(r, s1, ft_strlen(s1) + 1);
	f1 = ft_strlcat(r, s2, size);
	return (r);
}
