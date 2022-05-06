#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft.h"

typedef struct	s_stk
{
	int	num;
	struct s_stk	*next;
	struct s_stk	*previous;
}	t_stk;

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
