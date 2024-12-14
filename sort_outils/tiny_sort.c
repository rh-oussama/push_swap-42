/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhaddao <orhaddao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 19:30:31 by orhaddao          #+#    #+#             */
/*   Updated: 2023/12/30 14:40:19 by orhaddao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
1 - 1 2 3 {first < second && second < third}
2 - 1 3 2 {first < third && third < second}
3 - 2 1 3 {first > second && second < third && first < third}
4 - 2 3 1 {third < first && third < second && first < second}
5 - 3 1 2 {first > third && third > second && first > second}
6 - 3 2 1 {first > second && second > third && first > third}
*/

void	sort_three(t_list **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->number;
	second = (*a)->next->number;
	third = (*a)->next->next->number;
	if (first < second && second < third)
		return ;
	else if (first < third && third < second)
	{
		rra(a);
		sa(a);
	}
	else if (first > second && second < third && first < third)
		sa(a);
	else
		sort_three_helper(a, first, second, third);
}

void	sort_three_helper(t_list **a, int first, int second, int third)
{
	if (third < first && third < second && first < second)
		rra(a);
	else if (first > third && third > second && first > second)
		ra(a);
	else if (first > second && second > third && first > third)
	{
		sa(a);
		rra(a);
	}
}

void	sort_four(t_list **a, t_list **b)
{
	t_list	*tmp;

	update_info(*a);
	if (is_sorted(*a) == 1)
		return ;
	tmp = get_list(*a, 0);
	while (tmp->current_position != 0)
	{
		if (tmp->current_position < ft_lstsize(*a) / 2)
			ra(a);
		else
			rra(a);
		update_info(*a);
	}
	if (is_sorted(*a) == 1)
		return ;
	pb(a, b);
	sort_three(a);
	pa(a, b);
}

void	sort_five(t_list **a, t_list **b)
{
	t_list	*tmp;
	int		i;

	i = 0;
	update_info(*a);
	while (i <= 1)
	{
		tmp = get_list(*a, i);
		while (tmp->current_position != 0)
		{
			tmp = get_list(*a, i);
			if (tmp->current_position < ft_lstsize(*a) / 2)
				ra(a);
			else
				rra(a);
			update_info(*a);
		}
		pb(a, b);
		i++;
	}
	if (is_sorted(*a) == 1)
		return ;
	sort_three(a);
	pa(a, b);
	pa(a, b);
}

void	sort_two(t_list **a)
{
	update_info(*a);
	if (is_sorted(*a) == 0)
		sa(a);
}
