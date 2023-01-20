/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgervais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 04:52:31 by bgervais          #+#    #+#             */
/*   Updated: 2023/01/19 17:21:11 by bgervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_one_philo(t_philo *philo)
{
	pthread_mutex_lock(philo -> left);
	if (print(philo, "has taken a fork\n"))
	{
		pthread_mutex_unlock(philo->left);
		return (1);
	}
	pthread_mutex_unlock(philo->left);
	ft_usleep(philo->data->e);
	return (1);
}

int	ft_go_eat_even(t_philo *philo)
{
	pthread_mutex_lock(philo -> left);
	if (print(philo, "has taken a fork\n"))
	{
		pthread_mutex_unlock(philo->left);
		return (1);
	}
	pthread_mutex_lock(philo -> right);
	if (print(philo, "has taken a fork\n"))
	{
		pthread_mutex_unlock(philo->left);
		pthread_mutex_unlock(philo->right);
		return (1);
	}
	return (0);
}

int	ft_go_eat_odd(t_philo *philo)
{
	pthread_mutex_lock(philo -> right);
	if (print(philo, "has taken a fork\n"))
	{
		pthread_mutex_unlock(philo->right);
		return (1);
	}
	pthread_mutex_lock(philo -> left);
	if (print(philo, "has taken a fork\n"))
	{
		pthread_mutex_unlock(philo->left);
		pthread_mutex_unlock(philo->right);
		return (1);
	}
	return (0);
}

int	ft_if_dinner_is_complete(t_philo *philo)
{
	if (philo->dinner == philo->data->dinner)
	{
		pthread_mutex_lock(&philo->data->dinner_m);
		philo->data->repas--;
		pthread_mutex_unlock(&philo->data->dinner_m);
		philo->out = 1;
		return (1);
	}
	if (print(philo, "is sleeping\n"))
		return (1);
	ft_usleep(philo->data->s);
	if (print(philo, "is thinking\n"))
		return (1);
	return (0);
}
