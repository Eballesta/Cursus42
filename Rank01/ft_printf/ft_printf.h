/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eballest <eballest@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:02:25 by eballest          #+#    #+#             */
/*   Updated: 2022/10/18 15:34:24 by eballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(char const *s, ...);
int	ft_putchar(int c);
int	ft_putstr(char *s);
int	ft_putvoid(unsigned long nbr);
int	ft_putnbr(int n);
int	ft_putusnbr(unsigned int n);
int	ft_puthex(unsigned int nbr, char *base);

#endif
