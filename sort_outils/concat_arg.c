/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concat_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhaddao <orhaddao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 16:27:17 by orhaddao          #+#    #+#             */
/*   Updated: 2024/01/06 13:47:42 by orhaddao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	str = (char *) malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = 0;
	return (str);
}

char	*concat_args(int argc, char **argv)
{
	char	*result;
	int		i;
	char	*temp;

	result = ft_strdup("");
	i = 1;
	while (i < argc)
	{
		temp = result;
		result = ft_strjoin(result, argv[i]);
		free(temp);
		if (i < argc - 1)
		{
			temp = result;
			result = ft_strjoin(result, " ");
			free(temp);
		}
		i++;
	}
	return (result);
}

int	array_t(char **tmp)
{
	int			i;
	int			j;
	long int	*arr;
	int			res;

	i = 0;
	while (tmp[i])
		i++;
	arr = (long int *) malloc(sizeof(long int) * i);
	if (!arr)
		return (0);
	j = 0;
	while (j < i)
	{
		arr[j] = ft_atol(tmp[j]);
		if (arr[j] > 2147483647 || arr[j] < -2147483648)
			return (free(arr), 0);
		j++;
	}
	res = check_duplicates(arr, i);
	return (free(arr), res);
}

int	check_str(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] >= '0' && s[i] <= '9')
			i++;
		else if (s[i] == ' ')
			i++;
		else if (s[i] == '-' || s[i] == '+')
		{
			if (s[i + 1] == ' ' || (i != 0 && s[i - 1] != ' '))
				return (0);
			if ((s[i + 1] != '\0' && s[i + 1] != ' ' \
					&& !(s[i + 1] >= '0' && s[i + 1] <= '9')))
				return (0);
			i++;
		}
		else
			return (0);
	}
	if (s[i - 1] == '-' || s[i - 1] == '+')
		return (0);
	return (1);
}

int	check_duplicates(long int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
