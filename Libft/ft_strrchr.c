/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eballest <eballest@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:28:50 by eballest          #+#    #+#             */
/*   Updated: 2022/09/21 18:25:56 by eballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*r;
	int		len;

	len = (int)ft_strlen(s) + 1;
	while (len--)
	{
		if (s[len] == (char)c)
		{
			r = (char *)&s[len];
			return (r);
		}
	}
	return (NULL);
}
