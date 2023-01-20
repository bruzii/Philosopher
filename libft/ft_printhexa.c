/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgervais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:11:03 by bgervais          #+#    #+#             */
/*   Updated: 2022/11/10 16:46:36 by bgervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <unistd.h>
//#include <stdlib.h>

int	ft_count(unsigned int nbr)
{
	int	count;

	count = 0;
	if (nbr == 0)
		count++;
	while (nbr != 0)
	{
		count++;
		nbr /= 16;
	}
	return (count);
}

void	ft_puthexa(unsigned int nbr)
{
	char	*base;
	char	*res;
	int		i;
	int		len;

	i = 0;
	base = "0123456789abcdef";
	len = ft_count(nbr);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return ;
	res[len--] = '\0';
	while (len >= i)
	{
		res[len] = base[nbr % 16];
		nbr /= 16;
		len--;
	}
	ft_putstr(res);
	free(res);
}

void	ft_put_hexa(unsigned int nbr)
{
	char	*base;
	char	*res;
	int		i;
	int		len;

	i = 0;
	base = "0123456789ABCDEF";
	len = ft_count(nbr);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return ;
	res[len--] = '\0';
	while (len >= i)
	{
		res[len] = base[nbr % 16];
		nbr /= 16;
		len--;
	}
	ft_putstr(res);
	free(res);
}

int	ft_printhexa(unsigned int nbr)
{
	int	len;

	len = ft_count(nbr);
	ft_puthexa(nbr);
	return (len);
}

int	ft_print_hexa(unsigned int nbr)
{
	int	len;

	len = ft_count(nbr);
	ft_put_hexa(nbr);
	return (len);
}	
/*
int	main(void)
{
	printf("%d\n", ft_printhexa(0));
	printf("%d\n", ft_print_hexa(0));
	return (0);
}
*/
