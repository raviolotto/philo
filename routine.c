/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcardina <jcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:32:48 by jcardina          #+#    #+#             */
/*   Updated: 2023/10/07 18:49:49 by jcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

/*void* ruotine(void *philo)
{
	pseudo codice
	while(tempo morte < tempo morte tavolo && tavolo vivo)
	{
		if(se la forchetta del vicino é libera)
		{
			blocca le forchette
			printa ho perso la forchetta
			mangia
			tempo morte = 0
			pasto ++;
			printa sto mangiando
			sblocca forchetta

			scompattare in funzione mangia

			considerazioni per il numero dei pasti
			{
				somma ai pasti globali solo se raggiunta la quota
				poi si segna come sazio se é sazio non aggiungerá
				piú la sua quota
			}
		}
		printa dormi
		if (dormi(philo) == 1)
			return(morte)
		tempo morte += tempo dormi
		printa pensa
		if (pensa(philo) == 1)
			return(morte)
		tempo morte += tempo pensa
	}
	printa é morto
}*/
void	ft_lunch(t_philo *philo)
{
	pthread_mutex_lock(&philo->l_fork);
	sms(philo, "has taken a fork");
	pthread_mutex_lock(philo->r_fork);
	sms(philo, "has taken a fork");
	philo->meal_n++;
	if (philo->meal_n == philo->table->nb_eat)
		philo->sated = 1;
	sms(philo, "is eating");
	ft_usleep(philo->table->t_eat);
	pthread_mutex_unlock(&philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	*routine(void *philo)
{
	t_philo	*tmp;

	tmp = (t_philo *)philo;
	while (tmp->dead == 0)
	{
		ft_lunch(tmp);
		sms(tmp, "is sleeping");
		ft_usleep(tmp->table->t_sleep);
		sms(tmp, "is thinking");
	}
	return ((void *)0);
}

void	start(t_table *tab)
{
	int		i;
	t_philo	*tmp;

	tmp = tab->philo;
	tab->race = 0;
	i = 0;
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
	while (--i > 0)
	{
		if (pthread_join(tmp->tid, NULL) != 0)
		{
			write(1, "error\n", 6);
			return ;
		}
		tmp = tmp->prev;
	}
}
