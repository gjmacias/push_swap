/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmacias- <gmacias-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:36:19 by gmacias-          #+#    #+#             */
/*   Updated: 2022/05/16 16:41:30 by gmacias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/*
** 		¡¡¡EXPLICACIÓN PRINCIPAL EN "libft/ft_lstadd_back.c" !!!
** 
** Espero que lo leas o entiendas bien los punteros "tmp" y por qué son 
** importantes, en estos casos es igual de útil.
**
**
** En "r_stack" guardamos el primer puntero en "tmp", saltamos al siguiente y al
** puntero "tmp" le quitamos la lista para que solo apunte a 1 valor y no a los
** demás.
** EL ORDEN ES IMPORTANTE!! ya que si primero le hacemos el "NULL" cuando la
** lista "stack" quiera pasar al siguiente no podra por que antes le has 
** guardado "NULL" e ira a NULL.
*/

void	r_stack(t_stack **stack)
{
	t_stack	*tmp;

	tmp = (*stack);
	(*stack) = (*stack)->next;
	tmp->next = NULL;
	add_back(stack, tmp);
}

void	r_rboth(t_stack **a, t_stack **b)
{
	r_stack(a);
	r_stack(b);
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

void	rr_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*stack_tmp;

	stack_tmp = (*stack);
	while (stack_tmp->next->next)
		stack_tmp = stack_tmp->next;
	tmp = stack_tmp->next;
	stack_tmp->next = NULL;
	add_front(stack, tmp);
}

void	rr_rboth(t_stack **a, t_stack **b)
{
	rr_stack(a);
	rr_stack(b);
}
