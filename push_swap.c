/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kannie <kannie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 20:38:06 by kannie            #+#    #+#             */
/*   Updated: 2022/06/29 15:00:24 by kannie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*stk_a;
	t_stack	*stk_b;
	t_stack	*stk;

	if (argc < 2)
		exit(0);
	stk_b = NULL;
	stk_a = init_stack(argc - 2, &(argv[1]), 0);
	if (!(stk_a->next->next) && !is_sorted(stk_a))
		stk_a = sort_2elem(stk_a);
	else
	{
		stk_a = sorting(stk_a, stk_b);
		stk = stk_a;
		while (stk)
		{
			printf("%d ", stk->data);
			stk = stk->next;
		}
	}
}
