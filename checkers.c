#include "push_swap.h"

void	check_duplicate(char **split)
{
	int	i;
	int	j;
	
	i = -1;
	while(split[++i])
	{
		j = -1;
		while (split[++j])
		{
			if ((j != i) && (ft_strcmp(split[i], split[j]) == 0))
				exit(EXIT_FAILURE);
		}
	}
}

void check_is_number(char **split)
{
	int	i;

	if (!split[0])
		exit (EXIT_FAILURE);
	i = -1;
	while(split[++i])
	{
		if ()
		if (split[i] != "0" && ft_atoi(split[i]) == 0)
			exit(EXIT_FAILURE);
	}	
}
