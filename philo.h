/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kannie <kannie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:35:29 by kannie            #+#    #+#             */
/*   Updated: 2022/06/22 18:23:42 by kannie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <sys/types.h>
# include <semaphore.h>
# include <fcntl.h>

typedef struct s_philo
{
	int				id;
	int				pid_id;
	int				nbr_philo;
	long long		start;
	int				must_eat;
	long long		last_eat;
	int				time_to_life;
	int				time_to_eat;
	int				time_to_sleep;
	int				s_die;
	int				sig_eat;
	int				nbr_eat;
	int				f_kill;
	sem_t			*forks;
	sem_t			*print;
	sem_t			*eat;
	pthread_t		check_life;
}	t_philo;

typedef struct s_waiter
{
	sem_t			*forks;
	sem_t			*print;
	sem_t			*eat;
	t_philo			*philo;
	long long		start;
	int				must_eat;
	int				nbr_philo;
	int				time_to_life;
	int				time_to_eat;
	int				time_to_sleep;
	int				f;
}	t_waiter;

int			ft_atoi(const char *str);
int			schar_v_int(const char *strok, int i, int minus);
int			check_str(char *str);
int			print_exit(int i);
int			values_waiter(char *str[], t_waiter *waiter);
void		values_philo(t_waiter *waiter, t_philo *philo, int i);
void		init_sem(t_waiter *waiter);
int			num_portion(char *str, t_waiter *waiter);
int			philo_create(t_waiter *waiter);
void		philo_life(t_philo *buf);
void		what_philo_do(t_philo *philo, char *str,
				int time_to_do);
void		ft_sleep_philo(long long time_do, t_philo *philo);
long long	time_to(void);
void		*philo_check(void *buf);
void		f_check(t_philo *philo);

#endif