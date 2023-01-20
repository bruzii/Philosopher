/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgervais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:11:19 by bgervais          #+#    #+#             */
/*   Updated: 2022/12/13 09:47:52 by bgervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len_base(const char *base, unsigned long nbr)
{
	int			count;
	int			len;

	count = 0;
	len = ft_strlen((char *)base);
	while (nbr != 0)
	{
		nbr /= len;
		count++;
	}
	return (count);
}

char	*ft_itoa_base(const char *base, unsigned long long nbr)
{
	int		len;
	int		len_base;
	char	*str;

	len = ft_len_base(base, nbr);
	len_base = ft_strlen((char *)base);
	str = ft_calloc((len + 1), sizeof(char));
	if (!str)
		return (0);
	while (len)
	{
		len--;
		str[len] = base[nbr % len_base];
		nbr /= len_base;
	}
	return (str);
}

int	ft_put_ptr(const char *base, void *data)
{
	char			*str;
	unsigned long	t;
	int				i;

	i = 0;
	t = (unsigned long) data;
	if (t == 0)
		i += ft_putstr2("(nil)");
	else
	{
		i += ft_putstr2("0x");
		str = ft_itoa_base(base, t);
		i += ft_putstr2(str);
		free (str);
	}
	return (i);
}
