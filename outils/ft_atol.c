/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhaddao <orhaddao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:00:25 by orhaddao          #+#    #+#             */
/*   Updated: 2023/12/24 19:20:04 by orhaddao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long int	ft_atol(const char *nptr)
{
	long int	numb;
	int			i;
	int			sign;

	i = 0;
	sign = 1;
	numb = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] != '\0' && nptr[i] >= '0' && nptr[i] <= '9')
	{
		numb = numb * 10 + (nptr[i] - '0');
		i++;
	}
	return (sign * numb);
}
