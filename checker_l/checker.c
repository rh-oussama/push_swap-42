/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhaddao <orhaddao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 14:11:45 by orhaddao          #+#    #+#             */
/*   Updated: 2024/01/04 09:39:41 by orhaddao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "checker.h"

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] && str1[i] == str2[i])
		i++;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}

int	apply_instrac(char *line, t_list **a, t_list **b)
{
	if (ft_strcmp("sa\n", line) == 0)
		return (swap(a), 0);
	else if (ft_strcmp("ra\n", line) == 0)
		return (rotate(a), 0);
	else if (ft_strcmp("rb\n", line) == 0)
		return (rotate(b), 0);
	else if (ft_strcmp("rra\n", line) == 0)
		return (reverse_rotate(a), 0);
	else if (ft_strcmp("rrb\n", line) == 0)
		return (reverse_rotate(b), 0);
	else if (ft_strcmp("pa\n", line) == 0)
		return (push(b, a), 0);
	else if (ft_strcmp("pb\n", line) == 0)
		return (push(a, b), 0);
	else if (ft_strcmp("sb\n", line) == 0)
		return (swap(b), 0);
	else if (ft_strcmp("ss\n", line) == 0)
		return (swap(a), swap(b), 0);
	else if (ft_strcmp("rr\n", line) == 0)
		return (rotate(a), rotate(b), 0);
	else if (ft_strcmp("rrr\n", line) == 0)
		return (reverse_rotate(a), reverse_rotate(b), 0);
	else
		return (1);
}

void	process_lines(t_list **a, t_list **b, char **split)
{
	char	*line;

	line = get_next_line(0);
	while (line != NULL)
	{
		if (apply_instrac(line, a, b) == 0)
			free(line);
		else
		{
			free_split(split);
			free_list(a);
			ft_error();
			return ;
		}
		line = get_next_line(0);
	}
	update_info(*a);
	if (is_sorted(*a) == 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_split(split);
	free_list(a);
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
	if ((ft_strlen(str) == 1 && str[0] == ' ') || str[0] == '\0')
		return (free(str), 0);
	if (check_rules(str) == 0)
		return (free(str), ft_error());
	split = ft_split(str, ' ');
	free(str);
	fill_stack_a(&a, split);
	process_lines(&a, &b, split);
	return (0);
}
