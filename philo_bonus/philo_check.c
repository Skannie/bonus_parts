/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kannie <kannie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:55:46 by kannie            #+#    #+#             */
/*   Updated: 2022/06/23 20:10:52 by kannie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_check(void *buf)
{
	t_philo		*philo;

	philo = (t_philo *)buf;
	while (1)
	{
		if (philo->must_eat > 0)
		{
			sem_wait(philo->print);
			if (philo->must_eat == philo->nbr_eat)
			{
				sem_post(philo->print);
				sem_post(philo->eat);
			}
			sem_post(philo->print);
		}
		sem_wait(philo->print);
		if ((time_to() - philo->last_eat) > philo->time_to_life)
		{
			printf("%lld %d\033[0;31m died\e[0m\n",
				(time_to() - philo->start), philo->id);
			exit (0);
		}
		sem_post(philo->print);
	}
}

void	*check_ate(void *buf)
{
	t_waiter	*waiter;
	int			i;

	waiter = (t_waiter *)buf;
	i = -1;
	while (++i < waiter->nbr_philo)
		sem_wait(waiter->eat);
	waiter->sig_ate = 1;
	i = -1;
	while (++i < waiter->nbr_philo)
		sem_post(waiter->eat);
	i = -1;
	while (++i < waiter->nbr_philo)
		kill(waiter->philo[i].pid_id, SIGTERM);
	return (NULL);
}
