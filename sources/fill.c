
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
			ft_error(0);
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
