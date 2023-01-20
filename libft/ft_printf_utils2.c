/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgervais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:09:24 by bgervais          #+#    #+#             */
/*   Updated: 2022/11/18 11:20:44 by bgervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar2(const char c)
{
	write (1, &c, 1);
	return (1);
}

void	ft_putnbr(int nbr)
{
	char		res;
	int long	nb;

	nb = (int long) nbr;
	if (nb < 0)
	{
		nb = -nb;
		write (1, "-", 1);
	}
	if (nb > 9)
		ft_putnbr(nb / 10);
	res = nb % 10 + '0';
	write (1, &res, 1);
}

int	ft_putnbr2(int nbr)
{
	int long	nb;
	int			len;

	len = 0;
	nb = (int long) nbr;
	if (nbr < 0)
	{
		len++;
		nb = -nb;
	}
	if (nbr == 0)
		len++;
	ft_putnbr(nbr);
	while (nb != 0)
	{
		len++;
		nb = nb / 10;
	}
	return (len);
}
