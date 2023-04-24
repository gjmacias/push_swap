/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_him.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmacias- <gmacias-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 10:09:36 by gmacias-          #+#    #+#             */
/*   Updated: 2023/04/13 10:09:40 by gmacias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

{
	t_stack	*tmp;

	while ((*a))
	{
		tmp = (*a);
		(*a) = (*a)->next;
		free(tmp);
		tmp = NULL;
	}
}

int	end_search(t_stack **a, int min)
{
	t_stack	*tmp;
	int		moves;
	int		moves2;

	tmp = (*a);
	moves = 0;
	while (tmp->number != min)
	{
		tmp = tmp->next;
		moves++;
	}
	moves2 = check_length(a) - moves;
	if (moves <= moves2)
		return (moves);
	else
		return (-moves2);
}

void	reorder(t_stack **a, int min, char c)
{
	int	move;

	move = end_search(a, min);
	if (move > 0)
	{
		while (--move >= 0)
			r_stack(a, c);
	}
	else
	{
		while (++move <= 0)
			rr_stack(a, c);
	}
}

void	finish_him(t_parameters *p)
{
	int	tmp;
	int	move;

	reorder(&p->b, ft_max(&p->b), 'b');
	tmp = ft_last(&p->a);
	move = p->b->number;
	if (tmp > move)
		rr_stack(&p->a, 'a');
	else
		p_stack(&p->b, &p->a, 'a');
	tmp = ft_last(&p->a);
	move = ft_max(&p->a);
	while (check_length(&p->a) != p->length)
	{
		if (tmp > p->b->number && tmp != move)
		{
			rr_stack(&p->a, 'a');
			tmp = ft_last(&p->a);
		}
		else
			p_stack(&p->b, &p->a, 'a');
	}
	reorder(&p->a, ft_min(&p->a), 'a');
}
