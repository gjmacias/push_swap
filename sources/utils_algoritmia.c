
#include "push_swap.h"

int	ft_min(t_stack **b)
{
	t_stack	*tmp;
	int		min;

	if (*b == NULL)
		return (0);
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

int	ft_min_array(int *array)
{
	int	result;
	int	i;

	result = INT_MAX;
	i = -1;
	while (++i != 4)
	{
		if (array[i] < result)
			result = array[i];
	}
	return (result);
}

int	ft_max(t_stack **b)
{
	t_stack	*tmp;
	int		max;

	if (*b == NULL)
		return (0);
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

int	ft_max_int(int a, int b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

int	ft_last(t_stack **b)
{
	t_stack	*tmp;
	if (*b == NULL)
		return (0);
	tmp = (*b);
	while (tmp->next)
		(tmp) = (tmp)->next;
	return (tmp->number);
}
