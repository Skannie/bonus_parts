/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kannie <kannie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:14:17 by kannie            #+#    #+#             */
/*   Updated: 2022/06/29 15:00:13 by kannie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*swap_s(t_stack *stk)
{
	int	s;

	if (!stk)
		return (stk);
	s = stk->data;
	stk->data = stk->next->data;
	stk->next->data = s;
	return (stk);
}

void	double_swap_s(t_stack **stk_a, t_stack **stk_b)
{
	*stk_a = swap_s(*stk_a);
	*stk_b = swap_s(*stk_b);
	write(1, "ss\n", 3);
}

t_stack	*print_s_swap(t_stack *stk, char a)
{
	write(1, "s", 1);
	write(1, &a, 1);
	write(1, "\n", 1);
	return (swap_s(stk));
}

void	push_p(t_stack **stk_a, t_stack **stk_b)
{
	t_stack	*stk;

	if (!stk_a)
		return ;
	stk = (*stk_a)->next;
	(*stk_a)->next = (*stk_b);
	(*stk_b) = stk;
	stk = *stk_a;
	*stk_a = *stk_b;
	*stk_b = stk;
}

void	print_p_push(t_stack **stk_a, t_stack **stk_b, char a)
{
	push_p(stk_a, stk_b);
	write(1, "p", 1);
	write(1, &a, 1);
	write(1, "\n", 1);
}
