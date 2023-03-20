
#include "push_swap.h"

void	end_search(t_stack **a, int min)
{
	int	tmp;
	int	moves;
	int	moves2

	tmp = (*a);
	moves = 0;
	while (tmp->number = min)
	{
		tmp = tmp->next;
		moves++;
	}
	moves2 = check_lenght(a) - moves;
	if (moves <= moves2)
		return (moves);
	else
		return (-moves2);
}

void finish_him(t_parameters *parameters)
{
	int	tmp;
	int	move;

	tmp = ft_last(&parameters->a);
	while (check_length(&parameters->a) != parameters->length)
	{
		if (parameters->b->number < tmp)
		{
			rr_stack(&parameters->a, 'a');
			tmp = ft_last(&parameters->a);
		}
		else
			p_stack(&parameters->b, &parameters->a, 'b');
	}
	tmp = ft_min(&parameters->a);
	move = end_search(&parameters->a, tmp);
	if (move > 0)
	{
		while (--move >= 0)
			r_stack(a, 'a');
	}
	else
	{
		while ( ++move <= 0)
			rr_stack(a, 'a');
	}
}
