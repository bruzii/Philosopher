/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgervais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:30:37 by bgervais          #+#    #+#             */
/*   Updated: 2023/01/20 16:34:57 by bgervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_recup_arg(int argc, char **argv, t_data *d)
{
	if (ft_parcing_arg(argv))
		return (0);
	if (argc == 5 || argc == 6)
	{
		d->p = ft_atoi(argv[1]);
		d->d = ft_atoi(argv[2]);
		d->e = ft_atoi(argv[3]);
		d->s = ft_atoi(argv[4]);
		d->start = ft_get_timestamp();
		if (argc == 6)
			d->dinner = ft_atoi(argv[5]);
	}
	else
		return (0);
	d->philo = malloc(sizeof(t_philo) * d->p);
	if (!d->philo)
		return (0);
	d->forks = calloc(sizeof(pthread_mutex_t), d->p);
	if (!d->forks)
	{
		free (d->philo);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	d;
	int		i;

	i = 0;
	memset(&d, 0, sizeof(t_data));
	if (!ft_recup_arg(argc, argv, &d))
		return (0);
	ft_init(&d);
	while (i < d.p)
	{
		pthread_create(&d.philo[i].thread, NULL, thread_routine, &d.philo[i]);
		i++;
	}
	pthread_create(&d.dd, NULL, thread_track_died, &d);
	i = 0;
	while (i < d.p)
	{
		pthread_join(d.philo[i].thread, NULL);
		i++;
	}
	pthread_join(d.dd, NULL);
	ft_destroy_mutex(&d);
	free (d.philo);
	free (d.forks);
	return (0);
}
