/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgervais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 03:40:38 by bgervais          #+#    #+#             */
/*   Updated: 2023/01/16 14:06:47 by bgervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int long	ft_get_timestamp(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return (now.tv_sec * 1000 + now.tv_usec / 1000);
}

void	ft_usleep(long time)
{
	long	begin;

	begin = ft_get_timestamp();
	while (ft_get_timestamp() - begin < time)
		usleep(10);
}

void	ft_destroy_mutex(t_data *d)
{
	int	i;

	i = 0;
	while (i < d->p)
	{
		pthread_mutex_destroy(&d->forks[i]);
		pthread_mutex_destroy(&d->philo[i].time);
		i++;
	}
	pthread_mutex_destroy(&d->died_m);
	pthread_mutex_destroy(&d->dinner_m);
}

void	ft_init(t_data *d)
{
	int	i;

	i = 0;
	while (i < d->p)
	{
		pthread_mutex_init(&d->forks[i], NULL);
		d->philo[i].left = &d->forks[i];
		pthread_mutex_init(&d->philo[i].time, NULL);
		if (i != d->p - 1)
			d->philo[i].right = &d->forks[i + 1];
		else
			d->philo[i].right = &d->forks[0];
		d->philo[i].number = i;
		d->philo[i].timestamp = ft_get_timestamp();
		d->philo[i].data = d;
		d->philo[i].dinner = 0;
		i++;
	}
	d->repas = d->p;
	pthread_mutex_init(&d->died_m, NULL);
	pthread_mutex_init(&d->print, NULL);
	pthread_mutex_init(&d->dinner_m, NULL);
}

int	print(t_philo *philo, char *state)
{
	int	dead;

	pthread_mutex_lock(&philo->data->died_m);
	dead = philo->data->died;
	pthread_mutex_unlock(&philo->data->died_m);
	if (dead)
		return (1);
	pthread_mutex_lock(&philo->data->print);
	printf("%ld %d %s", ft_get_timestamp() - philo->data->start,
		philo->number, state);
	pthread_mutex_unlock(&philo->data->print);
	return (0);
}
