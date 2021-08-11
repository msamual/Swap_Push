/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <msamual@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 13:12:49 by msamual           #+#    #+#             */
/*   Updated: 2021/05/06 16:20:41 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_bzero(void *ptr, size_t size)
{
	unsigned char	*str;

	str = (unsigned char *)ptr;
	while (size)
	{
		*str = 0;
		str++;
		size--;
	}
	return (ptr);
}
