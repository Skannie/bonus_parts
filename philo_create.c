/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kannie <kannie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:07:18 by kannie            #+#    #+#             */
/*   Updated: 2022/06/22 17:53:16 by kannie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_create(t_waiter *waiter)
{
	int	i;

	i = -1;
	waiter->philo = malloc (sizeof(t_philo) * waiter->nbr_philo);
	if (!waiter->philo)
		return (-1);
	waiter->start = time_to();
	while (++i < waiter->nbr_philo)
	{
		values_philo(waiter, &(waiter->philo[i]), i);
		waiter->philo[i].pid_id = fork();
		if (waiter->philo[i].pid_id == 0)
		{
			philo_life(&waiter->philo[i]);
			return (0);
		}
	}
	waiter_philo(waiter);
	return (0);
}

void	philo_life(t_philo *philo)
{
	pthread_create(philo->check_life, NULL, &philo_check, philo);
	while (1)
	{
		sem_wait(philo->forks);
		what_philo_do(philo, "32m has taken a fork", 0);
		sem_wait(philo->forks);
		what_philo_do(philo, "32m has taken a fork", 0);
		philo->last_eat = time_to();
		what_philo_do(philo, "35m is eating", philo->time_to_eat);
		philo->nbr_eat++;
		sem_post(philo->forks);
		sem_post(philo->forks);
		what_philo_do(philo, "34m is sleeping", philo->time_to_sleep);
		what_philo_do(philo, "36m is thinking", 0);
	}
}

void	what_philo_do(t_philo *philo, char *str, int time_to_do)
{
	sem_wait(philo->print);
	printf("%lld %d\033[0;%s\e[0m\n", (time_to() - philo->start), philo->id, str);
	sem_post(philo->print);
	if (time_to_do > 0)
		ft_sleep_philo(time_to_do, philo);
}
