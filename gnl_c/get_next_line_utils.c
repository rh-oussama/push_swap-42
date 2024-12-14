/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhaddao <orhaddao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 14:47:50 by orhaddao          #+#    #+#             */
/*   Updated: 2024/01/01 19:35:18 by orhaddao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../checker_l/checker.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char) c)
		return ((char *) &s[i]);
	return (NULL);
}

void	*ft_calloc(size_t n, size_t size)
{
	size_t	i;
	void	*ptr;

	if (size && SIZE_MAX / size <= n)
		return (NULL);
	ptr = malloc((size_t)(size * n));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < (n * size))
		((unsigned char *)ptr)[i++] = 0;
	return (ptr);
}
