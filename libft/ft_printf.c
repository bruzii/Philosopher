/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgervais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:10:45 by bgervais          #+#    #+#             */
/*   Updated: 2022/11/10 15:14:29 by bgervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_arg(char c)
{
	char	*str;
	int		i;

	str = "csiduxXp%";
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_arg(const char format, va_list ap)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_putchar2(va_arg(ap, int));
	if (format == 's')
		len += ft_putstr2(va_arg(ap, char *));
	if (format == 'd' || format == 'i')
		len += ft_putnbr2(va_arg(ap, int));
	if (format == 'u')
		len += ft_putunbr2(va_arg(ap, unsigned int));
	if (format == 'x')
		len += ft_printhexa(va_arg(ap, int));
	if (format == 'X')
		len += ft_print_hexa(va_arg(ap, int));
	if (format == 'p')
		len += ft_put_ptr("0123456789abcdef", va_arg(ap, void *));
	if (format == '%')
		len += ft_print_percent();
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	int			valeur;
	int			i;

	i = 0;
	valeur = 0;
	va_start (ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			while (!ft_is_arg(format[i]))
				i++;
			valeur += ft_arg(format[i], ap);
		}
		else
			valeur += ft_putchar2(format[i]);
		i++;
	}
	va_end(ap);
	return (valeur);
}
