#include "push_swap.h"

void	r_stack(t_stack **a)
{
	t_stack	tmp;
	
	tmp = (t_stack *)malloc(sizeof(t_stack));
	if (!tmp)
		return (NULL);
	tmp = (*top);
	while (*top)
		(*top) = (*top)->next;
	(*top)->next = tmp;
	tmp
}

void	r_rboth(t_stack **a, t_stack **b)
{
	r_stack(a);
	r_stack(b);
}

void	rr_stack(t_stack **a)
{

}

void	rr_rboth(t_stack **a, t_stack **b)
{
	rr_stack(a);
	rr_stack(b);
}
