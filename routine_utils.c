/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcardina <jcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:46:20 by jcardina          #+#    #+#             */
/*   Updated: 2023/10/09 18:17:43 by jcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	deadtouch(t_philo *philo)
{
	t_philo	*tmp;
	int		i;

	tmp = philo;
	i = 0;
	while (i < philo->table->nb_philo)
	{
		i++;
		pthread_detach(tmp->tid);
		tmp = tmp->next;
	}
	return ;
}

void	ft_lunch(t_philo *philo)
{
	pthread_mutex_lock(&philo->l_fork);
	sms(philo, "has taken a fork");
	pthread_mutex_lock(philo->r_fork);
	sms(philo, "has taken a fork");
	philo->meal_n++;
	if (philo->meal_n == philo->table->nb_eat)
	{
		sms(philo, "é sazio");
		philo->sated = 1;
	}
	sms(philo, "is eating");
	ft_usleep(philo->table->t_eat);
	pthread_mutex_unlock(&philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

int	meal_control(t_table *tab, t_philo *philo)
{
	int i;
	int meal;

	i = 0;
	meal = 0;
	while (i < tab->nb_philo)
	{
		if (philo->sated == 1)
			meal++;
		i++;
		philo = philo->next;
	}
	if (meal == tab->nb_philo)
		return (1);
	return (0);
}
