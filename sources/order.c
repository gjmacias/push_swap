#include "push_swap.h"

int	ft_min (t_stack **a)
{
	t_stack *tmp;
	int min;
	
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

int	ft_max (t_stack **a)
{
	t_stack *tmp;
	int max;
	
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
	int i;
	
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
	while(check_order(parameters->a, parameters->length) != 0)
	{
		if (parameters->length <= 3)
			order_3(parameters->a, ft_min(parameters->a), ft_max(parameters->a));
		else
		{
			fill_position(parameters->a);
			fill_position(parameters->b);
			tsearch
		}
	}
}
