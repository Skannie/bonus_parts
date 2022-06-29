/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kannie <kannie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 20:38:06 by kannie            #+#    #+#             */
/*   Updated: 2022/06/29 14:45:25 by kannie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(int nbr, char **sstr, int flag)
{
	t_stack	*new;
	t_stack	*res;
	int		i;

	i = 0;
	res = NULL;
	while (nbr >= i)
	{
		new = (t_stack *)malloc(sizeof(t_stack));
		if (!new)
			exit(0);
		new->data = ft_atoi(sstr[i]);
		new->next = NULL;
		if (!res)
			res = new;
		else
			go_last(res)->next = new;
		i++;
	}
	check_double(res);
	if (flag == 0)
		if (is_sorted(res))
			exit(0);
	return (res);
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

void	delete_stack(t_stack *stk)
{
	t_stack	*next;

	while (stk)
	{
		next = stk->next;
		free(stk);
		stk = next;
	}
}

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
