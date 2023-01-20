/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgervais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:05:30 by bgervais          #+#    #+#             */
/*   Updated: 2022/11/15 16:25:01 by bgervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*content;

	if (nmemb && (nmemb * size) / nmemb != size)
		return (NULL);
	content = malloc((nmemb * size));
	if (!content)
		return (NULL);
	ft_memset(content, 0, (nmemb * size));
	return (content);
}
