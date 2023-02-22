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
# include "../libft/libft.h"

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
/*Funciones de calculo*/
void	search_min_max(t_parameters **parameters, t_stack **a);
int		algoritmia(int max_up, int max_down, int min_up, int min_down);
int		calculus(t_parameters *parameters, t_stack **a);
void	order(t_stack **a, t_stack **b, t_parameters *parameters);
void	sort_numbers(t_stack **a, t_stack **b, t_parameters *parameters);
/*Operaciones de stack*/
void	ft_stkadd_front(t_stack **stack, t_stack *new);
void	ft_stkadd_back(t_stack **stack, t_stack *new);
#endif
