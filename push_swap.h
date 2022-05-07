#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft.h"

typedef struct	s_stack
{
	int	num;
	struct s_stack	*next;
	struct s_stack	*previous;
}	t_stack;

typedef struct	s_parameters;
{
	char	*line;
	char	**split;
	char	**arguments;
	int		nword;
	int		length;
	int		print;
	int		color;
	t_stack	*a;
	t_stack	*b;
}

/*Operaciones ejecutables*/

/*Funciones auxiliares*/

#endif
