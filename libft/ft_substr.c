/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <msamual@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 13:40:02 by msamual           #+#    #+#             */
/*   Updated: 2021/04/26 13:20:12 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strnew(size_t size)
{
	return ((char *)ft_calloc(size, sizeof(char)));
}

char 	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;

	res = ft_strnew(len + 1);
	if (!s || !res)
		return (NULL);
	if (start < ft_strlen(s))
		ft_strlcpy(res, &(s[start]), len + 1);
	return (res);
}
