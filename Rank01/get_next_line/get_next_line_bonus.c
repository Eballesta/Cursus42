/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eballest <eballest@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:49:16 by eballest          #+#    #+#             */
/*   Updated: 2022/11/20 15:39:49 by eballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char		*str[1024];
	char			*line;
	unsigned int	i;
	int				lread;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	if (!str[fd])
	{
		str[fd] = (char *)malloc(1);
		if (!str[fd])
			return (NULL);
		str[fd][0] = '\0';
	}
	i = 0;
	lread = -1;
	str[fd] = ft_read(str[fd], &i, fd, &lread);
	if (!str[fd])
		return (NULL);
	line = ft_newline(str[fd], i);
	if (!line)
		return (ft_free(&str[fd]));
	str[fd] = ft_cleanline(str[fd], i);
	return (line);
}

char	*ft_read(char *str, unsigned int *i, int fd, int *lread)
{
	while (ft_foundline(str, i, *lread) == -1)
	{
		str = ft_readline(str, fd, *i, lread);
		if (!str)
			return (NULL);
	}
	return (str);
}

char	*ft_readline(char *str, int fd, int i, int *lread)
{
	char	line[BUFFER_SIZE + 1];

	*lread = read(fd, line, BUFFER_SIZE);
	if (*lread < 0 || (*lread == 0 && i <= 0))
		return (ft_free(&str));
	if (*lread == 0)
		return (str);
	line[*lread] = '\0';
	str = ft_addline(str, line, *lread);
	if (!str)
		return (NULL);
	return (str);
}

char	*ft_newline(char *str, unsigned int i)
{
	unsigned int	j;
	char			*line;

	if (str[0] == '\0')
		return (NULL);
	if (str[i] == '\n')
		line = (char *)malloc(i + 2);
	else
		line = (char *)malloc(i + 1);
	if (!line)
		return (NULL);
	j = 0;
	while (j < i)
	{
		line[j] = str[j];
		j++;
	}
	if (str[j] == '\n')
	{
		line[j] = '\n';
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*ft_cleanline(char *str, unsigned int i)
{
	char	*str2;
	int		j;

	if (str[i] == '\0')
		return (ft_free(&str));
	str2 = (char *)malloc(ft_strlen(str) - i + 1);
	if (!str2)
		return (ft_free(&str));
	j = 0;
	while (str[i] != '\0')
	{
		i++;
		str2[j] = str[i];
		j++;
	}
	if (j > 0)
		str2[j] = '\0';
	else
	{
		free(str2);
		return (ft_free(&str));
	}
	ft_free(&str);
	return (str2);
}
