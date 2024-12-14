/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ccleaner.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhaddao <orhaddao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 12:47:25 by orhaddao          #+#    #+#             */
/*   Updated: 2024/01/01 13:59:30 by orhaddao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_list(t_list **head)
{
	t_list	*tmp;

	while (*head != NULL)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp);
	}
	*head = NULL;
}

char	**free_split(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

int	ft_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

int	check_rules(char *str)
{
	char	**split_str;

	if (check_str(str) == 0)
		return (0);
	split_str = ft_split(str, ' ');
	if (array_t(split_str) == 0)
		return (free_split(split_str), 0);
	free_split(split_str);
	return (1);
}
