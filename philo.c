/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcardina <jcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 17:49:19 by jcardina          #+#    #+#             */
/*   Updated: 2023/11/03 15:50:59 by jcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	main(int ac, char **av)
{
	t_table	tab;

	if (bigchecker(ac, av) == 1)
		return (1);
	tab_init(&tab, av, ac);
	start(&tab);
}
