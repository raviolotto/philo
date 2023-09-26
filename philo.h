/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcardina <succosopompelmo>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:39:46 by jcardina          #+#    #+#             */
/*   Updated: 2023/09/26 16:19:52 by jcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

typedef struct s_philo
{
	pthread_t	index;
	int			id;
	int			meal_n;
	struct s_philo	*next;
	struct s_philo	*prev;
}	t_philo;

typedef struct s_table
{
	int			nb_philo;
	u_int64_t	t_die;
	u_int64_t	t_eat;
	u_int64_t	t_sleep;
	int			nb_eat;
}	t_table;

int	check(char **av);
