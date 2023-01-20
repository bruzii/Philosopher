/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgervais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:24:20 by bgervais          #+#    #+#             */
/*   Updated: 2022/11/08 16:33:27 by bgervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	k;

	i = 0;
	if (!haystack)
		return (NULL);
	if (!needle || !needle[0])
		return ((char *) haystack);
	while (haystack[i] && i < len)
	{
		k = 0;
		while (haystack[i + k] == needle[k] && (i + k) < len && haystack[i + k]
			&& needle[k])
		{
			k++;
			if (needle [k] == '\0')
			{
				return ((char *) &haystack[i]);
			}
		}
		i++;
	}
	return (NULL);
}
