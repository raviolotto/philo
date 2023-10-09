/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcardina <jcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 17:49:19 by jcardina          #+#    #+#             */
/*   Updated: 2023/10/09 14:40:58 by jcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

// void	ft_printlst(t_table *tab)
// {
// 	t_philo	*tmp;
// 	t_philo	*save;
// 	int		i;
// 	int		j;

// 	j = 0;
// 	save = tab->philo;
// 	while (j++ < tab->nb_philo)
// 	{
// 		tmp = save->next;
// 		i = save->id;
// 		printf("%d ", i);
// 		printf("l fork %p		r fork %p\n", &save->l_fork, save->r_fork);
// 		save = tmp;
// 	}
// 	printf(" / ");
// }

int	main(int ac, char **av)
{
	t_table	tab;

	if (bigchecker(ac, av) == 1)
		return (1);
	tab_init(&tab, av, ac);
	start(&tab);
}
