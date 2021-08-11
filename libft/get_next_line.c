/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <msamual@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 20:55:22 by msamual           #+#    #+#             */
/*   Updated: 2021/05/06 16:12:48 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lst	*ft_listnew(int fd)
{
	t_lst	*new;

	new = (t_lst *)malloc(sizeof(t_lst));
	if (!new)
		return (NULL);
	new->fd = fd;
	new->next = NULL;
	new->reminder = NULL;
	return (new);
}

t_lst	*find_fd(int fd, t_lst **lst)
{
	t_lst	*tmp;

	if (*lst == NULL)
	{
		*lst = ft_listnew(fd);
		if (!(*lst))
			return (NULL);
	}
	tmp = *lst;
	while (tmp->next)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	if (tmp->fd == fd)
		return (tmp);
	tmp->next = ft_listnew(fd);
	return (tmp->next);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != c)
		s++;
	if (*s == c)
		return ((char *)s);
	return (NULL);
}

int	check(char *str, char **line, t_lst *lst, int code)
{
	char	*nl;

	if (!str)
		return (0);
	nl = ft_strchr(str, '\n');
	if (nl)
	{
		*nl++ = '\0';
		nl = ft_strjoin_g(NULL, nl, 0);
		if (!nl)
			return (-1);
		*line = ft_strjoin_g(*line, str, code);
		if (!(*line))
			return (-1);
		lst->reminder = nl;
		return (1);
	}
	*line = ft_strjoin_g(*line, str, code);
	if (!(*line))
		return (-1);
	lst->reminder = NULL;
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static t_lst	*list;
	t_lst			*current;
	int				res;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, NULL, 0) < 0
		|| !line || !find_fd(fd, &list)
		|| read(fd, NULL, 0) < 0)
		return (-1);
	current = find_fd(fd, &list);
	*line = (char *)malloc(1);
	*line[0] = '\0';
	res = check(current->reminder, line, current, 1);
	if (res)
		return (res);
	res = read_line(current, line);
	if (res == 0)
	{
		if (current->reminder)
			free(current->reminder);
		clear(&list, fd);
	}
	return (res);
}
