/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kannie <kannie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 14:10:02 by kannie            #+#    #+#             */
/*   Updated: 2022/06/30 22:04:04 by kannie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_num_sym(int n)
{
	int	res;

	res = 0;
	if (n <= 0)
		res++;
	while (n)
	{
		res++;
		n = n / 10;
	}
	return (res);
}

static int	stepen(int n)
{
	int	res;

	res = 1;
	while (n)
	{
		res *= 10;
		n--;
	}
	return (res);
}

static char	*if_min_int(void)
{
	char	*res;

	res = (char *)malloc(12 * sizeof(char));
	if (!res)
		return (NULL);
	res[0] = '-';
	res[1] = '2';
	res[2] = '1';
	res[3] = '4';
	res[4] = '7';
	res[5] = '4';
	res[6] = '8';
	res[7] = '3';
	res[8] = '6';
	res[9] = '4';
	res[10] = '8';
	res[11] = 0;
	return (res);
}

char	*ft_itoa(int n)
{
	int		count;
	char	*res;
	int		num_sym;

	if (n == -2147483648)
		return (if_min_int());
	count = 0;
	num_sym = get_num_sym(n);
	res = (char *)malloc((num_sym + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[num_sym] = 0;
	if (n < 0)
	{
		res[0] = '-';
		count++;
		num_sym--;
		n = -n;
	}
	while (num_sym > 0)
	{
		res[count++] = n / (stepen(num_sym - 1)) + '0';
		n = n % (stepen(--num_sym));
	}
	return (res);
}
