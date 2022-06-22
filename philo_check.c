/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kannie <kannie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:55:46 by kannie            #+#    #+#             */
/*   Updated: 2022/06/22 18:24:36 by kannie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	f_check(t_philo *philo)
{
	if (philo->must_eat > 0)
		if (philo->must_eat == philo->nbr_eat)
		{
			
			philo->sig_eat = 1;
		}
	if ((time_to() - philo->last_eat) > philo->time_to_life)
	{
		philo->s_die = 1;
		sem_wait(philo->print);
		printf("%lld %d\033[0;31m died\e[0m\n",
			(time_to() - philo->start), philo->id);
		sem_post(philo->print);
	}
}

void	*philo_check(void *buf)
{
	t_philo		*philo;

	philo = (t_philo *)buf;
	while (1)
	{
		f_check(philo);
		if (philo->sig_eat == 1 || philo->s_die == 1)
			break ;
	}
	exit(0);
}
