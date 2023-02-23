/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmacias- <gmacias-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 20:22:57 by gmacias-          #+#    #+#             */
/*   Updated: 2023/02/22 21:32:32 by gmacias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_min(t_stack **a)
{
	t_stack	*tmp;
	int		min;

	tmp = (*a);
	min = tmp->number;
	while (tmp)
	{
		if (tmp->number < min)
			min = tmp->number;
		tmp = tmp->next;
	}
	tmp = NULL;
	return (min);
}

int	ft_max(t_stack **a)
{
	t_stack	*tmp;
	int		max;

	tmp = (*a);
	max = tmp->number;
	while (tmp)
	{
		if (tmp->number > max)
			max = tmp->number;
		tmp = tmp->next;
	}
	tmp = NULL;
	return (max);
}

/*
** Solo hay estos casos:
**	 	1	1	2	2^	3*	3
**		2	3	1	3	1	2
**		3	2	3	1	2	1
**		ok	sa	sa	rra	ra	sa
**			3*				2^
** 			1	ok	ok	ok	3
**			2				1
** Con el while, se soluciona solo, el valor "i" esta por que lo calcula tan
** rapido que se lagea xD
*/

void	order_3(t_stack **a, int min, int max)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	if (parameters->length_a == 2)
	{
		r_stack(a, 'a');
		return ;
	}
	tmp = (*a)->next->next;
	while (((*a)->number != min
			|| tmp->number != max) && ++i != 3)
	{
		if ((*a)->number != min
			&& (*a)->number != max
			&& tmp->number == min)
			rr_stack(a, 'a');
		else if ((*a)->number == max
			&& tmp->number != min
			&& tmp->number != max)
			r_stack(a, 'a');
		else
			s_stack(a, 'a');
	}
}

void	order(t_parmeters *parameters)
{
	while (check_order(parameters->a, parameters->length) != 0)
	{
		if (parameters->length <= 3)
			order_3(parameters->a, ft_min(parameters->a),
				ft_max(parameters->a));
		else
		{
			fill_position(parameters->a);
			fill_position(parameters->b);
			make_position(search_less_moves(parameters->a, parameters->b,
						parameters->length_a));
		}
	}
}

int	 search_less_moves(t_stack **a, t_stack **b, int length_a)
{
	t_algoritmia	*algoritmia;
	t_stack			*tmp_a;
	t_stack			*tmp_b;
	int				moves;
	int				result;

	moves = 0
	tmp_a = (*a);
	if (check_length(b) <= 2)
		return (1);
	else
	{
		while (tmp_a)
		{
			tmp_b = (*b);
			if(tmp_a->number > ft_max(b) || tmp_a->number < ft_min(b))
			{
				while (tmp_b->number != ft_max(b))
				{
					tmp_b = tmp_b->next;
					moves++;
				}
				algoritmia->moves_b = moves;
				moves = 0;
				while (tmp_b)
				{
					tmp_b->tmp_b->next;
					moves++;
				}
				if (moves < algoritmia->moves_b)
					algoritmia->moves = -moves;
			}
			else
			{
				while (tmp_b->number)
				{
					tmp_b = tmp_b->next;
					moves++;
				}
				algoritmia->moves_b = moves;
			}
		}
	}
	return (algoritmia->position);
}
