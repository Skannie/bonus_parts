/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kannie <kannie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 18:48:29 by kannie            #+#    #+#             */
/*   Updated: 2022/06/30 18:57:01 by kannie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*clear;

	while (*lst)
	{
		if ((*lst)->content)
			del((*lst)->content);
		clear = *lst;
		*lst = (*lst)->next;
		free (clear);
	}
	lst = NULL;
}
