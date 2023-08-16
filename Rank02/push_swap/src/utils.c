/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eballest <eballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:23:34 by eballest          #+#    #+#             */
/*   Updated: 2023/08/16 10:13:17 by eballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_free(void *pointer)
{
	if (pointer)
		free(pointer);
	return (-1);
}

int	free_stacks(t_stack *a)
{
	t_element	*aux;

	while (a->first)
	{
		aux = a->first->next;
		free(a->first);
		a->first = aux;
	}
	return (-1);
}

int	correct_number(char *str)
{
	int	i;
	int	len;
	int	sign;

	sign = 1;
	len = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] <= 13 && str[i] >= 9))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] >= 48 && str[i] <= 57)
			len++;
		else
			return (-1);
		i++;
	}
	return (correct_number2(str, sign, len));
}

int	correct_number2(char *str, int sign, int len)
{
	long int	num;

	num = ft_atol(str, sign);
	if (len > 10)
		return (-1);
	if (num > 2147483647 || num < -2147483648)
		return (-1);
	return (0); 
}

long int	ft_atol(char *str, int sign)
{
	int			i;
	long int	res;

	i = 0;
	if (sign < 0)
		i = 1;
	res = 0;
	while (str[i])
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	res = res * sign;
	return (res);
}
