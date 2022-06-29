/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kannie <kannie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 19:33:43 by kannie            #+#    #+#             */
/*   Updated: 2022/06/29 15:00:16 by kannie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*rotate_r(t_stack *stk)
{
	t_stack	*rh1;
	t_stack	*rh2;

	if (!stk || !stk->next)
		return (stk);
	rh1 = stk;
	stk = stk->next;
	rh2 = go_last(stk);
	rh2->next = rh1;
	rh1->next = NULL;
	return (stk);
}

t_stack	*print_rotate_r(t_stack *stk, char a)
{
	write(1, "r", 1);
	write(1, &a, 1);
	write(1, "\n", 1);
	return (rotate_r(stk));
}

void	double_rotate_r(t_stack **stk_a, t_stack **stk_b)
{
	*stk_a = rotate_r(*stk_a);
	*stk_b = rotate_r(*stk_b);
	write(1, "rr\n", 3);
}
