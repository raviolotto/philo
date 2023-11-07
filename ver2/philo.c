/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcardina <jcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 17:49:19 by jcardina          #+#    #+#             */
/*   Updated: 2023/11/07 15:44:25 by jcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	main(int ac, char **av)
{
	t_table	tab;
	t_table	*tmp;

	if (ac == 5)
		tab.nb_eat = -1;
	tmp = &tab;
	if (bigchecker(ac, av) == 1)
		return (1);
	tab_init(tmp, av, ac);
	start(&tab);
	destroyer2(tmp->philo);
}
