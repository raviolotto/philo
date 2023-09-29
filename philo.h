/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcardina <succosopompelmo>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:39:46 by jcardina          #+#    #+#             */
/*   Updated: 2023/09/29 17:05:49 by jcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdint.h>

typedef struct s_philo
{
	pthread_t		tid;
	int				id;
	int				meal_n;
	int				dead;
	int				sated;
	struct s_philo	*next;
	struct s_philo	*prev;
	struct s_table	*table;
}	t_philo;

typedef struct s_table
{
	t_philo		*philo;
	uint64_t	t_die;
	uint64_t	t_eat;
	uint64_t	t_sleep;
	int			nb_philo;
	int			nb_eat;
}	t_table;

int		check(char **av);
int		ft_atoi(const char *str);
int		bigchecker(int ac, char **av);
void	tab_init(t_table *tab, char **av, int ac);
void	philo_list(t_table *tab);
void	add_front(t_table *tab, t_philo *new);
t_philo	*philo_init(t_table *tab, int nb);

#endif
