/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhaddao <orhaddao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 20:18:58 by orhaddao          #+#    #+#             */
/*   Updated: 2024/01/01 13:04:19 by orhaddao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rrr(t_list **a, t_list **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (lst)
	{
		tmp = lst;
		lst = lst->next;
	}
	return (tmp);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (!(*lst))
	{
		(*lst) = new;
	}
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
		new->prev = last;
	}
}

void	fill_stack_a(t_list **a, char **argv)
{
	t_list	*new_node;
	int		*arr;

	arr = array(argv);
	while (*argv)
	{
		new_node = (t_list *) malloc(sizeof(t_list));
		if (!new_node)
			return ;
		new_node->number = ft_atol(*argv);
		new_node->final_index = get_final_index(arr, new_node->number);
		new_node->next = NULL;
		new_node->prev = NULL;
		ft_lstadd_back(a, new_node);
		argv++;
	}
	free(arr);
}
