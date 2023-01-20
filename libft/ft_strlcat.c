/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgervais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 10:45:23 by bgervais          #+#    #+#             */
/*   Updated: 2022/11/15 15:40:56 by bgervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	dl;
	unsigned int	sl;

	sl = ft_strlen(src);
	dl = ft_strlen(dest);
	i = 0;
	if (size < 1)
		return (sl + size);
	dest += dl;
	while (src[i] && i + dl < size - 1)
	{
		dest[i] = src[i];
			i++;
	}
	dest[i] = '\0';
	if (size < dl)
		return (sl + size);
	else
		return (dl + sl);
}
