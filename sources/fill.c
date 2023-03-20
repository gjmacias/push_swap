/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmacias- <gmacias-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 20:17:23 by gmacias-          #+#    #+#             */
/*   Updated: 2023/02/22 20:18:40 by gmacias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*fill_stack(t_parameters *parameters, char **split)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	while (split[i])
	{
		tmp = malloc(sizeof(t_stack));
		if (tmp == NULL)
			ft_error(0);
		tmp->number = ft_atoi(split[i++]);
		tmp->position = i;
		tmp->next = NULL;
		ft_stkadd_back(&parameters->a, tmp);
		tmp = NULL;
	}
	free(tmp);
	return (parameters->a);
}

char	**fill_split(t_parameters *parameters, char **arguments)
{
	parameters->split = &arguments[1];
	return (parameters->split);
}

void	fill_position(t_stack **a)
{
	int		i;
	t_stack	*tmp;

	if ((*a) == NULL)
		return ;
	i = 0;
	tmp = (*a);
	while (tmp)
	{
		tmp->position = ++i;
		tmp = tmp->next;
	}
	tmp = NULL;
}
