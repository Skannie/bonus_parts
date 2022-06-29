/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kannie <kannie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 22:52:56 by kannie            #+#    #+#             */
/*   Updated: 2022/06/29 15:00:34 by kannie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	top(t_stack **a, t_stack **b, int a_top, int b_top)
{
	while (a_top && b_top)
	{
		double_rotate_r(a, b);
		a_top--;
		b_top--;
	}
	while (a_top)
	{
		*a = print_rotate_r(*a, 'a');
		a_top--;
	}
	while (b_top)
	{
		*b = print_rotate_r(*b, 'b');
		b_top--;
	}
	print_p_push(b, a, 'a');
}

void	down(t_stack **a, t_stack **b, int a_down, int b_down)
{
	while (a_down && b_down)
	{
		double_rev_rot_rr(a, b);
		a_down--;
		b_down--;
	}
	while (a_down)
	{
		*a = print_rev_rot_rr(*a, 'a');
		a_down--;
	}
	while (b_down)
	{
		*b = print_rev_rot_rr(*b, 'b');
		b_down--;
	}
	print_p_push(b, a, 'a');
}

void	there_b(t_stack **a, t_stack **b, int top, int down)
{
	while (top--)
		*a = print_rotate_r(*a, 'a');
	while (down--)
		*b = print_rev_rot_rr(*b, 'b');
	print_p_push(b, a, 'a');
}

void	back_th(t_stack **a, t_stack **b, int down, int top)
{
	while (top--)
		*b = print_rotate_r(*b, 'b');
	while (down--)
		*a = print_rev_rot_rr(*a, 'a');
	print_p_push(b, a, 'a');
}

void	check_double(t_stack *stk)
{
	t_stack	*hstk;

	while (stk)
	{
		hstk = stk->next;
		while (hstk)
		{
			if (hstk->data == stk->data)
				write_error();
			hstk = hstk->next;
		}
		stk = stk->next;
	}
}
