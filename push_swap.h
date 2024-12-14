/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhaddao <orhaddao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:33:45 by orhaddao          #+#    #+#             */
/*   Updated: 2024/01/01 13:30:39 by orhaddao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				number;
	int				current_position;
	int				final_index;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

// split and sort array

char	**ft_split(char const *s, char c);
long	int	ft_atol(const char *nptr);
int		*array(char **tmp);
void	bubble_sort(int *arr, int n);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);

// Cleaner
void	free_list(t_list **head);
char	**free_split(char **arr);

// linked list outils

void	fill_stack_a(t_list **a, char **argv);
int		get_final_index(int *arr, int i);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);

// push swap instruction 1 //

void	swap(t_list **a);
void	rotate(t_list **lst);
void	reverse_rotate(t_list **lst);
void	push(t_list **from, t_list **to);

// push swap instruction 2 //

void	sa(t_list **a);
void	sb(t_list **b);
void	ra(t_list **a);
void	rb(t_list **b);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rr(t_list **a, t_list **b);
void	ss(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b);
void	pb(t_list **b, t_list **a);
void	rrr(t_list **a, t_list **b);

// TOOLS

char	*ft_strjoin(char const *s1, char const *s2);
char	*concat_args(int argc, char **argv);
int		check_str(char *s);
int		ft_error(void);
int		array_t(char **tmp);
int		check_duplicates(long int *arr, int size);
int		check_rules(char *str);

// sort the linked list //

int		is_sorted(t_list *a);
void	update_info(t_list *a);
void	push_b(t_list **a, t_list **b, int len);
void	sort_list(t_list **a, t_list **b);
void	push_a(t_list **a, t_list **b);
t_list	*get_list(t_list *a, int cpos);

// sort handler 

void	sort_two(t_list **a); /* SORT WO NUMBER */
void	sort_three(t_list **a); /* SORT THREE NUMBER */
void	sort_three_helper(t_list **a, int first, int second, int third);
void	sort_four(t_list **a, t_list **b);
void	sort_five(t_list **a, t_list **b); /* SORT FIVE NUMBER HELPER */
void	big_list_sort(t_list **a, t_list **b); /* BIG SORT */

#endif