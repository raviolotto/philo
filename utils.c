/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcardina <jcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:10:26 by jcardina          #+#    #+#             */
/*   Updated: 2023/10/12 17:18:14 by jcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10;
		result = result + str[i] - '0';
		i++;
	}
	return (result * sign);
}

uint64_t	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (uint64_t)1000) + (tv.tv_usec / 1000));
}

void	sms(t_philo *philo, char *str, int i)
{
	if (philo->dead == 0)
		printf("%ld %i %s\n",
			(get_time() - philo->table->start), philo->id, str);
	else if (i == 1)
		printf("%ld %i %s\n",
			(get_time() - philo->table->start), philo->id, str);
}

void	ft_usleep(unsigned int time)
{
	uint64_t	start;

	start = get_time();
	while ((get_time() - start) < time)
		usleep(time / 10);
}

// void	free_list(struct t_philo *list)
// {
// 	if (list->next)
// 		free_list(list->next);
// 	free(list);
// }

void	destroyer(t_philo *philo)
{
	if (philo->id != philo->table->nb_philo)
		destroyer(philo->next);
	pthread_mutex_destroy(&philo->l_fork);
	free(philo);
}

void	destroyer2(t_philo *philo)
{
	int		i;
	t_philo	*tmp1;

	i = 0;
	while (i < philo->table->nb_philo)
	{
		tmp1 = philo->next;
		pthread_mutex_destroy(&philo->l_fork);
		free(philo);
		philo = tmp1;
		i++;
	}
}

void	destroyer3(t_philo *philo, int i)
{
	if (i < philo->table->nb_philo)
		destroyer3(philo->next, i + 1);
	pthread_mutex_destroy(&philo->l_fork);
	free(philo);
}
