/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_perfection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmacias- <gmacias-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:35:34 by gmacias-          #+#    #+#             */
/*   Updated: 2022/05/19 17:45:58 by gmacias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	make_a_chunkers(t_stack **perfection, t_stack **a)
{
	t_stack	*tmp[2];

	tmp[0] = *perfection;
	while (tmp[0])
	{
		tmp[1] = *a;
		while (tmp[1])
		{
			if (tmp[0]->number == tmp[1]->number)
				tmp[1]->chunker = tmp[0]->chunker;
			tmp[1] = tmp[1]->next;
		}
		tmp[0] = tmp[0]->next;
	}
}

void	make_position_and_chunkers(t_stack **perfection, t_parameters *parameters)
{
	int	i;
	int	const_chunker;
	t_stack	*tmp;
	
	i = 0;
	constant_chunker = 10;
	tmp = *perfection;
	while (tmp)
	{
		tmp->position = i++;
		tmp = tmp->next;
	}
	tmp = *perfection;
	while (tmp)
	{
		tmp->chunker = ((tmp->position + const_chunker) / const_chunker);
		tmp = tmp->next;
	}
	tmp->chunker = ((tmp->position + const_chunker) / const_chunker);
	parameters->max_chunk = tmp->chunker;
}

void	make_perfection(t_stack **perfection, t_stack **a, t_parameters *parameters)
{
	t_stack *tmp[3];
	
	tmp[0] = *perfection;
	tmp[2] = (t_stack *)malloc(sizeof(t_stack));
	while (tmp[0])
	{
		tmp[1] = tmp[0];
		while (tmp[1])
		{
			if (tmp[0]->number > tmp[1]->number)
			{
				tmp[2]->number = tmp[1]->number;
				tmp[1]->number = tmp[0]->number;
				tmp[0]->number = tmp[2]->number;
			}
			tmp[1] = tmp[1]->next;
		}
		tmp[0] = tmp[0]->next;
	}
	free(tmp[2]);
	make_position_and_chunkers(perfection, parameters);
	make_a_chunkers(perfection, a);
}
