/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcardina <jcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:32:48 by jcardina          #+#    #+#             */
/*   Updated: 2023/10/02 18:01:06 by jcardina         ###   ########.fr       */
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
			printa ho perso la forchetta
			blocca la tua forchetta
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
void *routine(void *tab)
{
	t_philo *tmp;
	int	i;

	i = 0;
	tmp = (t_philo *)tab;
	while(i++ < 1000000)
	{
		tmp->meal_n++;
	}
	printf("%i numero di filosofi   \n", tmp->meal_n);
	write(1, "a\n", 2);
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
		usleep(6000);
		tmp = tmp->next;
	}
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

