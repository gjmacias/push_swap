
#include "push_swap.h"

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

void	finish_him(t_parameters *p)
{
	int	tmp;
	int	move;
int is_min;

	is_min = 0;
	tmp = ft_last(&p->a);
	while (check_length(&p->a) != p->length)
	{
		if (p->b->number < tmp && !(p->b->number < ft_min(&p->a)
				&& p->a->number == ft_min(&p->a)))
		{
			rr_stack(&p->a, 'a');
			tmp = ft_last(&p->a);
		}
		else if (is_min == 0 && p->b->number == ft_max(&p->b))
		{
			while (p->a->number != ft_min(&p->a))
				rr_stack(&p->a, 'a');
			is_min = 1;
		}
		else
		{
			p_stack(&p->b, &p->a, 'a');
		}
	}
	tmp = ft_min(&p->a);
	move = end_search(&p->a, tmp);
	if (move > 0)
	{
		while (--move >= 0)
			r_stack(&p->a, 'a');
	}
	else
	{
		while (++move <= 0)
			rr_stack(&p->a, 'a');
	}
}
