#include "push_swap.h"

void    add_front(t_stack **stack, t_stack *new)
{
    new->next = (*stack);
    (*stack) = new;
}

void    add_back(t_stack **stack, t_stack *new)
{
    t_stack *tmp;
    
    if ((*stack) == NULL)
        (*stack) = new;
    else
    {
        tmp = (*stack);
	    while (tmp->next)
	        tmp = tmp->next;
    tmp->next = new;
    }
}

void	p_stack(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = (t_stack *) malloc(sizeof(t_stack));
	if (tmp == NULL)
		return (NULL);
	if (*b == NULL)
	{
		(*b) = (t_stack *) malloc(sizeof(t_stack));
		if ((*b) == NULL)
			return (NULL);
		(*b)->number = (*a)->number;
		(*b)->next = NULL;
		tmp = (*a);
		(*a) = (*a)->next;
	}
	else
	{
		tmp->number = (*a)->number;
		tmp->next = NULL;
		add_front(b, tmp);
		tmp = (*a);
		(*a) = (*a)->next;
	}
	free(tmp);
}

void	s_stack(t_stack **top)
{
	int	tmp;

	if ((*top) && ((*top)->next))
	{
		tmp = (*top)->number;
		(*top)->number = (*top)->next->number;
		(*top)->next->number = tmp;
	}
}
