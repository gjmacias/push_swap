
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

int   supermoves = 0;

typedef struct s_algoritmia
{
	int		last_b;
	int		min_b;
	int		max_b;
	int		moves_b_ra;
	int		moves_b_rra;
	int		moves_a_ra;
	int		moves_a_rra;
	int		moves_a;
	int		moves_b;
	int		less_moves;
	int		position;
}	t_algoritmia;

typedef struct s_stack
{
	int				number;
	int				position;
	struct s_stack	*next;
}	t_stack;

typedef struct s_parameters
{
	char	*line;
	char	**split;
	char	**arguments;
	int		length_a;
	int		length;
	t_stack	*a;
	t_stack	*b;
	t_stack	*perfection;
}	t_parameters;


/*Checkers*/
int		check_length(t_stack **a);
int		check_order(t_stack **a, int length);
void	check_duplicate(t_stack **a);
int		check_atoi(const char *str);
void	check_is_number(char **split);
/*Llenado de infomacion*/
t_stack	*fill_stack(t_parameters *parameters, char **split);
char	**fill_split(t_parameters *parameters, char **arguments);
void	fill_position(t_stack **a);
/*Operaciones ejecutables*/
void	p_stack(t_stack **a, t_stack **b, char c);
void	s_stack(t_stack **top, char c);
void	r_stack(t_stack **stack, char c);
void	r_rboth(t_stack **a, t_stack **b);
void	rr_stack(t_stack **stack, char c);
void	rr_rboth(t_stack **a, t_stack **b);
void	ft_stkadd_front(t_stack **stack, t_stack *new);
void	ft_stkadd_back(t_stack **stack, t_stack *new);
/*Ordenación*/
int		search_less_moves(t_algoritmia *algoritmia, t_stack **a, t_stack **b);
int		search_less_position(t_stack **a, t_stack **b, t_algoritmia *al);
void	make_position(int position, t_algoritmia *alg, t_parameters *param);
int		order_3(t_stack **a, int min, int max);
void	order(t_parameters *parameters);
/*Utiles de algoritmia*/
int		ft_min(t_stack **b);
int		ft_min_array(int *array);
int		ft_max(t_stack **b);
int		ft_max_int(int a, int b);
int		ft_last(t_stack **b);
/*Programa*/
void	start_algoritmia(t_algoritmia *algoritmia, t_parameters *p);
void	push_swap(t_parameters *parameters, char **arguments);
t_parameters	*ft_init_parameters(t_parameters *parameters);

/*tests*/
int		ft_error(int num);
void	finish_him(t_parameters *param);
int	ft_sign(char *str);
int	ft_atoi(const char *str);









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

int	check_order(t_stack **a, int length)
{
	t_stack	*tmp;

	if (check_length(a) != length)
		return (-1);
	tmp = *a;
	while (tmp && tmp->next)
	{
		if (tmp->number < tmp->next->number)
			tmp = tmp->next;
		else
			return (-1);
	}
	return (0);
}

void	check_duplicate(t_stack **a)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	tmp1 = (*a);
	while (tmp1)
	{
		tmp2 = tmp1->next;
		while (tmp2)
		{
			if (tmp1->number == tmp2->number)
				ft_error(0);
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
}

int	check_atoi(const char *str)
{
	int				sign;
	int				i;
	long long int	num;

	i = 0;
	num = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\r' || str[i] == '\f')
		i++;
	sign = ft_sign((char *)&str[i]);
	while (str[i] == '+' || str [i] == '-')
		i++;
	if (str[i] < '0' || str[i] > '9')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		if (num > INT_MAX || (sign * num) < INT_MIN || str[++i] == ' ')
			return (0);
	}
	return (42);
}

void	check_is_number(char **split)
{
	int	i;

	if (!split[0])
		ft_error(0);
	i = -1;
	while (split[++i])
	{
		if (check_atoi(split[i]) == 0)
			ft_error(0);
	}
}

t_stack	*fill_stack(t_parameters *parameters, char **split)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	while (split[i])
	{
		tmp = malloc(sizeof(t_stack));
		if (tmp == NULL)
			ft_error(0);
		tmp->number = ft_atoi(split[i++]);
		tmp->position = i;
		tmp->next = NULL;
		ft_stkadd_back(&parameters->a, tmp);
		tmp = NULL;
	}
	free(tmp);
	return (parameters->a);
}

char	**fill_split(t_parameters *parameters, char **arguments)
{
	parameters->split = &arguments[1];
	return (parameters->split);
}

void	fill_position(t_stack **a)
{
	int		i;
	t_stack	*tmp;

	if ((*a) == NULL)
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

void	ft_stkadd_front(t_stack **stack, t_stack *new)
{
	new->next = (*stack);
	(*stack) = new;
}

/*
** La utilidad del temporal aqui, es muy importante. Esto sirve para que el stack
** principal "stack" no mueva su puntero del ultimo puntero, para eso, creamos al
** temporal "tmp". Este puede recorrer a "stack" sin problema ya que es un caso a
** parte, una vez llega al final de la stack, le anade el valor de "new" DENTRO 
** del "stack", puede parecer confuso, pero tiene sentido:
** 
** 	stack	***		***		***		***			NULL
**	tmp		->		->		->		->		^guarda "new"^		NULL
**
** El temporal se mueve dentro del stack y le anade al final, en el (null), el
** nuevo stack, que este nuevo stack apuntara a (null) siendo ahora el final de 
** la cadena.
*/

void	ft_stkadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*tmp;

	if (!(*stack))
	{
		(*stack) = new;
		return ;
	}
	if (new)
	{
		tmp = (*stack);
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}


void	r_stack(t_stack **stack, char c)
{
	t_stack	*tmp;

	tmp = (*stack);
	(*stack) = (*stack)->next;
	tmp->next = NULL;
	ft_stkadd_back(stack, tmp);
	if (c == 'a')
		write(1, "ra\n", 3);
	else  if (c == 'b')
		write(1, "rb\n", 3);
	supermoves = supermoves + 1;
}

void	r_rboth(t_stack **a, t_stack **b)
{
	r_stack(a, ' ');
	r_stack(b, ' ');
	write(1, "rr\n", 3);
	supermoves = supermoves - 1;
}

/*
** En "rr_stack" guardamos el ultimo puntero en "tmp", pero tenemos el mismo
** problema que: "libft/ft_lstadd_back.c".
** por ello hacemos otro temporal aparte para que lo recorra: "stack_tmp". ya
** tenemos los necesarios;
** "tmp" = guarda el puntero	"stack_tmp" = recorre la lista.
** 
** En este caso queremos recorrer hasta llegar a las ultimas 3 posiciones:
**	t_stack		...		f		g		NULL
**	numero		...		123		456
**	puntero		f		g		(null)
**	posicion	x		stk_tmp-next->	next
** En este caso "tmp" sera igual a g, osea "stack_tmp->next" YYY como g ya esta
** guardado,g lo convertimos en (null) PARA LA LISTA. Asi f tendria; 
** 123 y (null) apuntando a NULL
*/

void	rr_stack(t_stack **stack, char c)
{
	t_stack	*tmp;
	t_stack	*stack_tmp;

	stack_tmp = (*stack);
	while (stack_tmp->next->next)
		stack_tmp = stack_tmp->next;
	tmp = stack_tmp->next;
	stack_tmp->next = NULL;
	ft_stkadd_front(stack, tmp);
	if (c == 'a')
		write(1, "rra\n", 4);
	else if (c == 'b')
		write(1, "rrb\n", 4);
	supermoves = supermoves + 1;
}

void	rr_rboth(t_stack **a, t_stack **b)
{
	rr_stack(a, ' ');
	rr_stack(b, ' ');
	write(1, "rrr\n", 4);
	supermoves = supermoves - 1;
}

void	p_stack(t_stack **a, t_stack **b, char c)
{
	t_stack	*tmp;

	tmp = (t_stack *) malloc(sizeof(t_stack));
	if (tmp == NULL)
		ft_error(0);
	tmp->number = (*a)->number;
	tmp->next = NULL;
	ft_stkadd_front(b, tmp);
	tmp = (*a);
	(*a) = (*a)->next;
	if (c == 'a')
		write(1, "pa\n", 3);
	else
		write(1, "pb\n", 3);
	free(tmp);
	supermoves = supermoves + 1;
}

void	s_stack(t_stack **top, char c)
{
	int	tmp;

	if ((*top) && ((*top)->next))
	{
		tmp = (*top)->number;
		(*top)->number = (*top)->next->number;
		(*top)->next->number = tmp;
	}
	if (c == 'a')
		write(1, "sa\n", 3);
	else
		write(1, "sb\n", 3);
	supermoves = supermoves + 1;
}

void	ss_stack(t_stack **a, t_stack **b)
{
	s_stack(a, 'a');
	s_stack(b, 'b');
	write(1, "ss\n", 3);
	supermoves = supermoves - 1;
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
				&& !(tmp[0]->number > tmp[1]->number 
					&& tmp[0]->number < al->last_b)))
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
	return (al->position);
}

void	make_position(int position, t_algoritmia *alg, t_parameters *param)
{
	if (alg->moves_a > 1 && alg->moves_b > 0)
	{
		while (alg->moves_b-- != 0 && alg->moves_a-- != 1)
		{
			r_rboth(&param->a, &param->b);
		}
	    alg->moves_b++;
	}
	else if (alg->moves_a < -1 && alg->moves_b < 0)
	{
		while (alg->moves_b++ != 0 && alg->moves_a++ != -1)
			rr_rboth(&param->a, &param->b);
	    alg->moves_b--;
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

/*
** Solo hay estos casos:
**	 	1	1	2	2^	3*	3
**		2	3	1	3	1	2
**		3	2	3	1	2	1
**		ok	sa	sa	rra	ra	sa
**			3*				2^
** 			1	ok	ok	ok	3
**			2				1
** Con el while, se soluciona solo, el valor "i" esta por que lo calcula tan
** rapido que se lagea xD
*/

int	order_3(t_stack **a, int min, int max)
{
	t_stack	*tmp;

	tmp = (*a)->next;
	if (check_length(a) == 2 && (*a)->number > tmp->number)
	{
		r_stack(a, 'a');
		return (1);
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
	}
	return (1);
}

/*
void	order(t_parameters *parameters)
{
	t_algoritmia	*algoritmia;
	int				reverse;
	reverse = 0;
	algoritmia = malloc(sizeof(t_algoritmia));
	if (!algoritmia)
		ft_error(0);
	while (check_order(&parameters->a, parameters->length) != 0)
	{
		if (parameters->length <= 3)
			reverse = order_3(&parameters->a, ft_min(&parameters->a),
					ft_max(&parameters->a));
		else if (reverse == 1)
			finish_him(parameters);
		else
		{
			start_algoritmia(algoritmia, &parameters->b);
			fill_position(&parameters->a);
			fill_position(&parameters->b);
			make_position(search_less_position(&parameters->a, &parameters->b,
					algoritmia), algoritmia, parameters);
		}
	}
}
*/

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

/*
void	push_swap(t_parameters *parameters, char **arguments)
{
	parameters->split = fill_split(parameters, arguments);
	check_is_number(parameters->split);
	parameters->a = fill_stack(parameters, parameters->split);
	check_duplicate(&(parameters->a));
	parameters->b = NULL;
	parameters->length = check_length(&parameters->a);
	parameters->length_a = check_length(&parameters->a);
	order(parameters);
}
*/

t_parameters	*ft_init_parameters(t_parameters *parameters)
{
	parameters = (t_parameters *)malloc(sizeof(t_parameters));
	if (parameters == NULL)
		ft_error(0);
	parameters->line = NULL;
	parameters->split = NULL;
	parameters->length = 0;
	parameters->a = NULL;
	parameters->b = NULL;
	return (parameters);
}

/*
int	main(int nword, char *arguments[])
{
	t_parameters	*parameters;
	parameters = NULL;
	if (nword < 2)
		ft_error(0);
	parameters = ft_init_parameters(parameters);
	push_swap(parameters, arguments);
	free(parameters);
	parameters = NULL;
	exit(EXIT_SUCCESS);
}
*/

int ft_error(int num)
{
	printf("soy error :)");
    exit(0);
    return (num);
}


int	ft_sign(char *str)
{
	int	i;
	int	sign;

	sign = 1;
	i = 0;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	return (sign);
}

int	ft_atoi(const char *str)
{
	int				sign;
	int				i;
	long long int	num;

	i = 0;
	num = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\r' || str[i] == '\f')
		i++;
	sign = ft_sign((char *)&str[i]);
	while (str[i] == '+' || str [i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		if ((num * sign) > INT_MAX || (num * sign) < INT_MIN)
			return (0);
		i++;
	}
	return ((int)num * sign);
}

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

void print(t_stack **a, t_stack **b)
{
	t_stack *tmp;

	tmp = (*a);
	printf("Stack a: ");
	while (tmp)
	{
    	printf("%d, ", tmp->number);
		tmp = tmp->next;
    }
	printf("\n");
    tmp = (*b);
	printf("Stack b: ");
    while (tmp)
	{
    	printf("%d, ", tmp->number);
		tmp = tmp->next;
    }
		printf("\n");
}



























int	end_search(t_stack **a, int min)
{
	t_stack	*tmp;
	int		moves;
	int		moves2;

	tmp = (*a);
	moves = 0;
	while (tmp->number != min)
	{
		tmp = tmp->next;
		moves++;
	}
	moves2 = check_length(a) - moves;
	if (moves <= moves2)
		return (moves);
	else
		return (-moves2);
}
void	stack3_a(t_stack **a, int *s_a)
{
	int 	i;
	t_stack	*tmp_a;

	i = -1;
	tmp_a = (*a);
	while (++i != 3)
	{
		s_a[i] = tmp_a->number;
		tmp_a = tmp_a->next;
		printf("%d, %d\n ",s_a[i], i);
	}
}


void	finish_him(t_parameters *p)
{
	int	move;
	int l_n;
	int	s_a[3];
	int tmp;

	l_n = 2;
	stack3_a(&p->a, s_a);
	if (p->b->number > s_a[0] && p->b->number < s_a[2] && l_n >= 1)
	{
		if (p->b->number > s_a[0] && p->b->number < s_a[1] && l_n == 2)
		{
			rr_stack(&p->a, 'a');
			l_n--;
		}
		rr_stack(&p->a, 'a');
		l_n--;
	}
	else
	{
	   if (p->b->number < s_a[0])
	        l_n = -1;
	   p_stack(&p->b, &p->a, 'a');

	}
	printf("\n\nim out\n\n");
	while (ft_max(&p->b) != p->b->number)
	{
		if ((p->b->number < s_a[l_n]) && l_n != -1)
		{
			rr_stack(&p->a, 'a');
			l_n--;
		}
		else
		{
			p_stack(&p->b, &p->a, 'a');
		}
	print(&p->a, &p->b);
	}
	printf("\n\n\n\nCHANGE\n\n\n\n");
	tmp = ft_last(&p->a);
	if (p->b->number > s_a[0] && p->b->number < s_a[l_n])
	{
		if (p->b->number > s_a[0] && p->b->number < s_a[1] && l_n == 2)
		{
			rr_stack(&p->a, 'a');
			l_n--;
		}
		rr_stack(&p->a, 'a');
		l_n--;
	}
	else
	{
        if (p->b->number < s_a[0])
            p_stack(&p->b, &p->a, 'a');
	}
	while (check_length(&p->a) != p->length)
	{
		if ((p->b->number > s_a[l_n]) && l_n != -1)
		{
			rr_stack(&p->a, 'a');
			l_n--;
		}
		else
		{
		    p_stack(&p->b, &p->a, 'a');
		}
	print(&p->a, &p->b);
	}
	tmp = ft_min(&p->a);
	move = end_search(&p->a, tmp);
	if (move > 0)
	{
		while (--move >= 0)
			r_stack(&p->a, 'a');
	}
	else
	{
		while (++move <= 0)
			rr_stack(&p->a, 'a');
	}
	print(&p->a, &p->b);
	if (check_order(&p->a, p->length) == 0)
	    printf("OK :)\n");
	else
		printf("NOT ok :(\n");
}

void	order(t_parameters *parameters)
{
	t_algoritmia	*algoritmia;
	int				reverse;
	int i = 2;

	reverse = 0;
	algoritmia = malloc(sizeof(t_algoritmia));
	if (!algoritmia)
		ft_error(0);
	while (reverse != 2)
	{
		if (parameters->length_a <= 3 && reverse == 0)
		{
		    reverse = order_3(&parameters->a, ft_min(&parameters->a),
                ft_max(&parameters->a));
            print(&parameters->a, &parameters->b);
		}
		else if (reverse == 1)
		{
		    reverse = 2;
			finish_him(parameters);
		}
		else
		{
			start_algoritmia(algoritmia, parameters);
			fill_position(&parameters->a);
			fill_position(&parameters->b);
			make_position(search_less_position(&parameters->a, &parameters->b,
					algoritmia), algoritmia, parameters);
		}
		//print(&parameters->a, &parameters->b);
		parameters->length_a = check_length(&parameters->a);
		i++;
		printf("en B: %d/%d\n", i, parameters->length);
		printf("supermoves: %d\n", supermoves);
	}
}

void	push_swap(t_parameters *parameters, char **arguments)
{
	int	i = 0;
	t_stack *tmp;

	parameters->split = fill_split(parameters, arguments);
	while (parameters->split[i])
	{
		printf("%s", parameters->split[i++]);
	}
	printf("\n");
	i = 0;
	check_is_number(parameters->split);
	parameters->a = fill_stack(parameters, parameters->split);
	tmp = parameters->a;
	while (tmp)
	{
		printf("%d, ", tmp->number);
		tmp = tmp->next;
	}
	check_duplicate(&(parameters->a));
	parameters->b = NULL;
	parameters->length = check_length(&parameters->a);
	printf("\n%d, ", parameters->length);
	parameters->length_a = check_length(&parameters->a);
	order(parameters);
}

int	main(int nword, char *arguments[])
{
	t_parameters	*parameters;

	parameters = NULL;
	if (nword < 2)
		ft_error(0);
	parameters = ft_init_parameters(parameters);
	push_swap(parameters, arguments);
	free(parameters);
	parameters = NULL;
	printf("supermoves: %d\n", supermoves);
	exit(EXIT_SUCCESS);
	return (0);
}

