/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eballest <eballest@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:22:37 by eballest          #+#    #+#             */
/*   Updated: 2022/10/15 18:25:51 by eballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	typeprint(char const *s, int i, va_list arg);

int			ft_printf2(char const *s, int *i, int *len, va_list arg);

int	ft_printf(char const *s, ...)
{
	int		len;
	int		i;
	va_list	arg;
	int		aux;

	va_start(arg, s);
	len = 0;
	i = 0;
	while (s[i] != '\0')
	{
		aux = ft_printf2(s, &i, &len, arg);
		if (aux == -1)
			return (-1);
	}
	va_end(arg);
	return (len);
}

int	ft_printf2(char const *s, int *i, int *len, va_list arg)
{
	int	aux;

	if (s[*i] != '%')
	{
		if (write(1, &s[*i], 1) != 1)
			return (-1);
		*len = *len + 1;
		*i = *i + 1;
	}
	else
	{
		aux = typeprint(s, *i + 1, arg);
		if (aux == -1)
			return (-1);
		*len = *len + aux;
		*i += 2;
	}
	return (0);
}

static int	typeprint(char const *s, int i, va_list arg)
{
	if (s[i] == 'c')
		return (ft_putchar(va_arg(arg, int)));
	else if (s[i] == 's')
		return (ft_putstr(va_arg(arg, char *)));
	else if (s[i] == 'p')
		return (ft_putvoid(va_arg(arg, unsigned long)));
	else if (s[i] == 'd' || s[i] == 'i')
		return (ft_putnbr(va_arg(arg, int)));
	else if (s[i] == 'u')
		return (ft_putusnbr(va_arg(arg, unsigned int)));
	else if (s[i] == 'x')
		return (ft_puthex(va_arg(arg, unsigned int), "0123456789abcdef"));
	else if (s[i] == 'X')
		return (ft_puthex(va_arg(arg, unsigned int), "0123456789ABCDEF"));
	else if (s[i] == '%')
		return (ft_putchar('%'));
	else
		return (-1);
}
