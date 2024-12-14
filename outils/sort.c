/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhaddao <orhaddao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 09:26:11 by orhaddao          #+#    #+#             */
/*   Updated: 2024/01/01 13:30:10 by orhaddao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(t_list *a)
{
	while (a != NULL)
	{
		if (a->current_position == a->final_index)
			a = a->next;
		else
			return (0);
	}
	return (1);
}

void	update_info(t_list *a)
{
	int	i;

	i = 0;
	while (a != NULL)
	{
		a->current_position = i++;
		a = a->next;
	}
}

t_list	*get_list(t_list *a, int cpos)
{
	while (a != NULL)
	{
		if (a->final_index == cpos)
			return (a);
		a = a->next;
	}
	return (NULL);
}

void	push_b(t_list **a, t_list **b, int precision)
{
	int	i;

	i = 0;
	while (*a)
	{
		if ((*a)->final_index <= i)
		{
			pb(a, b);
			rb(b);
			i++;
		}
		else if ((*a)->final_index <= (i + precision))
		{
			pb(a, b);
			i++;
		}
		else if ((*a)->final_index >= i)
		{
			ra(a);
		}
		update_info(*a);
	}
}

void	push_a(t_list **a, t_list **b)
{
	int		size;
	t_list	*tmp;

	size = ft_lstsize(*b) - 1;
	update_info(*b);
	while (size >= 0)
	{
		tmp = NULL;
		if (((*b)->final_index == size) && (*b)->current_position == 0)
		{
			pa(b, a);
			size--;
		}
		else
		{
			tmp = get_list(*b, size);
			if (tmp->current_position < ft_lstsize(*b) / 2)
				rb(b);
			else
				rrb(b);
		}
		update_info(*b);
	}
}
