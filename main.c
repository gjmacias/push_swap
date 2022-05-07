# include "push_swap.h"

char	**fill_split(t_var *parameters, int nword, char **arguments)
{
	if (nword == 2)
		parameters->split = ft_split(arguments[1], ' ');
	else
		parameters->split = &arguments[1];
	return [parameters->split];
}

void	push_swap(t_var *parameters, int nword, char***arguments)
{
	t_stack	*stack;
	
	stack = NULL;
	parameters->split = fill_split(parameters, nword, arguments);
	check_duplicate(parameters->split);
	check_is_number(parameters->split);
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
