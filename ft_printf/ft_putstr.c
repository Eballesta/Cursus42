/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eballest <eballest@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:27:32 by eballest          #+#    #+#             */
/*   Updated: 2022/10/15 18:04:27 by eballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static ssize_t	ft_strlen1(char *s)
{
	ssize_t	i;

	i = 0;
	while (s[i] != 0)
	{
		i++;
	}
	return (i);
}

int	ft_putstr(char *s)
{
	if (!s)
		return (write(1, "(null)", 6));
	if (write(1, s, ft_strlen1(s)) != ft_strlen1(s))
		return (-1);
	return ((int)ft_strlen1(s));
}
