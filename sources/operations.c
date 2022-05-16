/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmacias- <gmacias-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:41:39 by gmacias-          #+#    #+#             */
/*   Updated: 2022/05/16 16:42:02 by gmacias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	order(t_stack **a, t_stack **b, t_parameters *parameters)
{
	search_min_max(&(parameters), b);
	if (calculus(parameters, b) == 0)
	{
		while ((*b)->number != parameters->max)
			r_stack(b);
	}
	else
	{
		while ((*b)->number != parameters->max)
			rr_stack(b);
	}
	while (*b)
		p_stack(b, a);
}

void	p_stack(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = (t_stack *) malloc(sizeof(t_stack));
	if (tmp == NULL)
		return (NULL);
	if (*b == NULL)
	{
		(*b) = (t_stack *) malloc(sizeof(t_stack));
		if ((*b) == NULL)
			return (NULL);
		(*b)->number = (*a)->number;
		(*b)->next = NULL;
		tmp = (*a);
		(*a) = (*a)->next;
	}
	else
	{
		tmp->number = (*a)->number;
		tmp->next = NULL;
		add_front(b, tmp);
		tmp = (*a);
		(*a) = (*a)->next;
	}
	free(tmp);
}

void	s_stack(t_stack **top)
{
	int	tmp;

	if ((*top) && ((*top)->next))
	{
		tmp = (*top)->number;
		(*top)->number = (*top)->next->number;
		(*top)->next->number = tmp;
	}
}

void	ss_stack(t_stack **a, t_stack **b)
{
	s_stack(a);
	s_stack(b);
}
