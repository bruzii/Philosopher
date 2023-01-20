/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgervais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 03:47:17 by bgervais          #+#    #+#             */
/*   Updated: 2023/01/20 16:51:56 by bgervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_eat(t_philo *philo)
{
	if (philo -> number % 2)
	{
		if (ft_go_eat_even(philo) == 1)
			return (1);
	}
	else
	{
		if (ft_go_eat_odd(philo) == 1)
			return (1);
	}
	if (print(philo, "is eating\n"))
		return (1);
	ft_usleep(philo->data->e);
	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(philo->right);
	pthread_mutex_lock(&philo->time);
	philo->timestamp = ft_get_timestamp();
	pthread_mutex_unlock(&philo->time);
	philo->dinner = philo->dinner + 1;
	if (ft_if_dinner_is_complete(philo) == 1)
		return (1);
	return (0);
}

void	*thread_routine(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	if (philo->number % 2)
		ft_usleep(philo->data->e * 0.8);
	while (1)
	{
		if (philo->dinner && philo->data->p % 2)
			ft_usleep(philo -> data -> d * 0.25);
		if (philo->data->p > 1)
		{
			if (ft_eat(philo))
				break ;
		}
		else
		{
			if (ft_one_philo(philo))
				break ;
		}
	}
	return (NULL);
}

int	ft_track_dinner(t_data *d, int *i, int long *time_philo)
{
	int	repas;

	pthread_mutex_lock(&d->philo[*i].time);
	*time_philo = ft_get_timestamp() - d->philo[*i].timestamp;
	pthread_mutex_unlock(&d->philo[*i].time);
	pthread_mutex_lock(&d->dinner_m);
	repas = d->repas;
	pthread_mutex_unlock(&d->dinner_m);
	if (repas == 0)
		return (1);
	return (0);
}

void	*thread_track_died(void *args)
{
	t_data		*d;
	int			i;
	int long	time_philo;

	d = (t_data *) args;
	while (1)
	{
		i = 0;
		while (i < d->p)
		{
			if (ft_track_dinner(d, &i, &time_philo) == 1)
				return (NULL);
			if (time_philo >= d->d)
			{
				pthread_mutex_lock(&d->print);
				printf("%ld %d died\n", ft_get_timestamp() - d->start, i);
				pthread_mutex_unlock(&d->print);
				pthread_mutex_lock(&d->died_m);
				d->died = 1;
				pthread_mutex_unlock(&d->died_m);
				return (NULL);
			}
			i++;
		}
	}
	return (NULL);
}
