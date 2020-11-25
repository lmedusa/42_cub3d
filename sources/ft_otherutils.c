/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_otherutils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 16:10:32 by lmedusa           #+#    #+#             */
/*   Updated: 2020/11/25 16:10:34 by lmedusa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_memcmp(const void *src, const void *src2, size_t n)
{
	int				res;
	size_t			i;
	unsigned char	*src_f;
	unsigned char	*src2_f;

	res = 0;
	i = 0;
	src_f = (unsigned char *)src;
	src2_f = (unsigned char *)src2;
	while (i < n)
	{
		if (src_f[i] != src2_f[i])
		{
			res = src_f[i] - src2_f[i];
			return (res);
		}
		i++;
	}
	return (res);
}

void	*ft_calloc(size_t num, size_t size)
{
	void *mem;

	if (!(mem = malloc(num * size)))
		return (NULL);
	ft_bzero(mem, size * num);
	return (mem);
}

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int			rez;
	size_t		i;

	i = 0;
	rez = 0;
	if (n == 0)
		return (0);
	while ((s1[i] != '\0') && (s2[i] != '\0') &&\
	(s1[i] == s2[i]) && (i != n - 1))
	{
		i++;
	}
	rez = (unsigned char)s1[i] - (unsigned char)s2[i];
	return (rez);
}

char	*ft_strnstr(const char *big, const char *small, size_t len)
{
	size_t	i;
	size_t	n;
	char	*big_f;

	big_f = (char *)big;
	i = 0;
	n = 0;
	if (*small == '\0')
		return ((char *)big);
	i = ft_strlen(small);
	while (big[n] && n + i <= len)
	{
		if (ft_strncmp(&big[n], small, i) == 0)
			return (&big_f[n]);
		n++;
	}
	return (NULL);
}
