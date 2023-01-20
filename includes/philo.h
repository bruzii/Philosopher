/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgervais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 19:23:09 by bgervais          #+#    #+#             */
/*   Updated: 2023/01/20 16:30:41 by bgervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "../libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <string.h>
# include <errno.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_data	t_data;
typedef struct s_philo
{
	int				number;
	pthread_t		thread;
	char			state;
	int				out;
	long			timestamp;
	pthread_mutex_t	repas_m;
	pthread_mutex_t	time;
	int				dinner;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	t_data			*data;
}	t_philo;

typedef struct s_data
{
	int				p;
	int				e;
	int				s;
	int				d;
	int				died;
	int				dinner;
	int				fourchette;
	int				repas;
	long			start;
	pthread_mutex_t	dinner_m;
	pthread_mutex_t	died_m;
	pthread_mutex_t	print;
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_t		dd;
}	t_data;

void		*thread_track_died(void *args);
void		*thread_routine(void *args);
void		ft_usleep(long time);
void		ft_destroy_mutex(t_data *d);
void		ft_init(t_data *d);
int			ft_parcing(char *str);
int			ft_parcing_arg(char **argv);
int long	ft_get_timestamp(void);
int			ft_one_philo(t_philo *philo);
int			print(t_philo *philo, char *state);
int			ft_eat(t_philo *philo);
int			ft_go_eat_even(t_philo *philo);
int			ft_go_eat_odd(t_philo *philo);
int			ft_if_dinner_is_complete(t_philo *philo);
#endif
