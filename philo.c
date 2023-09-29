/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcardina <succosopompelmo>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 17:49:19 by jcardina          #+#    #+#             */
/*   Updated: 2023/09/29 18:37:52 by jcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void	ft_printlst(t_table *tab)
{
	t_philo	*tmp;
	t_philo	*save;
	int		i;

	save = tab->philo;
	while (save)
	{
		tmp = save->next;
		i = save->id;
		printf("%d ", i);
		save = tmp;
	}
	printf(" / ");
}

int	main(int ac, char **av)
{
	t_table	tab;

	if (bigchecker(ac, av) == 1)
		return (1);
	tab_init(&tab, av, ac);
	//printf("%d\n%ld\n%ld\n%ld\n%d\n", tab.nb_philo, tab.t_die, tab.t_eat, tab.t_sleep, tab.nb_eat);
	ft_printlst(&tab);
}
