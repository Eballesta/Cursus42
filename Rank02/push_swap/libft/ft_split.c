/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eballest <eballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 15:42:37 by eballest          #+#    #+#             */
/*   Updated: 2023/07/09 13:25:36 by eballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_words(char const *s, char c)
{
	int	num_words;
	int	i;

	num_words = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			num_words++;
			while (s[i] != c && s[i] != '\0')
			{
				i++;
			}
		}
		else
			i++;
	}
	return (num_words);
}

size_t	len_word(char const *s, char c, int *i)
{
	size_t	len;
	int		j;

	len = 0;
	while (s[*i] == c)
		*i = *i + 1;
	j = *i;
	while (s[j] != c && s[j] != '\0')
	{
		j++;
		len++;
	}
	return (len);
}

void	free_mallocs(char **r, int i)
{
	i--;
	while (i >= 0)
	{
		free(r[i]);
		i--;
	}
	free(r);
}

char	**ft_split(char const *s, char c)
{
	int		num_words;
	char	**r;
	int		i;
	int		word;
	size_t	len;

	num_words = count_words(s, c);
	r = (char **)malloc(sizeof(char *) * (num_words + 1));
	if (!r)
		return (NULL);
	i = 0;
	word = 0;
	while (word++ < num_words)
	{
		len = len_word(s, c, &i);
		r[word - 1] = ft_substr(s, i, len);
		if (!r[word - 1])
		{
			free_mallocs(r, word - 1);
			return (NULL);
		}
		i = i + len;
	}
	r[word - 1] = NULL;
	return (r);
}
