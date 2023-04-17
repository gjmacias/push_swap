
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
int				check_length(t_stack **a);
int				check_order(t_stack **a, int length);
void			check_duplicate(t_stack **a);
int				check_atoi(const char *str);
void			check_is_number(char **split);
/*Llenado de infomacion*/
t_stack			*fill_stack(t_parameters *parameters, char **split);
char			**fill_split(t_parameters *parameters, char **arguments);
void			fill_position(t_stack **a);
/*Operaciones ejecutables*/
void			p_stack(t_stack **a, t_stack **b, char c);
void			s_stack(t_stack **top, char c);
void			r_stack(t_stack **stack, char c);
void			r_rboth(t_stack **a, t_stack **b);
void			rr_stack(t_stack **stack, char c);
void			rr_rboth(t_stack **a, t_stack **b);
void			ft_stkadd_front(t_stack **stack, t_stack *new);
void			ft_stkadd_back(t_stack **stack, t_stack *new);
/*Ordenación*/
int				search_less_moves(t_algoritmia *alg, t_stack **a, t_stack **b);
void			search_less_pos(t_stack **a, t_stack **b, t_algoritmia *al);
int				order_3(t_stack **a, int min, int max);
void			order(t_parameters *parameters);
/*Posicionamiento*/
void			make_position(t_algoritmia *alg, t_parameters *param);
void			make_pos_together(t_algoritmia *alg, t_parameters *param);
/*Utiles de algoritmia*/
int				ft_min(t_stack **b);
int				ft_min_array(int *array);
int				ft_max(t_stack **b);
int				ft_max_int(int a, int b);
int				ft_last(t_stack **b);
/*Programa*/
void			start_algoritmia(t_algoritmia *algoritmia, t_parameters *p);
void			push_swap(t_parameters *parameters, char **arguments);
t_parameters	*ft_init_parameters(t_parameters *parameters);
/*reordenacion final*/
void			finish_him(t_parameters *param);
/*Funciones utiles*/
int				ft_error(int num);
int				ft_atoi(const char *str);


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
	long long int	num;

	sign = 1;
	num = 0;
	while ((*str >= 9 && *str <= 12) || *str == ' ')
		str++;

	while (*str == '+' || *str == '-')
	{
		if (*str++ == '-')
			sign = -sign;
		str++;
	}
	while (*str)
	{
		if (*str <= '9' && *str >= '0')
			num = (num * 10) + (*str++ - '0');
		else
			return (0);
	}
	if (((sign * num) > INT_MAX || (sign * num) < INT_MIN))
		return 0;
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

int	ft_error(int num)
{
	write(1, "soy error :)\n", 11);
	exit(0);
	return (num);
}

int	ft_atoi(const char *str)
{
	int				sign;
	long long int	num;

	sign = 1;
	num = 0;
	while ((*str >= 9 && *str <= 12) || *str == ' ')
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str++ == '-')
			sign = -sign;
	}
	while (*str)
	{
		if (((num * sign) <= INT_MAX && (num * sign) >= INT_MIN)
			&& (*str >= '0' && *str <= '9'))
			num = (num * 10) + (*str++ - '0');
		else
			return (0);
	}
	return ((int)num * sign);
}

void	move_pos_a(t_algoritmia *alg, t_parameters *param)
{
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
}

void	move_pos_b(t_algoritmia *alg, t_parameters *param)
{
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
}

void	move_pos_together(t_algoritmia *alg, t_parameters *param)
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
}

void	make_position(t_algoritmia *alg, t_parameters *param)
{
	if ((param->b) == NULL)
	{
		p_stack(&param->a, &param->b, 'b');
		return ;
	}
	move_pos_together(alg, param);
	move_pos_a(alg, param);
	move_pos_b(alg, param);
	p_stack(&param->a, &param->b, 'b');
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
	else if (c == 'b')
		write(1, "rb\n", 3);
}

void	r_rboth(t_stack **a, t_stack **b)
{
	r_stack(a, ' ');
	r_stack(b, ' ');
	write(1, "rr\n", 3);
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
}

void	rr_rboth(t_stack **a, t_stack **b)
{
	rr_stack(a, ' ');
	rr_stack(b, ' ');
	write(1, "rrr\n", 4);
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
	else if (c == 'b')
		write(1, "pb\n", 3);
	free(tmp);
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
	else if (c == 'b')
		write(1, "sb\n", 3);
}

void	ss_stack(t_stack **a, t_stack **b)
{
	s_stack(a, ' ');
	s_stack(b, ' ');
	write(1, "ss\n", 3);
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

void	reorder(t_stack **a, int min, char c)
{
	int	move;
 
	move = end_search(a, min);
	if (move > 0)
	{
		while (--move >= 0)
			r_stack(a, c);
	}
	else
	{
		while (++move <= 0)
			rr_stack(a, c);
	}
}


void	finish_him(t_parameters *p)
{
	int tmp;
	int	move;

	reorder(&p->b, ft_max(&p->b), 'b');
	tmp = ft_last(&p->a);
	move = p->b->number;
	if (tmp > move)
		rr_stack(&p->a, 'a');
	else
		p_stack(&p->b, &p->a, 'a');
	tmp = ft_last(&p->a);
	move = ft_max(&p->a);
	while (check_length(&p->a) != p->length)
	{
		print(&p->a, &p->b);
		if (tmp > p->b->number && tmp != move)
		{
			rr_stack(&p->a, 'a');
			tmp = ft_last(&p->a);
		}
		else
			p_stack(&p->b, &p->a, 'a');
	}
	reorder(&p->a, ft_min(&p->a), 'a');
}

int	search_less_moves(t_algoritmia *alg, t_stack **a, t_stack **b)
{
	int	option[4];
	int	result;

	alg->moves_a_rra = check_length(a) - alg->moves_a_ra + 2;
	alg->moves_b_rra = check_length(b) - alg->moves_b_ra;
	option[0] = ft_max_int(alg->moves_a_ra, alg->moves_b_ra);
	option[1] = ft_max_int(alg->moves_a_rra, alg->moves_b_rra);
	option[2] = alg->moves_a_ra + alg->moves_b_rra;
	option[3] = alg->moves_a_rra + alg->moves_b_ra;
	result = ft_min_array(option);
	if (result < alg->less_moves)
	{
		if (result == option[0] || result == option[2])
			alg->moves_a = alg->moves_a_ra;
		else
			alg->moves_a = -(alg->moves_a_rra);
		if (result == option[0] || result == option[3])
			alg->moves_b = alg->moves_b_ra;
		else
			alg->moves_b = -(alg->moves_b_rra);
		alg->less_moves = result;
	}
	alg->last_b = ft_last(b);
	return (alg->less_moves);
}

int	condition_of_slp(t_stack **tmp0, t_stack **tmp1, t_algoritmia *al)
{
	t_stack	*tmp[2];
	int		result1;
	int		result2;
	int		result;

	tmp[0] = (*tmp0);
	tmp[1] = (*tmp1);
	result1 = ((tmp[0]->number > al->max_b || tmp[0]->number < al->min_b)
			&& (tmp[1]->number != al->max_b));
	result2 = (!(tmp[0]->number > al->max_b || tmp[0]->number < al->min_b)
			&& !(tmp[0]->number > tmp[1]->number
				&& tmp[0]->number < al->last_b));
	result = (result1 || result2);
	return (result);
}

void	search_less_pos(t_stack **a, t_stack **b, t_algoritmia *al)
{
	t_stack	*tmp[2];
	int		moves;

	tmp[0] = (*a);
	while (tmp[0])
	{
		tmp[1] = (*b);
		moves = 0;
		while (condition_of_slp(&tmp[0], &tmp[1], al))
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
	if (check_length(a) == 2)
	{
		if ((*a)->number > tmp->number)
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

void	order(t_parameters *p)
{
	t_algoritmia	*a;

	a = malloc(sizeof(t_algoritmia));
	if (!a)
		ft_error(0);
	while (check_order(&p->a, p->length))
	{
		print(&p->a, &p->b);
		if (p->length_a <= 3)
		{
			order_3(&p->a, ft_min(&p->a), ft_max(&p->a));
			if (check_length(&p->a) == p->length)
				reorder(&p->a, ft_min(&p->a), 'a');
			else
				finish_him(p);
		}
		else if (!(p->b))
			p_stack(&p->a, &p->b, 'b');
		else
		{
			start_algoritmia(a, p);
			fill_position(&p->a);
			fill_position(&p->b);
			search_less_pos(&p->a, &p->b, a);
			make_position(a, p);
		}
		p->length_a = check_length(&p->a);
	}
}

void	start_algoritmia(t_algoritmia *algoritmia, t_parameters *p)
{
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


