/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmacias- <gmacias-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:41:39 by gmacias-          #+#    #+#             */
/*   Updated: 2023/02/22 20:10:38 by gmacias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	p_stack(t_stack **a, t_stack **b, char c)
{
	t_stack	*tmp;

	tmp = (t_stack *) malloc(sizeof(t_stack));
	if (tmp == NULL)
		ft_error(0);
	tmp->number = (*a)->number;
	tmp->next = NULL;
	ft_stkadd_front(b, tmp);
	tmp = (*a);
	(*a) = (*a)->next;
	if (c == 'a')
		write(1, "pa\n", 3);
	else
		write(1, "pb\n", 3);
	free(tmp);
}

void	s_stack(t_stack **top, char c)
{
	int	tmp;

	if ((*top) && ((*top)->next))
	{
		tmp = (*top)->number;
		(*top)->number = (*top)->next->number;
		(*top)->next->number = tmp;
	}
	if (c == 'a')
		write(1, "sa\n", 3);
	else
		write(1, "sb\n", 3);
}

void	ss_stack(t_stack **a, t_stack **b)
{
	s_stack(a, 'a');
	s_stack(b, 'b');
	write(1, "ss\n", 3);
}
<<<<<<< HEAD

void	order(t_stack **a, t_stack **b, t_parameters *parameters)
{
	while ((*b) != NULL)
	{
		p_stack(b, a, 'b');
	}
	search_min_max(&(parameters), a);
	while ((*a)->number != parameters->min)
	{
		if (calculus(parameters, a) == 0)
			r_stack(a, 'a');
		else
			rr_stack(a, 'a');
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

void	order_3(t_stack **a, t_parameters *parameters)
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
	while (((*a)->number != parameters->min
			|| tmp->number != parameters->max) && ++i != 3)
	{
		if ((*a)->number != parameters->min
			&& (*a)->number != parameters->max
			&& tmp->number == parameters->min)
			rr_stack(a, 'a');
		else if ((*a)->number == parameters->max
			&& tmp->number != parameters->min
			&& tmp->number != parameters->max)
			r_stack(a, 'a');
		else
			s_stack(a, 'a');
	}
}
=======
>>>>>>> 98b83dc08a93166c5380cb224245d039121d9b4e
