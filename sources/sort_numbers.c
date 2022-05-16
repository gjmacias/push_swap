/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmacias- <gmacias-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:44:48 by gmacias-          #+#    #+#             */
/*   Updated: 2022/05/16 16:52:04 by gmacias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	search_min_max(t_parameters **parameters, t_stack **a)
{
	int		pos;
	t_stack	*tmp;

	pos = 0;
	tmp = (*a);
	(*parameters)->max = (tmp)->number;
	(*parameters)->min = (tmp)->number;
	(*parameters)->length_a = check_length(a);
	while ((tmp) != NULL)
	{
		(tmp)->position = ++pos;
		if ((tmp)->number <= (*parameters)->min)
		{
			(*parameters)->min = (tmp)->number;
			(*parameters)->min_pos = (tmp)->position;
		}
		if ((tmp)->number >= (*parameters)->max)
		{
			(*parameters)->max = (tmp)->number;
			(*parameters)->max_pos = (tmp)->position;
		}
		(tmp) = ((tmp)->next);
	}
}

/*
** ACLARACION: "down" significa que tu estas en la posicion ej: 5 y tienes 
** que ir a la 3. en ese caso tendras que hacer 'rra' para ir abajo del stack.
** "up" significa que tu estas en el 5 y quieres subir al 8, deberas hacer
** 'ra' porque quieres seguir avanzando en el stack.
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
**
** 1 es up y 0 es down, solo que casualmente me ha saslido algo de 'more than
** 25 lines -_-.
*/

int	calculus(t_parameters *parameters, t_stack **a)
{
	int	max[2];
	int	min[2];

	if ((*a)->position > parameters->min_pos)
	{
		min[0] = (*a)->position - parameters->min_pos;
		min[1] = parameters->length_a - min[0];
	}
	else
	{
		min[1] = parameters->min_pos - (*a)->position;
		min[0] = parameters->length_a - min[1];
	}
	if ((*a)->position > parameters->max_pos)
	{
		max[0] = (*a)->position - parameters->max_pos;
		max[1] = parameters->length_a - max[0];
	}
	else
	{
		max[1] = parameters->max_pos - (*a)->position;
		max[0] = parameters->length_a - max[1];
	}
	return (algoritmia(max[1], max[0], min[1], min[0]));
}

void	sort_numbers(t_stack **a, t_stack **b, t_parameters *parameters)
{
	search_min_max(&(parameters), a);
	while (check_order(a, parameters->length) != 0)
	{
		if (!a)
		{
			order(a, b, parameters);
			break ;
		}
		if ((*a)->number == parameters->min || (*a)->number == parameters->max)
		{
			p_stack(a, b);
			if ((*b)->number == parameters->max
				&& (*b)->number != parameters->min)
				r_stack(b);
			if (*a)
				search_min_max(&(parameters), a);
		}
		else
		{
			if (calculus(parameters, a) == 0)
				r_stack(a);
			else
				rr_stack(a);
		}
	}
}
