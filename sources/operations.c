/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmacias- <gmacias-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:41:39 by gmacias-          #+#    #+#             */
/*   Updated: 2023/02/22 20:24:39 by gmacias-         ###   ########.fr       */
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
