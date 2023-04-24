/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmacias- <gmacias-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:35:34 by gmacias-          #+#    #+#             */
/*   Updated: 2022/05/19 17:45:58 by gmacias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(int num)
{
	num = -1;
	write(2, "Error\n", 6);
	exit(num);
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
	if ((num * sign) == INT_MIN)
		return (INT_MIN);
	return ((int)num * sign);
}
