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
	char	*lime;
	char	**split;
	char	**arguments;
	int		nword;
	int		length;
	int		print;
	int		color;
	int		fd;
	t_stk	*a;
	t_stk	*b;
}

/*Operaciones ejecutables*/

/*Funciones auxiliares*/

#endif
