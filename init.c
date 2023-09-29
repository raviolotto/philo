/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcardina <succosopompelmo>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:08:42 by jcardina          #+#    #+#             */
/*   Updated: 2023/09/29 17:22:10 by jcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*philo_init(t_table *tab, int nb)
{
	t_philo	*tmp;

	tmp = malloc(sizeof(t_philo));
	if(tmp)
	{
		tmp->id = nb;
		tmp->meal_n = tab->nb_eat;
		tmp->dead = 0;
		tmp->sated = 0;
		tmp->table = tab;
		tmp->next = NULL;
	}
	return(tmp);
}

void	add_front(t_table *tab, t_philo *new)
{
	new->next = tab->philo;
	tab->philo = new;
	(new->next)->prev = new;
}

void	philo_list(t_table *tab)
{
	t_philo	*tmp;
	t_philo *tmp2;
	int nb;

	nb = tab->nb_philo;
	while(nb > 0)
	{
		tmp = philo_init(tab, nb);
		if (nb == tab->nb_philo)
		{
		tab->philo = tmp;
		tmp2 = tmp;
		}
		if(nb < tab->nb_philo)
			add_front(tab, tmp);
		nb--;
	}
	(tab->philo)->prev = tmp2;
	tmp2->next = tab->philo;
}

void	tab_init(t_table *tab, char **av, int ac)
{
	tab->nb_philo = ft_atoi(av[1]);
	tab->t_die = ft_atoi(av[2]);
	tab->t_eat = ft_atoi(av[3]);
	tab->t_sleep = ft_atoi(av[4]);
	if(ac == 6)
		tab->nb_eat = ft_atoi(av[5]);
	philo_list(tab);
}
