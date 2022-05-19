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

t_stack	*fill_stack(t_parameters *parameters, char **split)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	while (split[i])
	{
		tmp = malloc(sizeof(t_stack));
		if (tmp == NULL)
			ft_error(2);
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

void	push_swap(t_parameters *parameters, char **arguments)
{
	parameters->split = fill_split(parameters, arguments);
	check_is_number(parameters->split);
	parameters->a = fill_stack(parameters, parameters->split);
	check_duplicate(&(parameters->a));
	parameters->b = NULL;
	parameters->length = check_length(&parameters->a);
	parameters->length_a = check_length(&parameters->a);
	sort_numbers(&(parameters->a), &(parameters->b), parameters);
}

t_parameters	*ft_init_parameters(t_parameters *parameters)
{
	parameters = (t_parameters *)malloc(sizeof(t_parameters));
	if (parameters == NULL)
		ft_error(1);
	parameters->a = NULL;
	parameters->b = NULL;
	parameters->line = NULL;
	parameters->split = NULL;
	parameters->length = 0;
	parameters->print = 0;
	return (parameters);
}

int	main(int nword, char *arguments[])
{
	t_parameters	*parameters;

	parameters = NULL;
	if (nword < 2)
		ft_error(2);
	parameters = ft_init_parameters(parameters);
	push_swap(parameters, arguments);
	free(parameters);
	parameters = NULL;
	exit(EXIT_SUCCESS);
}
