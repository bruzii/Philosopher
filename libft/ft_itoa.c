/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgervais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:07:17 by bgervais          #+#    #+#             */
/*   Updated: 2022/12/05 15:19:26 by bgervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count(unsigned int n)
{
	int			count;
	int long	nbr;

	count = 0;
	nbr = (int long) n;
	if (nbr < 0)
	{
		nbr = -nbr;
		count++;
	}
	if (nbr == 0)
	{
		count++;
		return (count);
	}
	while (nbr > 0)
	{
		count++;
		nbr /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int			i;
	char		*nbr;
	int			size;
	int long	nb;

	size = ft_count(n);
	nb = (int long) n;
	i = 0;
	nbr = (char *)malloc(sizeof(char) * (size + 1));
	if (!nbr)
		return (0);
	nbr[size--] = '\0';
	if (nb < 0)
	{
		nb = -nb;
		nbr[0] = '-';
		i = 1;
	}
	while (size >= i)
	{
		nbr[size--] = nb % 10 + '0';
		nb /= 10;
	}
	return (nbr);
}
