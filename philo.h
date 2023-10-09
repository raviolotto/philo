/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcardina <jcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:39:46 by jcardina          #+#    #+#             */
/*   Updated: 2023/10/09 17:12:49 by jcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdint.h>
# include <sys/types.h>
# include <unistd.h>

typedef struct s_philo
{
	pthread_t		tid;
	pthread_mutex_t	l_fork;
	pthread_mutex_t	*r_fork;
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
	uint64_t	start;
	int			nb_philo;
	int			nb_eat;
}	t_table;

// input ok?
int			check(char **av);
int			bigchecker(int ac, char **av);
// utils
uint64_t	get_time(void);
int			ft_atoi(const char *str);
void		sms(t_philo *philo, char *str);
void		ft_usleep(unsigned int time);
// listing and init
void		tab_init(t_table *tab, char **av, int ac);
void		philo_list(t_table *tab);
void		add_front(t_table *tab, t_philo *new);
t_philo		*philo_init(t_table *tab, int nb);
// start routinwe
void		start(t_table *tab);
void		*routine(void *philo);

#endif

//a che punto sono arrivato
//
//
//
//
//
//
//
//
//
//
