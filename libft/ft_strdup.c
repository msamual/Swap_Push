/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <msamual@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:55:08 by msamual           #+#    #+#             */
/*   Updated: 2021/04/22 17:49:53 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*res;
	int		i;

	i = -1;
	res = malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!res)
		return (NULL);
	while (str[++i])
		res[i] = str[i];
	res[i] = '\0';
	return (res);
}
