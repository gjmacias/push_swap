#include "push_swap.h"
#include <stdio.h>

void	fill_position(t_stack **a)
{
	int		i;
	t_stack	*tmp;

	if (!(*a))
		return ;
	i = 0;
	tmp = (*a);
	while (tmp)
	{
		tmp->position = ++i;
		tmp = tmp->next;
	}
	tmp = NULL;
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

void	start_algoritmia(t_algoritmia *algoritmia, t_stack **b)
{
	algoritmia->last_b = ft_last(b);
	algoritmia->max_b = ft_max(b);
	algoritmia->min_b = ft_min(b);
	algoritmia->moves_b_ra = 0;
	algoritmia->moves_b_rra = 0;
	algoritmia->moves_a_ra = 0;
	algoritmia->moves_a_rra = 0;
	algoritmia->moves_a = 0;
	algoritmia->moves_b = 0;
	algoritmia->less_moves = INT_MAX;
	algoritmia->position = 0;
}

int	search_less_moves(t_algoritmia *algoritmia, t_stack **a, t_stack **b)
{
	int	option[4];
	int	result;

	algoritmia->moves_a_rra = check_length(a) - algoritmia->moves_a_ra;
	algoritmia->moves_b_rra = check_length(b) - algoritmia->moves_b_ra + 2;
	option[0] = ft_max_int(algoritmia->moves_a_ra, algoritmia->moves_b_ra);
	option[1] = ft_max_int(algoritmia->moves_a_rra, algoritmia->moves_b_rra);
	option[2] = algoritmia->moves_a_ra + algoritmia->moves_b_rra;
	option[3] = algoritmia->moves_a_rra + algoritmia->moves_b_ra;
    printf("Position: %d\n",
    printf("Position: %d\n",
    printf("Position: %d\n",
    printf("Position: %d\n",
	result = ft_min_array(option);
	if (result < algoritmia->less_moves)
	{
		if (result == option[0] || result == option[2])
			algoritmia->moves_a = algoritmia->moves_a_ra;
		else
			algoritmia->moves_a = -(algoritmia->moves_a_rra);
		if (result == option[0] || result == option[3])
			algoritmia->moves_b = algoritmia->moves_b_ra;
		else
			algoritmia->moves_b = -(algoritmia->moves_a_rra);
		algoritmia->less_moves = result;
	}
    printf("\n");
	return (algoritmia->less_moves);
}

int	search_less_position(t_stack **a, t_stack **b, t_algoritmia *algoritmia)
{
	t_stack			*tmp_a;
	t_stack			*tmp_b;
	int				moves;
    int             minmax;
    int             tmp_b_last;

    tmp_b_last = algoritmia->last_b;
	tmp_a = (*a);
	while (tmp_a)
	{
        minmax = (tmp_a->number > algoritmia->max_b || tmp_a->number < algoritmia->min_b);
		tmp_b = (*b);
        tmp_b_last = algoritmia->last_b;
		moves = 0;
        printf(" a: %d,", tmp_a->number);
		while ((minmax && (tmp_b->number != algoritmia->max_b))
			|| (!(minmax) && (tmp_a->number < tmp_b->number 
                || tmp_a->number > tmp_b_last)))
		{
            tmp_b_last = tmp_b->number;
			tmp_b = tmp_b->next;
			moves++;
        }
        printf(" b: %d,", tmp_b->number);
        printf(" moves: %d, ", moves);
        algoritmia->moves_b_ra = moves;
		algoritmia->moves_a_ra = tmp_a->position;
        printf(" position: %d\n", tmp_a->position);
		moves = algoritmia->less_moves;
		if (search_less_moves(algoritmia, a, b) < moves)
		 	algoritmia->position = tmp_a->position;
		tmp_a = tmp_a->next;
	}
    printf("\n");
	return (algoritmia->position);
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
    t_algoritmia *algoritmia;
    algoritmia = malloc(sizeof(t_algoritmia));

    a->number = 1;
    b->number = 6;
    c->number = 4;
    d->number = 5;
    e->number = 3;
    f->number = 2;
    a->next = b;
    b->next = c;
    c->next = NULL;
    d->next = e;
    e->next = f;
    f->next = NULL;

    fill_position(&a);
    fill_position(&d);
    start_algoritmia(algoritmia, &d);
    search_less_position(&a, &d, algoritmia);
    
	printf("Total A: %d,",algoritmia->moves_a);
	printf("Total B: %d\n",algoritmia->moves_b);
	printf("Less moves: %d,",algoritmia->less_moves);
	printf("Position: %d\n",algoritmia->position);
    printf("\n");
    
    printf("Stack a: %d,", a->number);
    printf(" %d,", b->number);
    printf(" %d\n", c->number);
    
    printf("Stack d: %d,", d->number);
    printf(" %d,", e->number);
    printf(" %d\n", f->number);
    return (0);
}