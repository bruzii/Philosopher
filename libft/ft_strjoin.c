/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgervais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:22:21 by bgervais          #+#    #+#             */
/*   Updated: 2023/01/03 12:41:40 by bgervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		len;
	int		k;

	len = ft_strlen((char *)(s1)) + ft_strlen(s2) + 2;
	i = 0;
	str = (char *)malloc(sizeof(char) * len);
	if (!str)
		return (0);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i++] = '/';
	k = i;
	i = 0;
	while (s2[i])
		str[k++] = s2[i++];
	str[k] = '\0';
	return (str);
}
