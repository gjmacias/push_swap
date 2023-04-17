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

int	search_less_moves(t_algoritmia *alg, t_stack **a, t_stack **b)
{
	int	option[4];
	int	result;

	alg->moves_a_rra = check_length(a) - alg->moves_a_ra + 2;
	alg->moves_b_rra = check_length(b) - alg->moves_b_ra;
	option[0] = ft_max_int(alg->moves_a_ra, alg->moves_b_ra);
	option[1] = ft_max_int(alg->moves_a_rra, alg->moves_b_rra);
	option[2] = alg->moves_a_ra + alg->moves_b_rra;
	option[3] = alg->moves_a_rra + alg->moves_b_ra;
	result = ft_min_array(option);
	if (result < alg->less_moves)
	{
		if (result == option[0] || result == option[2])
			alg->moves_a = alg->moves_a_ra;
		else
			alg->moves_a = -(alg->moves_a_rra);
		if (result == option[0] || result == option[3])
			alg->moves_b = alg->moves_b_ra;
		else
			alg->moves_b = -(alg->moves_b_rra);
		alg->less_moves = result;
	}
	alg->last_b = ft_last(b);
	return (alg->less_moves);
}

int	condition_of_slp(t_stack **tmp0, t_stack **tmp1, t_algoritmia *al)
{
	t_stack	*tmp[2];
	int		result1;
	int		result2;
	int		result;

	tmp[0] = (*tmp0);
	tmp[1] = (*tmp1);
	result1 = ((tmp[0]->number > al->max_b || tmp[0]->number < al->min_b)
			&& (tmp[1]->number != al->max_b));
	result2 = (!(tmp[0]->number > al->max_b || tmp[0]->number < al->min_b)
			&& !(tmp[0]->number > tmp[1]->number
				&& tmp[0]->number < al->last_b));
	result = (result1 || result2);
	return (result);
}

void	search_less_pos(t_stack **a, t_stack **b, t_algoritmia *al)
{
	t_stack	*tmp[2];
	int		moves;

	tmp[0] = (*a);
	while (tmp[0])
	{
		tmp[1] = (*b);
		moves = 0;
		while (condition_of_slp(&tmp[0], &tmp[1], al))
		{
			al->last_b = tmp[1]->number;
			tmp[1] = tmp[1]->next;
			moves++;
		}
		al->moves_b_ra = moves;
		al->moves_a_ra = tmp[0]->position;
		moves = al->less_moves;
		if (search_less_moves(al, a, b) < moves)
			al->position = tmp[0]->position;
		tmp[0] = tmp[0]->next;
	}
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

int	order_3(t_stack **a, int min, int max)
{
	t_stack	*tmp;

	tmp = (*a)->next;
	if (check_length(a) == 2)
	{
		if ((*a)->number > tmp->number)
			r_stack(a, 'a');
		return (1);
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
	return (1);
}

void	order(t_parameters *p)
{
	t_algoritmia	*a;

	a = malloc(sizeof(t_algoritmia));
	if (!a)
		ft_error(0);
	while (check_order(&p->a, p->length))
	{
		if (p->length_a <= 3)
		{
			order_3(&p->a, ft_min(&p->a), ft_max(&p->a));
			if (check_length(&p->a) == p->length)
				reorder(&p->a, ft_min(&p->a), 'a');
			else
				finish_him(p);
		}
		else if (!(p->b))
			p_stack(&p->a, &p->b, 'b');
		else
			start_algoritmia(a, p);
		p->length_a = check_length(&p->a);
	}
}
