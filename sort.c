/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kannie <kannie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 20:23:49 by kannie            #+#    #+#             */
/*   Updated: 2022/04/01 18:19:45 by kannie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *a)
{
	while (a->next)
	{
		if (a->data > a->next->data)
			return (0);
		a = a->next;
	}
	return (1);
}

t_stack	*sorting(t_stack *stk_a, t_stack *stk_b)
{
	while (!is_sorted(stk_a) && stk_a->next->next->next)
		print_p_push(&stk_a, &stk_b, 'b');
	stk_a = sort_3elem(stk_a);
	while (stk_b)
		sorting_1(&stk_a, &stk_b, NULL);
	if (!is_sorted(stk_a))
	{
		if (to_the_top(stk_a, f_min(stk_a)->data)
			<= to_the_down(stk_a, f_min(stk_a)->data))
			while (stk_a != f_min(stk_a))
				stk_a = print_rotate_r(stk_a, 'a');
		else
			while (stk_a != f_min(stk_a))
				stk_a = print_rev_rot_rr(stk_a, 'a');
	}
	return (stk_a);
}

t_stack	*sort_2elem(t_stack *stk)
{
	stk = print_s_swap(stk, 'a');
	return (stk);
}

t_stack	*sort_3elem(t_stack *stk)
{
	is_sorted(stk);
	if (stk->data > stk->next->data
		&& stk->data > stk->next->next->data)
		stk = print_rotate_r(stk, 'a');
	if (stk->next->data > stk->data
		&& stk->next->data > stk->next->next->data)
		stk = print_rev_rot_rr(stk, 'a');
	if (is_sorted(stk))
		return (stk);
	stk = print_s_swap(stk, 'a');
	return (stk);
}
