/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcardina <jcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:32:48 by jcardina          #+#    #+#             */
/*   Updated: 2023/10/09 17:10:28 by jcardina         ###   ########.fr       */
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
		{
			sms(philo, "é sazio");
			philo->sated = 1;
		}
	sms(philo, "is eating");
	ft_usleep(philo->table->t_eat);
	pthread_mutex_unlock(&philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

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

void	*sbirro(void *tab)
{
	int i;
	int meal;
	t_table *tmp;
	t_philo	*philo;

	i = 0;
	meal = 0;
	tmp = (t_table *)tab;
	philo = tmp->philo;
	while(i > -1)
	{
		while(i > tmp->nb_philo)
		{
			if(philo->sated == 1)
				meal++;
			i++;
			philo = philo->next;
		}
		printf("%i\n", );
		if(meal == tmp->nb_philo)
		{
			write(1, "aaaaaaaaaaaaaaaaaaaa\n", 21);
			deadtouch(philo);
			return ((void *)0);
		}
		i = 0;
		meal = 0;
	}
	return (void *)0;
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
	int			i;
	t_philo		*tmp;
	pthread_t	cop;

	tmp = tab->philo;
	tab->race = 0;
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
			write(1, "error\n", 6);
			return ;
		}
		tmp = tmp->prev;
	}
}
