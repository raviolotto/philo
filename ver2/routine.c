/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcardina <jcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:32:48 by jcardina          #+#    #+#             */
/*   Updated: 2023/11/06 18:21:54 by jcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void	*timer(void *tmp)
{
	t_philo		*philo;
	//uint64_t	time;
	uint64_t	time2;

	philo = (t_philo *)tmp;
	philo->time = get_time();
	while (philo->status == 0)
	{
		time2 = get_time() - philo->time;
		if ((time2) > philo->table->t_die)
		{
			philo->dead = 1;
			return (NULL);
		}
	}
	return (NULL);
}

void	*sbirro(void *tab)
{
	int		i;
	t_table	*tmp;
	t_philo	*philo;

	i = 0;
	tmp = (t_table *)tab;
	philo = tmp->philo;
	while (i > -1)
	{
		if (deadtouch(philo, (meal_death(tmp, philo))) != 0)
			return (NULL);
	}
	return (NULL);
}

void	*routine(void *philo)
{
	t_philo		*tmp;
	pthread_t	time;

	tmp = (t_philo *)philo;
	tmp->tid2 = &time;
	if (tmp->table->nb_philo < 2)
		tmp->dead = 1;
	while (tmp->dead == 0)
	{
		if (tmp->meal_n > 0)
		{
			sms(tmp, "is sleeping", 0);
			usleep((tmp->table->t_sleep) * 1000);
			sms(tmp, "is thinking", 0);
		}
		if (tmp->meal_n == 0)
			pthread_create(&time, NULL, &timer, tmp);
		ft_lunch(tmp);
	}
	tmp->status = 1;
	pthread_join(time, NULL);
	return (NULL);
}

void	start(t_table *tab)
{
	int			i;
	t_philo		*tmp;
	pthread_t	cop;

	tmp = tab->philo;
	i = 0;
	while (i < tab->nb_philo)
	{
		if (pthread_create(&tmp->tid, NULL, &routine, tmp) != 0)
		{
			write(1, "error\n", 6);
			return ;
		}
		usleep(60);
		tmp = tmp->next;
		i++;
	}
	if (pthread_create(&cop, NULL, &sbirro, tab) != 0)
		return ;
	if (pthread_join(cop, NULL) != 0)
		return ;
	ft_join(tmp, i);
}
