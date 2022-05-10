#include "push_swap.h"

void	p_stack()
{
	
}

void	s_stack(t_stack **top)
{
	int	tmp;

	if ((*top) && (*top->next))
	{
		tmp = *top->number;
		*top->number = *top->next->number;
		*top->next->number = tmp;
	}
}
