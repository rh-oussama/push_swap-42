/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhaddao <orhaddao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 19:23:21 by orhaddao          #+#    #+#             */
/*   Updated: 2023/12/30 11:14:12 by orhaddao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_list **a)
{
	write(1, "sa\n", 3);
	swap(a);
}

void	sb(t_list **b)
{
	write(1, "sb\n", 3);
	swap(b);
}

void	ss(t_list **a, t_list **b)
{
	swap(a);
	swap(b);
}

void	pb(t_list **a, t_list **b)
{
	write(1, "pb\n", 3);
	push(a, b);
}

void	pa(t_list **b, t_list **a)
{
	write(1, "pa\n", 3);
	push(b, a);
}
