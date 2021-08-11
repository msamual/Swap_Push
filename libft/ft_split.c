/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <msamual@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 19:40:12 by msamual           #+#    #+#             */
/*   Updated: 2021/05/06 16:16:09 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_word(char const *s, unsigned int pos, char c)
{
	if (pos == 0)
		if (s[pos] != c)
			return (1);
	if (s[pos] != c && s[pos - 1] == c)
		return (1);
	return (0);
}

static int	words_count(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (is_word(s, i, c))
			count++;
		i++;
	}
	return (count);
}

static int	word_size(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	count;
	unsigned int	i;
	unsigned int	j;
	char			**res;

	if (!s)
		return (NULL);
	count = words_count(s, c);
	res = malloc(sizeof(char *) * count + 1);
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (j < count)
	{
		if (is_word(s, i, c))
		{
			res[j] = ft_substr(s, i, word_size(&(s[i]), c));
			j++;
		}
		i++;
	}
	res[j] = NULL;
	return (res);
}
