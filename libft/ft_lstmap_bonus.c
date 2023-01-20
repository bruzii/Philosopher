/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgervais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:29:42 by bgervais          #+#    #+#             */
/*   Updated: 2022/12/23 19:59:57 by bgervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*init_elem;
	t_list	*src_elem;
	t_list	*dest_elem;

	if (!lst)
		return (NULL);
	init_elem = ft_lstnew(f((void *)lst->content));
	if (!init_elem)
		return (NULL);
	src_elem = lst->next;
	while (src_elem)
	{
		dest_elem = ft_lstnew(f(src_elem->content));
		if (!src_elem)
		{
			ft_lstclear(&init_elem, del);
			return (NULL);
		}
		ft_lstadd_back(&init_elem, dest_elem);
		src_elem = src_elem->next;
	}
	return (init_elem);
}
