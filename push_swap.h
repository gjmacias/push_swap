#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft.h"

typedef struct	s_stack
{
	int	number;
	struct s_stack	*next;
}	t_stack;

typedef struct	s_parameters
{
	char	*line;
	char	**split;
	char	**arguments;
	int		nword;
	int		length;
	int		min;
	int		max;
	int		print;
	int		color;
	t_stack	*a;
	t_stack	*b;
}	t_parameters;

/*Operaciones ejecutables*/

/*Funciones auxiliares*/

#endif
