/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcardina <jcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:46:20 by jcardina          #+#    #+#             */
/*   Updated: 2023/11/06 19:42:50 by jcardina         ###   ########.fr       */
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
		if (j == 1 || j == 2)
		{
			tmp->dead = 1;
			tmp->status = 1;
			sms(tmp, "is dead", tmp->sms);
		}
		tmp = tmp->next;
	}
	return (1);
}

void	ft_lunch(t_philo *philo)
{
	if (pthread_mutex_lock(philo->r_fork) == 0)
	{
		//philo->status = 1;
		//pthread_join(*time, NULL);
		philo->time = get_time();
		sms(philo, "has taken a fork", 0);
		pthread_mutex_lock(&philo->l_fork);
		sms(philo, "has taken a fork", 0);
	}
	philo->meal_n++;
	if (philo->meal_n == philo->table->nb_eat)
		philo->sated = 1;
	sms(philo, "is eating", 0);
	philo->status = 0;
	//pthread_create(time, NULL, &timer, philo);
	usleep((philo->table->t_eat) * 1000);
	pthread_mutex_unlock(&philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

int	meal_death(t_table *tab, t_philo *philo)
{
	int		i;
	int		meal;
	t_philo	*tmp;

	i = 0;
	meal = 0;
	tmp = philo;
	while (i < tab->nb_philo)
	{
		if (tmp->dead == 1)
		{
			tmp->sms = 1;
			return (1);
		}
		else if (tmp->sated == 1)
			meal++;
		i++;
		tmp = tmp->next;
	}
	if (meal == tab->nb_philo)
		return (2);
	return (0);
}

void	ft_join(t_philo *philo, int i)
{
	while (--i >= 0)
	{
		if (pthread_join(philo->tid, NULL) != 0)
			return ;
		philo = philo->prev;
	}
}
