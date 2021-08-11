/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <msamual@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 13:45:07 by msamual           #+#    #+#             */
/*   Updated: 2021/04/28 11:32:38 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	struct s_list	*next;
	int				fd;
	char			*reminder;
}					t_list;

int					get_next_line(int fd, char **line);
char				*ft_strchr(const char *s, int c);
char				*ft_strjoin_g(char *s1, char *s2, int code);
int					read_line(t_list *lst, char **line);
int					check(char *str, char **line, t_list *lst, int code);
void				clear(t_list **begin_list, int fd);

#endif
