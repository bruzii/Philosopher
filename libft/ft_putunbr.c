/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgervais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:11:53 by bgervais          #+#    #+#             */
/*   Updated: 2022/11/18 11:17:19 by bgervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putunbr(unsigned int nbr)
{
	char	res;

	if (nbr > 9)
		ft_putunbr(nbr / 10);
	res = nbr % 10 + '0';
	write (1, &res, 1);
}

int	ft_putunbr2(unsigned int nbr)
{
	int	len;

	len = 0;
	ft_putunbr(nbr);
	if (nbr == 0)
		len++;
	while (nbr != 0)
	{
		nbr /= 10;
		len ++;
	}
	return (len);
}
