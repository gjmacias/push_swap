/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmacias- <gmacias-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:33:00 by gmacias-          #+#    #+#             */
/*   Updated: 2022/05/16 16:35:27 by gmacias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

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
	return (len);
}

int	check_order(t_stack **a, int length)
{
	t_stack	*tmp;

	if (check_length(*a) != length)
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

void	check_duplicate(char **split)
{
	int	i;
	int	j;

	i = -1;
	while (split[++i])
	{
		j = -1;
		while (split[++j])
		{
			if ((j != i) && (ft_strcmp(split[i], split[j]) == 0))
				ft_error(3);
		}
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
		if (num > INT_MAX || num < INT_MIN)
			return (0);
		i++;
	}
	return (42);
}

void	check_is_number(char **split)
{
	int	i;

	if (!split[0])
		ft_error(2);
	i = -1;
	while (split[++i])
	{
		if (check_atoi(split[i]) == 0)
			ft_error(3);
	}
}
