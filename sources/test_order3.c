#include <stdio.h>
#include "push_swap.h"

int ft_error(int num)
{
    exit(0);
    return (num);
}

int	check_number(t_stack **a)
{
	t_stack	*tmp;

	tmp = (*a);
	while (tmp)
	{
		printf("%d", tmp->number);
		(tmp) = (tmp)->next;
	}
	tmp = NULL;
    printf("\n");
    return(0);
}

int	check_length(t_stack **a)
{
	int		len;
	t_stack	*tmp;

	len = 0;
	tmp = (*a);
	while (tmp)
	{
		len ++;
		(tmp) = (tmp)->next;
	}
	tmp = NULL;
	return (len);
}

void	order_3(t_stack **a, int min, int max)
{
	t_stack	*tmp;

	tmp = (*a)->next;
	if (check_length(a) == 2 && (*a)->number > tmp->number)
	{
		r_stack(a, 'a');
		return ;
	}
	tmp = tmp->next;
	while (!((*a)->number == min && tmp->number == max))
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
        tmp = (*a)->next->next;
        check_number(a);
	}
}

int main()
{
    t_stack *a;
    a = malloc(sizeof(t_stack));
    t_stack *b;
    b = malloc(sizeof(t_stack));
    t_stack *c;
    c = malloc(sizeof(t_stack));
    t_stack *d;
    d = malloc(sizeof(t_stack));
    t_stack *e;
    e = malloc(sizeof(t_stack));
    t_stack *f;
    f = malloc(sizeof(t_stack));
    a->number = 1;
    b->number = 3;
    c->number = 2;
    d->number = 4;
    e->number = 5;
    f->number = 6;
    a->next = b;
    b->next = c;
    c->next = NULL;
    d->next = e;
    e->next = f;
    f->next = NULL;
    check_number(&a);
    order_3(&a, 1, 3);
    check_number(&a);
}