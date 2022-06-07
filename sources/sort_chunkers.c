/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunkers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmacias- <gmacias-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:44:48 by gmacias-          #+#    #+#             */
/*   Updated: 2022/06/07 16:18:35 by gmacias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	search_min_max(t_parameters **parameters, t_stack **a)
{
	int		pos;
	t_stack	*tmp;

	pos = 0;
	tmp = (*a);
	(*parameters)->max = (tmp)->number;
	(*parameters)->min = (tmp)->number;
	(*parameters)->length_a = check_length(a);
	while ((tmp) != NULL)
	{
		(tmp)->position = ++pos;
		if ((tmp)->number <= (*parameters)->min)
		{
			(*parameters)->min = (tmp)->number;
			(*parameters)->min_pos = (tmp)->position;
		}
		if ((tmp)->number >= (*parameters)->max)
		{
			(*parameters)->max = (tmp)->number;
			(*parameters)->max_pos = (tmp)->position;
		}
		(tmp) = ((tmp)->next);
	}
}

void	sort_chunkers(t_stack **a, t_stack **b, t_parameters *parameters)
{
	search_min_max(&(parameters), a);
	while (check_order(a, parameters->length) != 0)
	{
		if (parameters->length_a <= 3)
		{
			order_3(a, parameters);
			order(a, b, parameters);
			break ;
		}
		if ((*a)->number == parameters->min || (*a)->number == parameters->max)
		{
			p_stack(a, b, 'a');
			if ((*b)->number == parameters->max
				&& parameters->length != parameters->length_a)
				r_stack(b, 'b');
			search_min_max(&(parameters), a);
		}
		else
		{
			if (calculus(parameters, a) == 0)
				r_stack(a, 'a');
			else
				rr_stack(a, 'a');
		}
	}
}
