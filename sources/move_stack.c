/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmacias- <gmacias-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:01:21 by gmacias-          #+#    #+#             */
/*   Updated: 2022/05/19 18:19:08 by gmacias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

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
