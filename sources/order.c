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

	tmp = (*a)->next;
	if (check_length(a) == 2 && (*a)->number > tmp->number)
	{
		r_stack(a, 'a');
		return ;
	}
	tmp = tmp->next;
	while (!((*a)->number == min && tmp->number == max))
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
		tmp = (*a)->next->next;
	}
}

void	order(t_parameters *parameters)
{
	t_algoritmia *algoritmia;
	algoritmia = malloc(sizeof(t_algoritmia));
	if (!algoritmia)
		ft_error(0);
	while (check_order(&parameters->a, parameters->length) != 0)
	{
		if (parameters->length <= 3)
			order_3(&parameters->a, ft_min(parameters->a),
				ft_max(parameters->a));
		else
		{
			start_algortimia(algoritmia, parameters->b);
			fill_position(parameters->a);
			fill_position(parameters->b);
			make_position(search_less_moves(parameters->a, parameters->b,
						algoritmia));
		}
	}
}

int	 search_less_moves(t_stack **a, t_stack **b, t_algoritmia *algoritmia)
{
	t_stack			*tmp_a;
	t_stack			*tmp_b;
	int				moves;
	int				result;

	moves = 0;
	result = 0;
	tmp_a = (*a);
	if (check_length(b) <= 2)
		return (1);
	else
	{
		while (tmp_a)
		{
			tmp_b = (*b);
			if(tmp_a->number > algoritmia->max_b || tmp_a->number < algoritmia->min_b)
			{
				while (tmp_b->number != algoritmia->max_b)
				{
					tmp_b = tmp_b->next;
					moves++;
				}
				algoritmia->moves_b = moves;
				moves = check_length(b) - algoritmia->moves_b;
				if (moves < algoritmia->moves_b)
					algoritmia->moves_b = -moves;
			}
			else
			{
				while (tmp_a->number >= tmp_b->number && tmp_a <= algoritmia->last_b)
				{
					tmp_b = tmp_b->next;
					moves++;
				}
				algoritmia->moves_b = moves;
				moves = check_length(b) - algoritmia->moves_b;
				if (moves < algoritmia->moves_b)
					algoritmia->moves_b = -moves;
			}
			if (algoritmia->moves_b - pos)
			tmp_a = tmp_a->next;
		}
	}
	return (algoritmia->position);
}

