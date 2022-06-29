/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kannie <kannie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 22:50:27 by kannie            #+#    #+#             */
/*   Updated: 2022/03/25 22:52:16 by kannie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*f_best(t_stack *a, t_stack *b)
{
	t_stack	*res;
	t_stack	*stk;

	stk = b;
	res = b;
	while (stk)
	{
		if (step(a, b, stk->data) < step(a, b, res->data))
			res = stk;
		stk = stk->next;
	}
	return (res);
}

int	step(t_stack *a, t_stack *b, int data)
{
	t_stack	*pos;
	int		a_top;
	int		a_down;
	int		b_top;
	int		b_down;

	pos = f_pos(a, data);
	a_top = to_the_top(a, pos->data);
	a_down = to_the_down(a, pos->data);
	b_top = to_the_top(b, data);
	b_down = to_the_down(b, data);
	return (min(min(max(b_down, a_down), max(a_top, b_top)),
			min(a_down + b_top, a_top + b_down)));
}

int	min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

int	max(int a, int b)
{
	if (a < b)
		return (b);
	return (a);
}
