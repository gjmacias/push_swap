#include "push_swap.h"
#include <stdio.h>

int ft_error(int num)
{
	printf("soy error :)");
    exit(0);
    return (num);
}

void	finish_him(t_parameters *param)
{
	param = NULL;
	exit(1);
}

int	ft_sign(char *str)
{
	int	i;
	int	sign;

	sign = 1;
	i = 0;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	return (sign);
}

int	ft_atoi(const char *str)
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
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		if ((num * sign) > INT_MAX || (num * sign) < INT_MIN)
			return (0);
		i++;
	}
	return ((int)num * sign);
}
















void print(t_stack **a, t_stack **b)
{
	t_stack *tmp;

	tmp = (*a);
	printf("Stack a: ");
	while (tmp)
	{
    	printf("%d, ", tmp->number);
		tmp = tmp->next;
    }
	printf("\n");
    tmp = (*b);
	printf("Stack b: ");
    while (tmp)
	{
    	printf("%d, ", tmp->number);
		tmp = tmp->next;
    }
		printf("\n");
}






void	order(t_parameters *parameters)
{
	t_algoritmia	*algoritmia;
	int				reverse;

	reverse = 0;
	algoritmia = malloc(sizeof(t_algoritmia));
	if (!algoritmia)
		ft_error(0);
	while (reverse != 6)
	{
		if (parameters->length <= 3)
			reverse = order_3(&parameters->a, ft_min(&parameters->a),
					ft_max(&parameters->a));
		else if (reverse == 11)
			finish_him(parameters);
		else
		{
			start_algoritmia(algoritmia, parameters);
			fill_position(&parameters->a);
			fill_position(&parameters->b);
			make_position(search_less_position(&parameters->a, &parameters->b,
					algoritmia), algoritmia, parameters);
			print(&parameters->a, &parameters->b);
		}
		reverse++;
	}
}








void	push_swap(t_parameters *parameters, char **arguments)
{
	int	i = 0;
	t_stack *tmp;

	parameters->split = fill_split(parameters, arguments);
	while (parameters->split[i])
	{
		printf("%s", parameters->split[i++]);
	}
	printf("\n");
	i = 0;
	check_is_number(parameters->split);
	parameters->a = fill_stack(parameters, parameters->split);
	tmp = parameters->a;
	while (tmp)
	{
		printf("%d, ", tmp->number);
		tmp = tmp->next;
	}
	check_duplicate(&(parameters->a));
	parameters->b = NULL;
	parameters->length = check_length(&parameters->a);
	printf("\n%d, ", parameters->length);
	parameters->length_a = check_length(&parameters->a);
	order(parameters);
}

int	main(int nword, char *arguments[])
{
	t_parameters	*parameters;

	parameters = NULL;
	if (nword < 2)
		ft_error(0);
	parameters = ft_init_parameters(parameters);
	push_swap(parameters, arguments);

	free(parameters);
	parameters = NULL;
	exit(EXIT_SUCCESS);
}