/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kannie <kannie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 10:02:19 by kannie            #+#    #+#             */
/*   Updated: 2022/06/29 15:00:10 by kannie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] == str2[i] && str1[i] != '\n')
		i++;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}

void	checker_do(t_stack **a, t_stack **b, char *line)
{
	if (!ft_strcmp(line, "sa\n"))
		*a = swap_s(*a);
	else if (!ft_strcmp(line, "sb\n"))
		*b = swap_s(*b);
	else if (!ft_strcmp(line, "ss\n"))
	{
		*a = swap_s(*a);
		*b = swap_s(*b);
	}
	else if (!ft_strcmp(line, "pa\n"))
		push_p(b, a);
	else if (!ft_strcmp(line, "pb\n"))
		push_p(a, b);
	else if (!ft_strcmp(line, "ra\n"))
		*a = rotate_r(*a);
	else if (!ft_strcmp(line, "rb\n"))
		*b = rotate_r(*b);
	else if (!ft_strcmp(line, "rr\n"))
	{
		*a = rotate_r(*a);
		*b = rotate_r(*b);
	}
	else
		checker_do_else(a, b, line);
}

void	checker_do_else(t_stack **a, t_stack **b, char *line)
{
	if (!ft_strcmp(line, "rra\n"))
		*a = rev_rotate_rr(*a);
	else if (!ft_strcmp(line, "rrb\n"))
		*b = rev_rotate_rr(*b);
	else if (!ft_strcmp(line, "rrr\n"))
	{
		*a = rev_rotate_rr(*a);
		*b = rev_rotate_rr(*b);
	}
	else
		write_error();
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	char		*line;

	if (argc < 2)
		exit(0);
	a = init_stack(argc - 2, &(argv[1]), 1);
	b = NULL;
	line = get_next_line(0);
	while (line)
	{
		checker_do(&a, &b, line);
		free(line);
		line = get_next_line(0);
	}
	if (is_sorted(a) && !b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	delete_stack(a);
	delete_stack(b);
}
