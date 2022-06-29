/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kannie <kannie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 20:38:02 by kannie            #+#    #+#             */
/*   Updated: 2022/06/29 14:44:56 by kannie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}	t_stack;

int			main(int argc, char **argv);
t_stack		*init_stack(int nbr, char **sstr, int flag);
void		delete_stack(t_stack *stk);
void		check_double(t_stack *stk);
t_stack		*go_last(t_stack *stk);
t_stack		*go_prelast(t_stack *stk);
void		write_error(void);
t_stack		*swap_s(t_stack *sta);
void		double_swap_s(t_stack **stk_a, t_stack **stk_b);
t_stack		*print_s_swap(t_stack *stk, char a);
void		push_p(t_stack **stk_a, t_stack **stk_b);
void		print_p_push(t_stack **stk_a, t_stack **stk_b, char a);
t_stack		*rotate_r(t_stack *stk);
t_stack		*print_rotate_r(t_stack *stk, char a);
void		double_rotate_r(t_stack **stk_a, t_stack **stk_b);
t_stack		*rev_rotate_rr(t_stack *stk);
t_stack		*print_rev_rot_rr(t_stack *stk, char a);
void		double_rev_rot_rr(t_stack **stk_a, t_stack **stk_b);
int			is_sorted(t_stack *a);
t_stack		*sorting(t_stack *stk_a, t_stack *stk_b);
t_stack		*sort_2elem(t_stack *stk);
t_stack		*sort_3elem(t_stack *stk);
void		sorting_1(t_stack **a, t_stack **b, t_stack *best);
t_stack		*f_min(t_stack *stk_a);
t_stack		*f_pos(t_stack *stk, int nbr);
int			to_the_top(t_stack *stk, int nbr);
t_stack		*sort_2elem(t_stack *stk);
int			to_the_down(t_stack *stk, int nbr);
t_stack		*f_best(t_stack *a, t_stack *b);
int			step(t_stack *a, t_stack *b, int data);
int			min(int a, int b);
int			max(int a, int b);
void		top(t_stack **a, t_stack **b, int a_top, int b_top);
void		down(t_stack **a, t_stack **b, int a_down, int b_down);
void		there_b(t_stack **a, t_stack **b, int top, int down);
void		back_th(t_stack **a, t_stack **b, int down, int top);
int			ft_atoi(const char *str);
int			schar_v_int(const char *strok, int i, int minus);

#endif //PUSH_SWAP