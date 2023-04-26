/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmacias- <gmacias-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:35:34 by gmacias-          #+#    #+#             */
/*   Updated: 2022/05/19 17:45:58 by gmacias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	fill_position(&p->a);
	fill_position(&p->b);
	search_less_pos(&p->a, &p->b, algoritmia);
	make_position(algoritmia, p);
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
		return (0);
	parameters = ft_init_parameters(parameters);
	push_swap(parameters, arguments);
	free_stack(&parameters->a);
	free(parameters);
	parameters = NULL;
	exit(EXIT_SUCCESS);
}
