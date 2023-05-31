/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eballest <eballest@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 20:52:24 by eballest          #+#    #+#             */
/*   Updated: 2022/09/23 10:53:10 by eballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char			c;

	if (n == -2147483648)
		write(fd, "-2147483648", sizeof(char) * 11);
	else if (n < 0)
	{
		write(fd, "-", sizeof(char));
		n = n * -1;
		ft_putnbr_fd(n, fd);
	}
	else
	{
		if (n > 9)
			ft_putnbr_fd(n / 10, fd);
		c = n % 10 + '0';
		write(fd, &c, sizeof(char));
	}
}
