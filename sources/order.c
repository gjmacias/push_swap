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

int	search_less_moves(t_algoritmia *algoritmia, t_stack **a, t_stack **b)
{
	int	option[4];
	int	result;

	algoritmia->moves_a_rra = check_length(a) - algoritmia->moves_a_ra;
	algoritmia->moves_b_rra = check_length(b) - algoritmia->moves_b_ra + 2;
	option[0] = ft_max_int(algoritmia->moves_a_ra, algoritmia->moves_b_ra);
	option[1] = ft_max_int(algoritmia->moves_a_rra, algoritmia->moves_b_rra);
	option[2] = algoritmia->moves_a_ra + algoritmia->moves_b_rra;
	option[3] = algoritmia->moves_a_rra + algoritmia->moves_b_ra;
	result = ft_min_array(option);
	if (result < algoritmia->less_moves)
	{
		if (result == option[0] || result == option[2])
			algoritmia->moves_a = algoritmia->moves_a_ra;
		else
			algoritmia->moves_a = -(algoritmia->moves_a_rra);
		if (result == option[0] || result == option[3])
			algoritmia->moves_b = algoritmia->moves_b_ra;
		else
			algoritmia->moves_b = -(algoritmia->moves_a_rra);
		algoritmia->less_moves = result;
	}
	return (algoritmia->less_moves);
}

int	search_less_position(t_stack **a, t_stack **b, t_algoritmia *algoritmia)
{
	t_stack			*tmp_a;
	t_stack			*tmp_b;
	int				moves;

	tmp_a = (*a);
	while (tmp_a)
	{
		tmp_b = (*b);
		moves = 0;
		while (((tmp_a->number > algoritmia->max_b
					|| tmp_a->number < algoritmia->min_b)
				&& (tmp_b->number != algoritmia->max_b))
			|| (tmp_a->number > tmp_b->number && tmp_a < algoritmia->last_b))
		{
			tmp_b = tmp_b->next;
			moves++;
		}
		algoritmia->moves_b_ra = moves;
		algoritmia->moves_a_ra = tmp_a->position;
		moves = algoritmia->less_moves;
		if (search_less_moves(algoritmia, a, b) < moves)
			algoritmia->position = tmp_a->position;
		tmp_a = tmp_a->next;
	}
	return (algoritmia->position);
}

void	make_position(int position, t_algoritmia *alg, t_parameters *param)
{
	if (alg->moves_a > 0 && alg->moves_b > 0)
	{
		while (alg->moves_b-- != 0 || alg->moves_a-- != 1)
			r_rboth(param->a, param->b);
	}
	else if (alg->moves_a < 0 && alg->moves_b < 0)
	{
		while (alg->moves_b++ != 0 || alg->moves_a++ != -1)
			rr_rboth(param->a, param->b);
	}
	if (alg->moves_a > 0)
	{
		while (alg->moves_a-- != 1)
			r_stack(param->a, 'a');
	}
	else if (alg->moves_a < 0)
	{
		while (alg->moves_a++ != -1)
			rr_stack(param->a, 'a');
	}
	if (alg->moves_b >= 1)
	{
		while (alg->moves_b-- != 0)
			r_stack(param->b, 'b');
	}
	else if (alg->moves_b <= 1)
	{
		while (alg->moves_b++ != 0)
			rr_stack(param->b, 'b');
	}
	p_stack(param->a, param->b, 'a');
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
	return (1);
}

void	order(t_parameters *parameters)
{
	t_algoritmia	*algoritmia;
	int				reverse;

	reverse = 0;
	algoritmia = malloc(sizeof(t_algoritmia));
	if (!algoritmia)
		ft_error(0);
	while (check_order(&parameters->a, parameters->length) != 0)
	{
		if (parameters->length <= 3)
			reverse = order_3(&parameters->a, ft_min(parameters->a),
					ft_max(parameters->a));
		else if (reverse == 1)
			finish_him(parameters);
		else
		{
			start_algortimia(algoritmia, parameters->b);
			fill_position(parameters->a);
			fill_position(parameters->b);
			make_position(search_less_position(parameters->a, parameters->b,
					algoritmia), algoritmia, parameters);
		}
	}
}
