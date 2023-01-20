/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgervais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:24:49 by bgervais          #+#    #+#             */
/*   Updated: 2022/11/15 16:58:07 by bgervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_separateur(char str, char c)
{
	if (str == c)
		return (1);
	return (0);
}

static int	ft_count_words(char	const *str, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && ft_separateur(str[i], c) == 1)
			i++;
		if (str[i] && ft_separateur(str[i], c) == 0)
			count++;
		while (str[i] && ft_separateur(str[i], c) == 0)
			i++;
	}
	return (count);
}

static char	*ft_strndup(char const *str, int b, int t)
{
	int		i;
	char	*new;

	i = 0;
	new = (char *)malloc(sizeof(char) * ((t - b) + 1));
	if (!new)
		return (0);
	while (b < t)
		new[i++] = str[b++];
	new[i] = '\0';
	return (new);
}

static	char	**ft_clean(char **strs, int i)
{
	while (i >= 0)
		free (strs[i--]);
	free (strs);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		b;
	char	**strs;
	int		k;
	int		size;

	i = 0;
	k = 0;
	size = ft_count_words(s, c);
	strs = (char **)malloc(sizeof(char *) *(size + 1));
	if (!strs)
		return (0);
	while (i < size)
	{
		while (s[k] && ft_separateur(s[k], c) == 1)
			k++;
		b = k;
		while (s[k] && ft_separateur(s[k], c) == 0)
			k++;
		strs[i++] = ft_strndup(s, b, k);
		if (!strs[i - 1])
			return (ft_clean(strs, i - 2));
	}
	strs[i] = NULL;
	return (strs);
}
