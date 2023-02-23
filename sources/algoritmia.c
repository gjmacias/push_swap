
#include "push_swap.h"

int	ft_min(t_stack **b)
{
	t_stack	*tmp;
	int		min;

	tmp = (*b);
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

int	ft_max(t_stack **b)
{
	t_stack	*tmp;
	int		max;

	tmp = (*b);
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

int	ft_last(t_stack **b)
{
	t_stack	*tmp;

	tmp = (*b);
	while (tmp)
		(tmp) = (tmp)->next;
	return (tmp->number);
}

void    start_algoritmia(t_algoritmia *algoritmia, t_stack **b)
{
    algoritmia->length_b = check_length(b);
    algoritmia->last_b = ft_last(b);
    algoritmia->max_b = ft_max(b);
    algoritmia->min_b = ft_min(b);
    algoritmia->moves_b = 0;
	algoritmia->less_moves = INT_MAX;
    algoritmia->position = 0;
}
