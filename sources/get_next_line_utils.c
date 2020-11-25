/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 18:06:39 by lmedusa           #+#    #+#             */
/*   Updated: 2020/07/29 18:06:53 by lmedusa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

size_t	ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_bzero(void *str, size_t len)
{
	int				i;
	int				max;
	unsigned char	*src;

	max = (int)len;
	src = (unsigned char *)str;
	i = 0;
	while (i <= max - 1)
	{
		src[i] = 0;
		i++;
	}
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;
	size_t	j;

	j = 0;
	i = start;
	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
	{
		if (!(res = (char *)malloc(sizeof(char))))
			return (NULL);
		res[0] = '\0';
		return (res);
	}
	if (!(res = ft_new(len)))
		return (NULL);
	while (len-- && s[i] != '\0')
	{
		res[j] = s[i];
		i++;
		j++;
	}
	return (res);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s;
	int		i;
	int		j;

	s = NULL;
	if (!s1 || !s2)
		return (NULL);
	if ((s = malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
	{
		i = 0;
		j = 0;
		while (s1[i])
		{
			s[i] = s1[i];
			i++;
		}
		while (s2[j])
		{
			s[i + j] = s2[j];
			j++;
		}
		s[i + j] = '\0';
	}
	return (s);
}

char	*ft_strdup(const char *s)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = NULL;
	if (!s)
		return (NULL);
	if ((tmp = (char *)malloc(ft_strlen(s) + 1)))
	{
		while (s[i])
		{
			tmp[i] = s[i];
			i++;
		}
		tmp[i] = '\0';
	}
	return (tmp);
}
