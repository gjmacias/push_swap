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
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
//# include "../libft/libft.h"

typedef struct s_algoritmia
{
	int		last_b;
	int		min_b;
	int		max_b;
	int		moves_b_ra;
	int		moves_b_rra;
	int		moves_a_ra;
	int		moves_a_rra;
	int		moves_a;
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
int				check_length(t_stack **a);
int				check_order(t_stack **a, int length);
void			check_duplicate(t_stack **a);
int				check_atoi(const char *str);
void			check_is_number(char **split);
/*Llenado de infomacion*/
t_stack			*fill_stack(t_parameters *parameters, char **split);
char			**fill_split(t_parameters *parameters, char **arguments);
void			fill_position(t_stack **a);
/*Operaciones ejecutables*/
void			p_stack(t_stack **a, t_stack **b, char c);
void			s_stack(t_stack **top, char c);
void			r_stack(t_stack **stack, char c);
void			r_rboth(t_stack **a, t_stack **b);
void			rr_stack(t_stack **stack, char c);
void			rr_rboth(t_stack **a, t_stack **b);
void			ft_stkadd_front(t_stack **stack, t_stack *new);
void			ft_stkadd_back(t_stack **stack, t_stack *new);
/*Ordenación*/
int				search_less_moves(t_algoritmia *alg, t_stack **a, t_stack **b);
int				search_less_pos(t_stack **a, t_stack **b, t_algoritmia *al);
void			make_position(int pos, t_algoritmia *alg, t_parameters *param);
int				order_3(t_stack **a, int min, int max);
void			order(t_parameters *parameters);
/*Utiles de algoritmia*/
int				ft_min(t_stack **b);
int				ft_min_array(int *array);
int				ft_max(t_stack **b);
int				ft_max_int(int a, int b);
int				ft_last(t_stack **b);
/*Programa*/
void			start_algoritmia(t_algoritmia *algoritmia, t_parameters *p);
void			push_swap(t_parameters *parameters, char **arguments);
t_parameters	*ft_init_parameters(t_parameters *parameters);
/*reordenacion final*/
void			finish_him(t_parameters *param, int tmp);
/*Funciones utiles*/
int				ft_error(int num);
int				ft_sign(char *str);
int				ft_atoi(const char *str);
#endif
