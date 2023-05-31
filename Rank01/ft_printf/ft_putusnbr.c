/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putusnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eballest <eballest@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:30:20 by eballest          #+#    #+#             */
/*   Updated: 2022/10/15 19:36:52 by eballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putusnbr2(unsigned int n, int *len);

int	ft_putusnbr(unsigned int n)
{
	int		len;

	len = 1;
	ft_putusnbr2(n, &len);
	return (len);
}

static void	ft_putusnbr2(unsigned int n, int *len)
{
	char	c;

	if (n > 9)
	{
		if (*len != -1)
		{
			*len = *len + 1;
			ft_putusnbr2(n / 10, len);
		}
	}
	c = n % 10 + '0';
	if (*len != -1)
	{
		if (write(1, &c, 1) == -1)
			*len = -1;
	}
}
