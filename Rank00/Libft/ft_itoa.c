/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eballest <eballest@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:40:30 by eballest          #+#    #+#             */
/*   Updated: 2022/09/26 18:35:04 by eballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_len(int n)
{
	int	len;

	if (n == 0)
		return (1);
	if (n < 0)
		n = -n;
	len = 0;
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

void	putnbr(char *r, int n, int i, int len)
{
	if (n < 0)
		n = -n;
	r[len] = '\0';
	len--;
	while (len >= i)
	{
		r[len] = n % 10 + '0';
		n = n / 10;
		len--;
	}
}

char	*ft_itoa(int n)
{
	int		len;
	char	*r;
	int		i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = count_len(n);
	i = 0;
	if (n < 0)
	{
		len = len + 1;
		i = 1;
	}
	r = (char *)malloc(sizeof(char) * (len + 1));
	if (!r)
		return (NULL);
	putnbr(r, n, i, len);
	if (n < 0)
		r[0] = '-';
	return (r);
}
