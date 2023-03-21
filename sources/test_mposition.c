#include "push_swap.h"
#include <stdio.h>

int ft_error(int num)
{
    exit(0);
    return (num);
}

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

void	start_algoritmia(t_algoritmia *algoritmia, t_parameters *p)
{
	if ((p->b) == NULL)
		p_stack(&p->a, &p->b,'b');
	algoritmia->last_b = ft_last(&p->b);
	algoritmia->max_b = ft_max(&p->b);
	algoritmia->min_b = ft_min(&p->b);
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

	algoritmia->moves_a_rra = check_length(a) - algoritmia->moves_a_ra + 2;
	algoritmia->moves_b_rra = check_length(b) - algoritmia->moves_b_ra;
	option[0] = ft_max_int(algoritmia->moves_a_ra, algoritmia->moves_b_ra);
	option[1] = ft_max_int(algoritmia->moves_a_rra, algoritmia->moves_b_rra);
	option[2] = algoritmia->moves_a_ra + algoritmia->moves_b_rra;
	option[3] = algoritmia->moves_a_rra + algoritmia->moves_b_ra;
	printf("Position: %d\n",option[0]);
    printf("Position: %d\n",option[1]);
    printf("Position: %d\n",option[2]);
    printf("Position: %d\n",option[3]);
	result = ft_min_array(option);
	printf("result: %d\n",result);
	printf("less_moves: %d\n",algoritmia->less_moves);
	if (result < algoritmia->less_moves)
	{
		if (result == option[0] || result == option[2])
			algoritmia->moves_a = algoritmia->moves_a_ra;
		else
			algoritmia->moves_a = -(algoritmia->moves_a_rra);
		if (result == option[0] || result == option[3])
			algoritmia->moves_b = algoritmia->moves_b_ra;
		else
			algoritmia->moves_b = -(algoritmia->moves_b_rra);
		algoritmia->less_moves = result;
	}
	algoritmia->last_b = ft_last(b);
	return (algoritmia->less_moves);
}

int	search_less_position(t_stack **a, t_stack **b, t_algoritmia *al)
{
	t_stack			*tmp[2];
	int				moves;

	tmp[0] = (*a);
	while (tmp[0])
	{
		tmp[1] = (*b);
		moves = 0;
		while (((tmp[0]->number > al->max_b || tmp[0]->number < al->min_b)
				&& (tmp[1]->number != al->max_b))
			|| (!(tmp[0]->number > al->max_b || tmp[0]->number < al->min_b)
				&& !(tmp[0]->number > tmp[1]->number && tmp[0]->number < al->last_b)))
		{
			al->last_b = tmp[1]->number;
			tmp[1] = tmp[1]->next;
			moves++;
		}
		al->moves_b_ra = moves;
		al->moves_a_ra = tmp[0]->position;
		moves = al->less_moves;
		if (search_less_moves(al, a, b) < moves)
			al->position = tmp[0]->position;
		tmp[0] = tmp[0]->next;
	}
    printf("\n");
	return (al->position);
}

void	make_position(int position, t_algoritmia *alg, t_parameters *param)
{
	if (alg->moves_a > 1 && alg->moves_b > 0)
	{
		while (alg->moves_b-- != 0 || alg->moves_a-- != 1)
			r_rboth(&param->a, &param->b);
	}
	else if (alg->moves_a < -1 && alg->moves_b < 0)
	{
		while (alg->moves_b++ != 0 || alg->moves_a++ != -1)
			rr_rboth(&param->a, &param->b);
	}
	if (alg->moves_a > 1)
	{
		while (alg->moves_a-- != 1)
			r_stack(&param->a, 'a');
	}
	else if (alg->moves_a < -1)
	{
		while (alg->moves_a++ != -1)
			rr_stack(&param->a, 'a');
	}
	if (alg->moves_b > 0)
	{
		while (alg->moves_b-- != 0)
			r_stack(&param->b, 'b');
	}
	else if (alg->moves_b < 0)
	{
		while (alg->moves_b++ != 0)
			rr_stack(&param->b, 'b');
	}
	p_stack(&param->a, &param->b, 'b');
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
	t_stack *g;
    g = malloc(sizeof(t_stack));
    t_algoritmia *algoritmia;
    algoritmia = malloc(sizeof(t_algoritmia));
	t_parameters *p;
    p = malloc(sizeof(t_algoritmia));

    a->number = 4;
    b->number = 8;
    c->number = 9;
    d->number = 2;
    e->number = 7;
    f->number = 5;
	g->number = 3;
    a->next = b;
    b->next = c;
    c->next = NULL;
    d->next = e;
    e->next = f;
    f->next = g;
    g->next = NULL;

    fill_position(&a);
    fill_position(&d);
	p->a = a;
	p->b = d;
    start_algoritmia(algoritmia, p);
    //search_less_position(&a, &d, algoritmia);
	printf("Stack a: %d,", a->number);
    printf(" %d,", b->number);
    printf(" %d\n", c->number);
    
    printf("Stack d: %d,", d->number);
    printf(" %d,", e->number);
    printf(" %d,", f->number);
    printf(" %d\n", g->number);

    make_position(search_less_position(&a, &d, algoritmia), algoritmia, p);

	printf("Total A: %d,",algoritmia->moves_a);
	printf("Total B: %d\n",algoritmia->moves_b);
	printf("Less moves: %d,",algoritmia->less_moves);
	printf("Position: %d\n",algoritmia->position);
    printf("\n");
    
	printf("Stack a: ");
	while (p->a)
	{
    	printf("%d, ", p->a->number);
		p->a = p->a->next;
    }
	printf("\n");
    
	printf("Stack d: ");
    while (p->b)
	{
    	printf("%d, ", p->b->number);
		p->b = p->b->next;
    }
    return (0);
}