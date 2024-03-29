/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eballest <eballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:50:43 by eballest          #+#    #+#             */
/*   Updated: 2023/02/09 18:32:58 by eballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	convertirint(char *str, double *j);

int	ft_atoi(const char *str)
{
	int		pos;
	int		num;
	double	i;
	double	*j;
	char	*s;

	s = (char *)str;
	num = 0;
	j = &i;
	pos = 0;
	while (*s == ' ' || (*s <= 13 && *s >= 9))
		s++;
	if (*s == '-')
	{
		pos = 1;
		s++;
	}
	else if (*s == '+')
		s++;
	if (*s >= '0' && *s <= '9')
		num = convertirint(s, j);
	if (pos == 1)
		num = -num;
	return (num);
}

int	convertirint(char *str, double *j)
{
	int	aux;
	int	aux2;

	if (*str > '9' || *str < '0')
	{
		*j = 0.1;
		return (0);
	}
	else
	{
		aux2 = *str - 48;
		str++;
		aux = convertirint(str, j);
		*j = *j * 10;
		return (aux + (aux2 * *j));
	}
}
