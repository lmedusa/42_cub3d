/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 21:27:07 by lmedusa           #+#    #+#             */
/*   Updated: 2020/11/23 21:27:09 by lmedusa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_clear(int i, char **mas)
{
	while (i >= 0)
	{
		ft_strdel(&mas[i]);
		i--;
	}
}

int		ft_isdigit(int dig)
{
	if (dig >= '0' && dig <= '9')
		return (1);
	else
		return (0);
}

void	ft_putendl(char *s)
{
	int i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

char	*ft_strnew(size_t size)
{
	char *str;

	if (size == (size_t)-1)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	ft_bzero(str, size);
	str[size] = '\0';
	return (str);
}

void	*ft_memset(void *src, int c, size_t len)
{
	size_t			i;
	unsigned char	*srcx;

	srcx = (unsigned char *)src;
	i = 0;
	if (len == 0)
		return (src);
	while (i < len)
	{
		srcx[i] = c;
		i++;
	}
	return (src);
}
