/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhaddao <orhaddao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 19:33:22 by orhaddao          #+#    #+#             */
/*   Updated: 2024/01/01 19:51:31 by orhaddao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_list(t_list **a, t_list **b)
{
	int	lst_size;

	lst_size = ft_lstsize(*a);
	update_info(*a);
	if (is_sorted(*a) == 1)
		return ;
	if (lst_size == 1)
		return ;
	else if (lst_size == 2)
		sort_two(a);
	else if (lst_size == 3)
		sort_three(a);
	else if (lst_size == 4)
		sort_four(a, b);
	else if (lst_size == 5)
		sort_five(a, b);
	else
		big_list_sort(a, b);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	char	*str;
	char	**split;

	a = NULL;
	b = NULL;
	str = concat_args(argc, argv);
	if (ft_strlen(str) == 1 && str[0] == ' ')
		return (free(str), 0);
	if (check_rules(str) == 0)
		return (free(str), ft_error());
	split = ft_split(str, ' ');
	free(str);
	fill_stack_a(&a, split);
	sort_list(&a, &b);
	free_split(split);
	free_list(&a);
	return (0);
}
