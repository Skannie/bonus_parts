/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kannie <kannie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 22:14:51 by kannie            #+#    #+#             */
/*   Updated: 2022/03/26 18:35:04 by kannie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting_1(t_stack **a, t_stack **b, t_stack *best)
{
	t_stack	*pos;
	int		a_top;
	int		a_bottom;
	int		b_top;
	int		b_bottom;

	best = f_best(*a, *b);
	pos = f_pos(*a, best->data);
	a_top = to_the_top(*a, pos->data);
	a_bottom = to_the_down(*a, pos->data);
	b_top = to_the_top(*b, best->data);
	b_bottom = to_the_down(*b, best->data);
	if (step(*a, *b, best->data) == max(a_top, b_top))
		top(a, b, a_top, b_top);
	else if (step(*a, *b, best->data) == max(a_bottom, b_bottom))
		down(a, b, a_bottom, b_bottom);
	else if (step(*a, *b, best->data) == a_top + b_bottom)
		there_b(a, b, a_top, b_bottom);
	else if (step(*a, *b, best->data) == a_bottom + b_top)
		back_th(a, b, a_bottom, b_top);
}

t_stack	*f_min(t_stack *stk_a)
{
	t_stack	*stk;

	stk = stk_a;
	while (stk_a)
	{
		if (stk_a->data < stk->data)
			stk = stk_a;
		stk_a = stk_a->next;
	}
	return (stk);
}

t_stack	*f_pos(t_stack *stk, int nbr)
{
	t_stack	*hstk;

	hstk = f_min(stk);
	while (hstk && hstk->data < nbr)
		hstk = hstk->next;
	if (!hstk)
	{
		hstk = stk;
		while (hstk != f_min(stk) && hstk->data < nbr)
			hstk = hstk->next;
	}
	return (hstk);
}

int	to_the_top(t_stack *stk, int nbr)
{
	int	i;

	i = 0;
	while (stk && stk->data != nbr)
	{
		i++;
		stk = stk->next;
	}
	return (i);
}

int	to_the_down(t_stack *stk, int nbr)
{
	int	i;

	i = 0;
	while (stk && stk->data != nbr)
		stk = stk->next;
	while (stk)
	{
		i++;
		stk = stk->next;
	}
	return (i);
}
