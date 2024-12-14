/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhaddao <orhaddao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 17:21:56 by orhaddao          #+#    #+#             */
/*   Updated: 2023/12/30 14:50:22 by orhaddao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_list **a)
{
	t_list	*first;
	t_list	*second;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	first = *a;
	second = (*a)->next;
	first->next = second->next;
	if (second->next != NULL)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	*a = second;
}

void	rotate(t_list **lst)
{
	t_list	*head;
	t_list	*last;

	head = (*lst);
	if (*lst == NULL || (*lst)->next == NULL)
		return ;
	(*lst) = (*lst)->next;
	(*lst)->prev = NULL;
	last = ft_lstlast(*lst);
	last->next = head;
	head->prev = last;
	head->next = NULL;
}

void	reverse_rotate(t_list **lst)
{
	t_list	*head;
	t_list	*last;

	head = (*lst);
	if (*lst == NULL || (*lst)->next == NULL)
		return ;
	last = ft_lstlast(*lst);
	last->prev->next = NULL;
	last->next = head;
	last->prev = NULL;
	head->prev = last;
	(*lst) = last;
}

void	push(t_list **from, t_list **to)
{
	t_list	*head_from;

	if (*from == NULL)
		return ;
	head_from = (*from);
	(*from) = (*from)->next;
	if (*from != NULL)
		(*from)->prev = NULL;
	head_from->next = *to;
	if (*to != NULL)
		(*to)->prev = head_from;
	head_from->prev = NULL;
	*to = head_from;
}

void	big_list_sort(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) <= 100)
		push_b(a, b, 15);
	else
		push_b(a, b, 30);
	push_a(a, b);
}
