/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcardina <succosopompelmo>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:39:46 by jcardina          #+#    #+#             */
/*   Updated: 2023/09/25 17:43:07 by jcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

typedef struct s_philo
{
	pthread_t	index;
	int			nb;
	struct s_philo	*next;
	struct s_philo	*prev;
}	t_philo;


