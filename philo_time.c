/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kannie <kannie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:12:21 by kannie            #+#    #+#             */
/*   Updated: 2022/06/22 16:08:03 by kannie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	time_to(void)
{
	struct timeval	tm;
	long long		time;

	gettimeofday(&tm, NULL);
	time = (tm.tv_sec * 1000 + tm.tv_usec / 1000);
	return (time);
}

void	ft_sleep_philo(long long time_do, t_philo *philo)
{
	long long	time_now;

	time_now = time_to();
	while (time_do > (time_to() - time_now))
		usleep(100);
}
