/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kannie <kannie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 18:19:43 by kannie            #+#    #+#             */
/*   Updated: 2022/06/29 15:00:22 by kannie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	schar_v_int(const char *strok, int i, int minus)
{
	long	l;

	l = 0;
	while (strok[i])
	{
		if (strok[i] >= '0' && strok[i] <= '9')
			l = l * 10 + (strok[i] - 48);
		else
			write_error();
		if (l > INT_MAX && l < INT_MIN)
			write_error();
		i++;
	}
	return (l * minus);
}

int	ft_atoi(const char *str)
{
	int				a;
	int				minus;
	long			b;

	a = 0;
	b = 0;
	minus = 1;
	while (str[a] == ' ' || str[a] == '\n' || str[a] == '\t'
		|| str[a] == '\v' || str[a] == '\r' || str[a] == '\f')
		a++;
	if (str[a] == '+' || str[a] == '-')
	{
		if (str[a] == '-' && str[a + 1] != '-')
			minus = -1;
		else if (str[a] == '+' && str[a + 1] != '+')
			minus = 1;
		a++;
	}
	if (str[a] >= 48 && str[a] <= 57)
	{
		b = schar_v_int(str, a, minus);
	}
	else
		write_error();
	return (b);
}

t_stack	*go_last(t_stack *stk)
{
	if (stk == NULL)
		return (NULL);
	while (stk->next)
		stk = stk->next;
	return (stk);
}

t_stack	*go_prelast(t_stack *stk)
{
	if (stk == NULL)
		return (NULL);
	while (stk->next->next)
		stk = stk->next;
	return (stk);
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
