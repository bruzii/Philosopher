/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgervais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:31:49 by bgervais          #+#    #+#             */
/*   Updated: 2023/01/20 17:13:42 by bgervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_parcing(char *str)
{
	int	n;
	int	i;

	i = 0;
	n = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}		
	n = ft_atoi(str);
	if (n <= 0)
		return (1);
	return (0);
}

int	ft_parcing_arg(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_parcing(argv[i]))
			return (1);
		if (i == 5 && ft_atoi(argv[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}
	
