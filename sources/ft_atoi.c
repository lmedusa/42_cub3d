/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 15:51:10 by lmedusa           #+#    #+#             */
/*   Updated: 2020/11/25 15:51:12 by lmedusa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_check(char s)
{
	if (s == ' ' || s == '\t' || s == '\n' || s == '\v')
		return (1);
	else if (s == '\f' || s == '\r')
		return (1);
	return (0);
}

char	*ft_spc(char *s)
{
	int			i;

	i = 0;
	while (s[i] != '\0')
	{
		if (ft_check(s[i]) == 1)
			i++;
		else if (s[i] == '+' || s[i] == '-')
		{
			if (s[i + 1] <= '9' && s[i + 1] >= '0')
				i++;
			else
				break ;
		}
		else if (s[i] >= '0' && s[i] <= '9')
		{
			if (s[i - 1] == '-')
				return (&s[i - 1]);
			return (&s[i]);
		}
		else
			break ;
	}
	return (s);
}

int		ft_atoi(const char *str)
{
	int			i;
	char		*src;

	i = 0;
	src = (char *)str;
	src = ft_spc(src);
	if (*src == '-')
	{
		src++;
		while (*src && *src >= '0' && *src <= '9')
		{
			i = i * 10 + (*src - '0');
			src++;
		}
		return (i * -1);
	}
	while (*src && *src >= '0' && *src <= '9')
	{
		i = i * 10 + (*src - '0');
		src++;
	}
	return (i);
}
