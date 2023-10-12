/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcardina <jcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:46:20 by jcardina          #+#    #+#             */
/*   Updated: 2023/10/12 17:14:15 by jcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	deadtouch(t_philo *philo, int j)
{
	t_philo	*tmp;
	int		i;

	tmp = philo;
	i = 0;
	if (j == 0)
		return (0);
	while (i < philo->table->nb_philo)
	{
		i++;
		if (j == 1)
		{
			tmp->dead = 1;
			tmp->status = 1;
			sms(tmp, "is dead", 1);
			//pthread_join(*(tmp->tid2), NULL);
		}
		pthread_detach(tmp->tid);
		pthread_detach(*(tmp->tid2));
		tmp = tmp->next;
	}
	return (1);
}

void	ft_lunch(t_philo *philo, pthread_t *time)
{
	if (pthread_mutex_lock(philo->r_fork) == 0)
	{
		philo->status = 1;
		pthread_join(*time, NULL);
		sms(philo, "has taken a fork", 0);
		pthread_mutex_lock(&philo->l_fork);
		sms(philo, "has taken a fork", 0);
	}
	philo->meal_n++;
	if (philo->meal_n == philo->table->nb_eat)
		philo->sated = 1;
	sms(philo, "is eating", 0);
	philo->status = 0;
	pthread_create(time, NULL, &timer, philo);
	ft_usleep(philo->table->t_eat);
	pthread_mutex_unlock(&philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

int	meal_death(t_table *tab, t_philo *philo)
{
	int	i;
	int	meal;

	i = 0;
	meal = 0;
	while (i < tab->nb_philo)
	{
		if (philo->dead == 1)
			return (1);
		else if (philo->sated == 1)
			meal++;
		i++;
		philo = philo->next;
	}
	if (meal == tab->nb_philo)
		return (2);
	return (0);
}

void	ft_join(t_philo *philo, int i)
{
	while (--i > 0)
	{
		if (pthread_join(philo->tid, NULL) != 0)
		{
			write(1, "dead touch\n", 12);
			return ;
		}
		philo = philo->prev;
	}
}
