/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcardina <jcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:32:48 by jcardina          #+#    #+#             */
/*   Updated: 2023/10/06 18:04:27 by jcardina         ###   ########.fr       */
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
	if(philo->meal_n == philo->table->nb_eat)
		philo->sated = 1;
	sms(philo, "is eating");
	ft_usleep(philo->table->t_eat);
}

void *routine(void *philo)
{
	t_philo *tmp;

	tmp = (t_philo *)philo;
	while(tmp->dead == 0)
	{
		ft_lunch(philo);
	}
	return ((void *)0);
}

void	start(t_table *tab)
{
	int	i;
	t_philo *tmp;

	tmp = tab->philo;
	tab->race = 0;
	i = 0;
	while(i++ < tab->nb_philo)
	{
		if(pthread_create(&tmp->tid, NULL, &routine, tmp) != 0)
		{
			write(1, "error\n", 6);
			return ;
		}
		usleep(60000);
		tmp = tmp->next;
	}
	//funzio di controllo forse un tread a parte
	while(--i > 0)
	{
		if(pthread_join(tmp->tid, NULL) != 0)
			{
				write(1, "error\n", 6);
				return;
			}
		tmp = tmp->prev;
	}
}

