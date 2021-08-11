/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <msamual@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 13:46:11 by msamual           #+#    #+#             */
/*   Updated: 2021/04/26 14:41:34 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atoi(char *str)
{
	int		neg;
	long	res;

	neg = 0;
	res = 0;
	while (*str == ' ' || (*str > 8 && *str < 14))
		str++;
	if (*str == '-')
		neg++;
	if (*str == '-' || *str == '+')
		str++;
	while (*str > 47 && *str < 58)
	{
		res = res * 10 + (*str - 48);
		str++;
	}
	if (neg)
		return (-res);
	return (res);
}
