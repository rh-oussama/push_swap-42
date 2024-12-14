/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhaddao <orhaddao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 14:11:59 by orhaddao          #+#    #+#             */
/*   Updated: 2024/01/01 20:48:24 by orhaddao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../gnl_c/get_next_line.h"
# include "../push_swap.h"

int		ft_strcmp(char *str1, char *str2);
int		apply_instrac(char *line, t_list **a, t_list **b);
void	process_lines(t_list **a, t_list **b, char **split);

#endif