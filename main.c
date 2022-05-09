# include "push_swap.h"

t_stack	*fill_stack(t_var *parameters, char **split)
{
	int	i;
	t_stack	*tmp;
	
	i = 0;
	while (split[i])
	{
		tmp = malloc(sizeof(t_stack));
		if (tmp == NULL)
			return (NULL);
		tmp->number = ft_atoi(split[i++]);
		tmp->next = NULL;
		tmp->previous = NULL;
		add_back(&v->a, temp);
		tmp = NULL;
	}
	free(tmp);
	return (v->a);
}

char	**fill_split(t_var *parameters, int nword, char **arguments)
{
	if (nword == 2)
		parameters->split = ft_split(arguments[1], ' ');
	else
		parameters->split = &arguments[1];
	return [parameters->split];
}

void	push_swap(t_parameters *parameters, int nword, char **arguments)
{
	parameters->split = fill_split(parameters, nword, arguments);
	check_duplicate(parameters->split);
	check_is_number(parameters->split);
	parameters->a = fill_stack(parameters, parameters->split);
	parameters->b = NULL;
	parameters->length = check_length(parameters->a);
	sort_numbers(&(parameters->a), &(parameters->b), parameters);
}

t_parameters	*ft_init_parameters(t_parameters *parameters)
{
	parameters = (t_parameters *)malloc(sizeof( t_parameters));
	if (parameters == NULL)
		exit(EXIT_FAILURE);
	parameters->a = NULL;
	parameters->b = NULL;
	parameters->line = NULL;
	parameters->split = NULL;
	parameters->lenght = 0;
	parameters->print = 0;
	return (parameters);
}

int main(int nword, char *arguments[])
{
	t_parameters	*parameters;
	
	parameters = NULL;
	if  (nword < 2)
		exit(EXIT_FAILURE);
	parameters = ft_init_parameters(parameters);
	if(!ft_strcmp(arguments[1], "-h"))
		h_for_help();
	else
		push_swap(parameters, nword, arguments);
	free(parameters);
	parameters = NULL;	
	return (0);
}
