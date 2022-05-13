#include "push_swap.h"

int	check_length(t_stack **a)
{
	int	len;
	t_stack *tmp;

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
				exit(EXIT_FAILURE);
		}
	}
}

void	check_is_number(char **split)
{
	int	i;

	if (!split[0])
		exit (EXIT_FAILURE);
	i = -1;
	while (split[++i])
	{
		if (split[i] != "0" && ft_atoi(split[i]) == 0)
			exit(EXIT_FAILURE);
		if (hacer funcion igual a atoi para long )
			exit(EXIT_FAILURE);
	}
}
