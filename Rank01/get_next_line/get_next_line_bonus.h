/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eballest <eballest@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:48:32 by eballest          #+#    #+#             */
/*   Updated: 2022/11/15 15:48:51 by eballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_read(char *str, unsigned int *i, int fd, int *lread);
int		ft_foundline(char *str, unsigned int *i, int lread);
char	*ft_readline(char *str, int fd, int i, int *lread);
char	*ft_newline(char *str, unsigned int i);
char	*ft_cleanline(char *str, unsigned int i);
int		ft_strlen(char *str);
char	*ft_addline(char *str, char *line, int lread);
char	*ft_free(char **str);

#endif
