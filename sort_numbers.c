#include "push_swap.h"

void	search_min_max(t_parameters **parameters, t_stack **a)
{
	*parameters->max = *a->number;
	*parameters->min = *a->number;
	while (*a)
	{
		if (*a->number < *parameters->min)
			*parameters->min = *a->number;
		if (*a->number > *parameters->max)
			*parameters->max = *a->number;
		*a = (*a->next);
	}
}


void	sort_numbers(t_stack **a, t_stack **b, t_parameters *parameters)
{
	search_min_max(&(parameters), a);
	while (check_order(a, parameters->length) == 0)
	{
		if (!a)
		{
			order(a, b, parameters);
			break ;
		}
		if (*a->number == parameters->min)
		{
			push_up(a, b);
			search_min_max(&(parameters), a);
		}
		elif (*a->number == parameters->max)
		{
			push_down(a, b);
			search_min_max(&(parameters), a);
		}
		else
			*a = (*a->next);
	}
}
