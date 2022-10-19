/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eballest <eballest@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:36:00 by eballest          #+#    #+#             */
/*   Updated: 2022/10/15 18:24:08 by eballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr2(int n, int *len);

int	ft_putnbr(int n)
{
	int		len;

	len = 1;
	if (n == -2147483648)
	{
		if (write(1, "-2147483648", 11) != 11)
			return (-1);
		else
			return (11);
	}
	else if (n < 0)
	{
		if (write(1, "-", 1) != 1)
			return (-1);
		n = n * -1;
		len++;
	}
	ft_putnbr2(n, &len);
	return (len);
}

static void	ft_putnbr2(int n, int *len)
{
	char	c;

	if (n > 9)
	{
		if (*len != -1)
		{
			*len = *len + 1;
			ft_putnbr2(n / 10, len);
		}
	}
	c = n % 10 + '0';
	if (*len != -1)
	{
		if (write(1, &c, 1) != 1)
			*len = -1;
	}
}
