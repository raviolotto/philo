/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcardina <jcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:32:48 by jcardina          #+#    #+#             */
/*   Updated: 2023/10/10 15:30:05 by jcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

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
		if(deadtouch(philo, (meal_control(tmp, philo))) != 0)
			return ((void *)0);
		// if (meal_control(tmp, philo) == 1)
		// {
		// 	deadtouch(philo);
		// 	return ((void *)0);
		// }
		// else if (death_control(tmp, philo) == 1)
		// {
		// 	deadtouch(philo);
		// 	return ((void *)0);
		// }
	}
	return ((void *)0);
}

void	*routine(void *philo)
{
	t_philo	*tmp;

	tmp = (t_philo *)philo;
	while (tmp->dead == 0)
	{
		if(tmp->meal_n > 0)
		{
			sms(tmp, "is sleeping");
			ft_usleep(tmp->table->t_sleep);
			sms(tmp, "is thinking");
		}
		ft_lunch(tmp);
	}
	return ((void *)0);
}

void	start(t_table *tab)
{
	int			i;
	t_philo		*tmp;
	pthread_t	cop;

	tmp = tab->philo;
	i = 0;
	pthread_create(&cop, NULL, &sbirro, tab);
	while (i++ < tab->nb_philo)
	{
		if (pthread_create(&tmp->tid, NULL, &routine, tmp) != 0)
		{
			write(1, "error\n", 6);
			return ;
		}
		usleep(6000);
		tmp = tmp->next;
	}
	pthread_join(cop, NULL);
	while (--i > 0)
	{
		if (pthread_join(tmp->tid, NULL) != 0)
		{
			write(1, "dead touch\n", 12);
			return ;
		}
		tmp = tmp->prev;
	}
}
