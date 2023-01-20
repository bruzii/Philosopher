/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgervais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:25:06 by bgervais          #+#    #+#             */
/*   Updated: 2022/11/15 15:39:41 by bgervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_is_set(char t, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == t)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		len;
	int		size;
	char	*str;

	i = 0;
	if (!s1)
		return (NULL);
	size = 0;
	len = (int)ft_strlen(s1) - 1;
	while (s1[i] && (ft_is_set(s1[i], set) == 1))
		i++;
	while (ft_is_set(s1[len], set) == 1)
			len--;
		size = len - i + 1;
	if (size < 0)
		size = 0;
	str = (char *)malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	size = 0;
	while (i <= len)
		str[size++] = s1[i++];
	str[size] = '\0';
	return (str);
}
