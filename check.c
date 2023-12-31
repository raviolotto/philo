/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcardina <jcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:26:26 by jcardina          #+#    #+#             */
/*   Updated: 2023/10/02 14:56:33 by jcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	bigchecker(int ac, char **av)
{
	if (ac < 5 || ac > 6)
	{
		printf("error");
		return (1);
	}
	if (check(av) == 1)
	{
		printf("error");
		return (1);
	}
	return (0);
}

int	check(char **av)
{
	int	i;
	int	j;

	j = 1;
	while (av[j])
	{
		i = 0;
		while (av[j][i])
		{
			if (av[j][i] > 47 && av[j][i] < 58)
				i++;
			else
				return (1);
		}
		j++;
	}
	while (--j > 0)
	{
		if (ft_atoi(av[j]) < 1)
			return (1);
	}
	return (0);
}
