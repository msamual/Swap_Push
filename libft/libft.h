/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <msamual@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 13:40:56 by msamual           #+#    #+#             */
/*   Updated: 2021/05/06 15:22:55 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

# define STACK_MAX_SIZE 10000
# define BUFFER_SIZE 10000

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_lst
{
	struct s_lst	*next;
	int				fd;
	char			*reminder;
}					t_lst;

typedef struct s_stack
{
	int		numbers[STACK_MAX_SIZE];
	size_t	size;
}				t_stack;

void				swap(int *a, int *b);
int					ft_int_max(int a, int b);
int					ft_int_max_three(int a, int b, int c);
unsigned long		ft_strlen(const char *str);
char				*ft_strcpy(char *dst, const char *src);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_write(int fildes, const void *buf, int nbyte);
int					ft_read(int fildes, const void *buf, int nbyte);
char				*ft_strdup(const char *src);

int					ft_atoi_base(char *str, int base);
void				ft_list_push_front(t_list **begin_list, void *data);
int					ft_list_size(t_list *begin_list);
void				ft_list_sort(t_list **begin_list, int (*cmp)());
void				ft_list_remove_if(t_list **begin_list, void *data_ref,
						int (*cmp)());

void				*ft_memset(void *b, int c, size_t len);
void				*ft_bzero(void *ptr, size_t size);
void				*ft_memcpy(void *dest, const void *src, size_t size);
void				*ft_memccpy(void *dest, const void *src, int c,
						size_t size);
void				*ft_memmove(void *dest, const void *source, size_t size);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(void *arr1, void *arr2, size_t size);
char				*ft_strdup(const char *str);
size_t				ft_strlcpy(char *dest, const char *src, size_t dstsize);
size_t				ft_strlcat(char *dst, char const *append, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t loc);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
long				ft_atoi(char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_isdigit_str(char *str);
int					is_number(char *str);
void				*ft_calloc(size_t count, size_t size);

char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char const c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

void				ft_putstr(char *str);
void				ft_putendl(char *str);
void				ft_putendl_void(void *str);

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

void				push(t_stack *stack, int n);
int					pop(t_stack *stack);
void				print_stack(t_stack *stack);
void				print_stacks(t_stack *a, t_stack *b);
void				print_three_stacks(t_stack *a, t_stack *b, t_stack *c);
t_stack				*new_stack(void);

int					get_next_line(int fd, char **line);
char				*ft_strchr(const char *s, int c);
char				*ft_strjoin_g(char *s1, char *s2, int code);
int					read_line(t_lst *lst, char **line);
int					check(char *str, char **line, t_lst *lst, int code);
void				clear(t_lst **begin_list, int fd);

#endif
