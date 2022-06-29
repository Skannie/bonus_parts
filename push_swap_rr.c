/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kannie <kannie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 20:03:25 by kannie            #+#    #+#             */
/*   Updated: 2022/06/29 15:00:18 by kannie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*rev_rotate_rr(t_stack *stk)
{
	t_stack	*rh;
	t_stack	*rprel;

	if (!stk || !stk->next)
		return (stk);
	rprel = go_prelast(stk);
	rh = rprel->next;
	rprel->next = NULL;
	rh->next = stk;
	return (rh);
}

t_stack	*print_rev_rot_rr(t_stack *stk, char a)
{
	write(1, "rr", 2);
	write(1, &a, 1);
	write(1, "\n", 1);
	return (rev_rotate_rr(stk));
}

void	double_rev_rot_rr(t_stack **stk_a, t_stack **stk_b)
{
	*stk_a = rev_rotate_rr(*stk_a);
	*stk_b = rev_rotate_rr(*stk_b);
	write(1, "rrr\n", 4);
}

void	write_error(void)
{
	write(1, "Error\n", 6);
	exit(0);
}
