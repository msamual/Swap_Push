#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include "libft.h"

# define STACK_MAX_SIZE 10000

typedef struct s_number
{
	int		n;
	int		need;
	int		already_sorted;
	int		dist_in_b;
	int		dist_in_a;
	int		dist;
	int		flag;
	bool	max;
}			t_number;

typedef struct s_struct_stack
{
	t_number	numbers[STACK_MAX_SIZE];
	size_t		size;
	size_t		mediana;
	int			expected;
}				t_st;

int			find_command(char *str);
void		**init_function_array(void);
void		execute_command(t_stack *a, t_stack *b, int com, void **mass);
bool		check_duplicates(t_stack *stack);
int			puterror(char *msg, int code);
bool		check_sorted(t_stack *stack_a, t_stack *stack_b);
bool		is_int(char *str);
int			read_command(t_stack *stack_a, t_stack *stack_b, int debug);
void		sort_array(int *arr, int size);
void		sort_stack(t_stack *a, t_stack *b, t_stack *c);
void		rotate_loop(t_stack *a, int count, int com, t_list **lst);
void		push_and_rotate(t_stack *a, t_stack *b, t_stack *c, t_list **lst);
void		push_all(t_stack *from, t_stack *to, char *com, t_list **lst);
void		write_commands(t_list *lst);
void		turn_into_place(t_stack *a, int max, t_list **lst);
void		clear_list(t_list **lst);

void		a_swap(t_stack *a, t_stack *b);
void		b_swap(t_stack *a, t_stack *b);
void		sa_and_sb(t_stack *a, t_stack *b);
void		push_a(t_stack *a, t_stack *b);
void		push_b(t_stack *a, t_stack *b);
void		rotate_a(t_stack *a, t_stack *b);
void		rotate_b(t_stack *a, t_stack *b);
void		ra_and_rb(t_stack *a, t_stack *b);
void		reverse_rotate_a(t_stack *a, t_stack *b);
void		reverse_rotate_b(t_stack *a, t_stack *b);
void		rra_and_rrb(t_stack *a, t_stack *b);

void		clear_all_list(t_list **lst);
t_st		*new_s_stack(void);
t_number	new_t_number(int n);
void		push_nb(t_st *stack, t_number n);
t_number	pop_nb(t_st *stack);
void		print_three_stacks_s(t_st *stack_a, t_st *stack_b,
				t_stack *stack_c);
void		marking(t_st *a, t_stack *c);
int			is_already_sorted(t_st *a);
void		sorting(t_st *a, t_st *b, t_stack *c);
void		insert_number_to_place(t_st *a, t_st *b, t_list **lst);
void		rotate_dist_a(t_st *a, int dist, t_list **lst);
void		rotate_dist_b(t_st *b, int dist, t_list **lst);
void		turn_in_place(t_st *a, int max, t_list **lst);
void		optimize_command_list(t_list **lst);
void		replace_two_with_one(char *cur, char *next, t_list *lst);

void		sort_three_elements(t_st *a, t_list **lst);
void		sort_five_elements(t_st *a, t_st *b, t_list **lst);
void		sort_all(t_st *a, t_st *b, t_stack *c, t_list **lst);
int			get_min_path_to_insert(t_st *a, t_number n);
bool		check_duplicates_s(t_st *stack);

void		swap_numbers(t_number *a, t_number *b);
void		sa(t_st *a, t_list **lst);
void		sb(t_st *b, t_list **lst);
void		ss(t_st *a, t_st *b, t_list **lst);
void		ra(t_st *a, t_list **lst);
void		rb(t_st *b, t_list **lst);
void		rra(t_st *a, t_list **lst);
void		rrb(t_st *b, t_list **lst);
void		pa(t_st *a, t_st *b, t_list **lst);
void		pb(t_st *a, t_st *b, t_list **lst);

#endif