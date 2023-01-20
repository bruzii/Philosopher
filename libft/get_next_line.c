/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgervais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:43:43 by bgervais          #+#    #+#             */
/*   Updated: 2022/12/23 19:59:32 by bgervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_add(char *str, char *s)
{
	int		t;
	int		i;

	t = 0;
	i = 0;
	while (str[i])
		i++;
	while (s[t])
		str[i++] = s[t++];
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin_bis(char *s1, char *s2)
{
	int		i;
	int		size;
	char	*str;

	if (!s1)
		size = ft_strlen_bis(s2);
	else
		size = ft_strlen_bis(s2) + ft_strlen_bis(s1);
	i = 0;
	str = (char *)ft_calloc_bis((size + 1), sizeof(char));
	if (!str)
		return (0);
	if (size > ft_strlen_bis(s2))
	{
		while (s1[i])
		{
			str[i] = s1[i];
			i++;
		}
	}
	free (s1);
	str = ft_add(str, s2);
	return (str);
}

char	*get_line(char *str)
{
	int		i;
	int		k;
	char	*buff;

	i = 0;
	k = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	buff = (char *)ft_calloc_bis((i + 1), sizeof(char));
	if (buff == NULL)
		return (NULL);
	while (k < i)
	{
		buff[k] = str[k];
		k++;
	}
	return (buff);
}

char	*ft_prox_nl(char *str)
{
	int		res;
	int		i;
	int		len;
	char	*new;

	i = 0;
	if (!str)
		return (NULL);
	len = ft_strlen(str);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	if (str[i] == '\0')
		return (free(str), NULL);
	res = len - i;
	new = (char *)ft_calloc_bis((res + 1), sizeof(char));
	if (!new)
		return (NULL);
	len = 0;
	while (str[i])
		new[len++] = str[i++];
	new[len] = '\0';
	return (free(str), new);
}

char	*get_next_line(int fd)
{
	int				ret;
	static char		*str;
	char			*new;
	static char		buff[2];

	ret = 1;
	if (fd < 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	while (ret > 0)
	{	
		ret = read(fd, buff, 2);
		if (ret < 0 || (ret == 0 && !str))
			return (NULL);
		buff[ret] = '\0';
		str = ft_strjoin_bis(str, buff);
		if (!str)
			return (NULL);
		if (ft_strstr(str, '\n'))
			break ;
	}
	new = get_line(str);
	str = ft_prox_nl(str);
	return (new);
}
