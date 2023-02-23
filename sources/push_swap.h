/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmacias- <gmacias-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:42:09 by gmacias-          #+#    #+#             */
/*   Updated: 2022/06/23 14:20:36 by gmacias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include <stdlib.h>
#include <unistd.h>
//# include "../libft/libft.h"

typedef struct s_algoritmia
{
	int		length_b;
	int		last_b;
	int		min_b;
	int		max_b;
	int		moves_b;
	int		less_moves;
	int		position;
}	t_algoritmia;

typedef struct s_stack
{
	int				number;
	int				position;
	struct s_stack	*next;
}	t_stack;

typedef struct s_parameters
{
	char	*line;
	char	**split;
	char	**arguments;
	int		length_a;
	int		length;
	t_stack	*a;
	t_stack	*b;
	t_stack	*perfection;
}	t_parameters;
/*Checkers*/
int		check_length(t_stack **a);
int		check_order(t_stack **a, int length);
void	check_duplicate(t_stack **a);
int		check_atoi(const char *str);
void	check_is_number(char **split);
/*Operaciones ejecutables*/
void	p_stack(t_stack **a, t_stack **b, char c);
void	s_stack(t_stack **top, char c);
void	r_stack(t_stack **stack, char c);
void	r_rboth(t_stack **a, t_stack **b);
void	rr_stack(t_stack **stack, char c);
void	rr_rboth(t_stack **a, t_stack **b);
void	ft_stkadd_front(t_stack **stack, t_stack *new);
void	ft_stkadd_back(t_stack **stack, t_stack *new);
/*Funciones de calculo*/

/*tests*/
int ft_error(int num);
#endif
