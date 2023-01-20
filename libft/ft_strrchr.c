/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgervais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:24:41 by bgervais          #+#    #+#             */
/*   Updated: 2022/11/07 18:43:15 by bgervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			cc;
	int				len;

	cc = (char) c;
	len = ft_strlen(s);
	while (len >= 0)
	{
		if (s[len] == cc)
			return ((char *)&s[len]);
		len--;
	}
	return (NULL);
}
