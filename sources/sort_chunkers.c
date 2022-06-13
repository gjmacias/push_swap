/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunkers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmacias- <gmacias-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:44:48 by gmacias-          #+#    #+#             */
/*   Updated: 2022/06/07 16:18:35 by gmacias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_chunk(t_parameters *parameters, t_stack **a)
{
	t_stack	*tmp;
	int		is;
	
	is = false;
	tmp = (*a);
	while (tmp)
	{
		if (parameters->my_chunk == (*a)->chunker)
			is = true;
		tmp = tmp->next;
	}
	return (is);	
}

/*
** i[0] = down		el mas cercano bajando
** i[1] = position	posicion del stack
** i[2] = block		bloquear el cercano
** i[3] = up		el mas cercano subiendo
**
** ACLARACION: "down" significa que tu estas en la posicion ej: 5 y tienes 
** que ir a la 3. en ese caso tendras que hacer 'rra' para ir abajo del stack.
** "up" significa que tu estas en el 5 y quieres subir al 8, deberas hacer
** 'ra' porque quieres seguir avanzando en el stack.
*/

void	search_up_down(t_parameters *parameters, t_stack **a)
{
	int		i[4];
	t_stack	*tmp;

	i[1] = 0;
	i[2] = false;
	tmp = (*a);
	while ((tmp) != NULL)
	{
		i[1]++;
 		if (parameters->my_chunk == (*a)->chunker)
		{
			if (i[2] == false)
			{
				i[3] = i[1];
				i[2] = true;
			}
			i[0] = i[1];
		}
		(tmp) = ((tmp)->next);
	}
	if ((i[1] - i[0]) <= i[3])
		rr_stack(a, 'a');
	else
		r_stack(a, 'a');
}

void	chunker_on_stack(t_stack **a, t_stack **b, t_parameters *parameters)
{
	while (check_chunk == true)
	{
		if ((*a)->chunker == parameters->my_chunk)
			p_stack(a, b, 'b');
		else
			search_up_down(parameters, a);
	}
}

void	sort_chunkers(t_stack **a, t_stack **b, t_parameters *parameters)
{
	int	next_chunk;

	next_chunk = false;
	while (parameters->my_chunk++ != max_chunk)
	{
		chunker_on_stack(a, b, parameters);
		while (next_chunk != true)
		{
			if (check_chunk == false)
			{
				order(b, a, parameters);
				next_chunk = true;
			}
			if ((*b)->number == parameters->min || (*b)->number == parameters->max)
			{
				p_stack(b, a, 'b');
				if ((*a)->number == parameters->max
					&& parameters->length != parameters->length_a)
					r_stack(a, 'a');
				search_min_max(&(parameters), b);
			}
			else
			{/*
				if (calculus(parameters, a) == 0)
					r_stack(a, 'a');
				else
					rr_stack(a, 'a');
			
			todo esto se puede quitar y que lo haga la funcion que le pertoque*/
			
			}
		}
		next_chunk = false;
	}
}
