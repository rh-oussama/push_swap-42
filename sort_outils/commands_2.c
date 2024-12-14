/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhaddao <orhaddao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 19:29:45 by orhaddao          #+#    #+#             */
/*   Updated: 2023/12/28 16:15:04 by orhaddao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_list **a)
{
	write(1, "ra\n", 3);
	rotate(a);
}

void	rb(t_list **b)
{
	write(1, "rb\n", 3);
	rotate(b);
}

void	rr(t_list **a, t_list **b)
{
	rotate(a);
	rotate(b);
}

void	rra(t_list **a)
{
	write(1, "rra\n", 4);
	reverse_rotate(a);
}

void	rrb(t_list **b)
{
	write(1, "rrb\n", 4);
	reverse_rotate(b);
}
