/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmacias- <gmacias-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:33:00 by gmacias-          #+#    #+#             */
/*   Updated: 2022/05/19 17:28:19 by gmacias-         ###   ########.fr       */
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
	tmp = NULL;
	return (len);
}

int	check_order(t_stack **a, int length)
{
	t_stack	*tmp;

	if (check_length(a) != length)
		return (1);
	tmp = *a;
	while (tmp && tmp->next)
	{
		if (tmp->number < tmp->next->number)
			tmp = tmp->next;
		else
			return (1);
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
	if (*str == '+' || *str == '-')
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
		return (0);
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
