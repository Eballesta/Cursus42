/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putvoid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eballest <eballest@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:43:40 by eballest          #+#    #+#             */
/*   Updated: 2022/10/15 19:30:41 by eballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	canviarbase(unsigned long nbr, char *base, int *len);

int	ft_putvoid(unsigned long nbr)
{
	int	len;

	if (ft_putstr("0x") != 2)
		return (-1);
	len = 3;
	canviarbase(nbr, "0123456789abcdef", &len);
	return (len);
}

static void	canviarbase(unsigned long nbr, char *base, int *len)
{
	if (nbr > 15)
	{
		if (*len != -1)
		{
			*len = *len + 1;
			canviarbase(nbr / 16, base, len);
		}
	}
	if (*len != -1)
	{
		if (write(1, &base[nbr % 16], 1) != 1)
			*len = -1;
	}
}
