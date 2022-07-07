/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 04:57:09 by marvin            #+#    #+#             */
/*   Updated: 2022/06/17 14:06:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init_values(t_list *d)
{
	int	i;

	d->init_philo = 0;
	d->thread = malloc(sizeof(pthread_t *) * (d->num_philos));
	if (!d->thread)
		return (-1);
	pthread_mutex_init(&d->mutex_i, NULL);
	pthread_mutex_init(&d->mutex_msg, NULL);
	pthread_mutex_init(&d->mutex_fork, NULL);
	d->philo = malloc(sizeof(t_philo) * d->num_philos);
	if (!d->philo)
		return (-1);
	d->mutex = malloc(sizeof(pthread_mutex_t) * d->num_philos);
	if (!d->mutex)
		return (-1);
	i = -1;
	while (++i < d->num_philos)
	{
		d->philo[i].num_eats = 0;
		d->philo[i].fork_r = i - 1;
		d->philo[i].fork_l = i;
	}
	d->philo[0].fork_r = d->num_philos - 1;
	return (0);
}
