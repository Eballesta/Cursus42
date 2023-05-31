/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eballest <eballest@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:46:36 by eballest          #+#    #+#             */
/*   Updated: 2022/10/15 19:32:54 by eballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	canviarbase(unsigned int nbr, char *base, int *len);

int	ft_puthex(unsigned int nbr, char *base)
{
	int				len;

	len = 1;
	canviarbase(nbr, base, &len);
	return (len);
}

static void	canviarbase(unsigned int nbr, char *base, int *len)
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
