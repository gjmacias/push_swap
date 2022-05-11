#include "push_swap.h"

void	search_min_max(t_parameters **parameters, t_stack **a)
{
	int	pos;

	pos = 0;
	*parameters->max = *a->number;
	*parameters->min = *a->number;
	*parameters->length_a = check_length(a);
	while (*a)
	{
		*a->position = ++pos;
		if (*a->number <= *parameters->min)
		{
			*parameters->min = *a->number;
			*parameters->min_pos = *a->position;
		}
		if (*a->number >= *parameters->max)
		{
			*parameters->max = *a->number;
			*parameters->max_pos = *a->position;
		}
		*a = (*a->next);
	}
}

/*
** ACLARACION: "down" significa que tu estas en la posicion ej: 5 y tienes 
** que ir a la 3. en ese caso tendras que hacer 'rra' para ir abajo del stack.
** "up" significa que tu estas en el 5 y quieres subir al 8, deberas hacer
**  'ra' porque quieres seguir avanzando en el stack.
*/

int	algoritmia(int max_up, int max_down, int min_up, int min_down)
{
	int	tmp_up;
	int	tmp_down;
	
	if (max_up > min_up)
		tmp_up = min_up;
	else
		tmp_up = max_up;
	if (max_down > min_down)
		tmp_down = min_down;
	else
		tmp_down = max_down;
	if (tmp_up > tmp_down)
		return (42);
	return (0);
}

/*
** Esto es complicado de entender pero la formula que he utilizado ha sido
** ver si el numero que busco es mayor o menor en el que estoy, con eso sé
** si subir o bajar PERO, tambien tengo que ver si dando la vuelta al stack
** es más rápido, de ahi el "lenght_a - el paso" (piensa en el mundo y si
** buscar es más rápido por la izquierda o derecha). Repetirlo para el max
** y ver si es más rápido buscar el minimo o el máximo y luego si es por
** arriba o por abajo.
*/

int	calculus(t_parameters *parameters, t_stack **a)
{
	int	max_up;
	int	max_down;
	int	min_up;
	int	min_down;
	
	if (*a->poisition > parametrs->min_pos)
	{
		min_down = *a->poisition - parametrs->min_pos;
		min_up = parameters->length_a - min_down;
	}
	else
	{
		min_up = parametrs->min_pos - *a->poisition;
		min_down = parameters->length_a - min_up;
	}
	if (*a->poisition > parametrs->max_pos)
	{
		max_down = *a->poisition - parametrs->max_pos;
		max_up = parameters->length_a - max_down;
	}
	else
	{
		max_up = parametrs->max_pos - *a->poisition;
		max_down = parameters->length_a - max_up;
	}
	return (algoritmia(max_up, max_down, min_up, min_down));
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
		{
			if (calculus(parameters, a) == 0)
				ra(a);
			else 
				rra(a);
		}
	}
}
