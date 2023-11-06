/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcardina <jcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:08:42 by jcardina          #+#    #+#             */
/*   Updated: 2023/11/06 18:43:38 by jcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*philo_init(t_table *tab, int nb)
{
	t_philo	*tmp;

	tmp = malloc(sizeof(t_philo));
	if (!tmp)
		return (NULL);
	if (tmp)
	{
		tmp->id = nb;
		tmp->sms = 0;
		tmp->meal_n = 0;
		tmp->dead = 0;
		tmp->sated = 0;
		tmp->status = 0;
		tmp->table = tab;
		tmp->next = NULL;
		pthread_mutex_init(&tmp->l_fork, NULL);
	}
	return (tmp);
}

void	add_front(t_table *tab, t_philo *new)
{
	pthread_mutex_t	*tmp;

	new->next = tab->philo;
	tab->philo = new;
	(new->next)->prev = new;
	tmp = &new->l_fork;
	(new->next)->r_fork = tmp;
}

void	philo_list(t_table *tab)
{
	t_philo			*tmp;
	t_philo			*tmp2;
	pthread_mutex_t	*tmp3;
	int				nb;

	nb = tab->nb_philo;
	while (nb > 0)
	{
		tmp = philo_init(tab, nb);
		if (nb == tab->nb_philo)
		{
			tab->philo = tmp;
			tmp2 = tmp;
			tmp3 = &tmp2->l_fork;
		}
		else if (nb < tab->nb_philo)
			add_front(tab, tmp);
		nb--;
	}
	(tab->philo)->prev = tmp2;
	tmp2->next = tab->philo;
	(tab->philo)->r_fork = tmp3;
}

void	tab_init(t_table *tab, char **av, int ac)
{
	tab->nb_philo = ft_atoi(av[1]);
	tab->t_die = ft_atoi(av[2]);
	tab->t_eat = ft_atoi(av[3]);
	tab->t_sleep = ft_atoi(av[4]);
	tab->nb_eat = -1;
	if (ac == 6)
		tab->nb_eat = ft_atoi(av[5]);
	else
	tab->start = get_time();
	philo_list(tab);
}
