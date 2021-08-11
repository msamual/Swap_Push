/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <msamual@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 20:40:53 by msamual           #+#    #+#             */
/*   Updated: 2021/04/28 18:53:39 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_void(void *str)
{
	str = (char *)str;
	if (str)
		write(1, str, ft_strlen(str));
	write(1, "\n", 1);
}

void	ft_putendl(char *str)
{
	if (str)
		write(1, str, ft_strlen(str));
	write(1, "\n", 1);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

void	ft_putstr_fd(char const *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
}
