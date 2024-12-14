/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_stack_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhaddao <orhaddao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 19:14:15 by orhaddao          #+#    #+#             */
/*   Updated: 2023/12/24 19:21:00 by orhaddao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	bubble_sort(int *arr, int n)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < n - 1)
	{
		j = 0;
		while (j < n - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

int	*array(char **tmp)
{
	int	i;
	int	j;
	int	*arr;

	i = 0;
	while (tmp[i])
		i++;
	arr = (int *)malloc(sizeof(int) * i);
	if (!arr)
		return (NULL);
	j = 0;
	while (j < i)
	{
		arr[j] = ft_atol(tmp[j]);
		j++;
	}
	bubble_sort(arr, i);
	return (arr);
}

int	get_final_index(int *arr, int i)
{
	int	j;

	j = 0;
	while (arr[j] != i)
		j++;
	return (j);
}

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
