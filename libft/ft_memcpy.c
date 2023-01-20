/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgervais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:09:11 by bgervais          #+#    #+#             */
/*   Updated: 2022/11/07 17:26:19 by bgervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dst_bis;
	const char	*src_bis;

	src_bis = (const char *) src;
	dst_bis = (char *) dst;
	if (dst == src || n == 0)
		return (dst);
	if (!dst && !src)
		return (NULL);
	while (n > 0)
	{
		*dst_bis++ = *src_bis++;
		n--;
	}
	return (dst);
}
