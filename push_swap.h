#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_stack
{
	int			number;
	int			position;
	struct s_stack	*next;
}	t_stack;

typedef struct s_parameters
{
	char	*line;
	char	**split;
	char	**arguments;
	int		length_a;
	int		length;
	int		min;
	int		max;
	int		min_pos;
	int		max_pos;
	int		print;
	int		color;
	t_stack	*a;
	t_stack	*b;
}	t_parameters;

/*Operaciones ejecutables*/

/*Funciones auxiliares*/

#endif
