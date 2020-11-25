/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 14:34:00 by lmedusa           #+#    #+#             */
/*   Updated: 2020/11/25 14:34:02 by lmedusa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	parse_str(char *str, t_all *all)
{
	while (*str && *str == ' ')
		str++;
	if (*str != '1' && *str != '\0')
		ft_exit("Map is broken.", all);
}

int		ft_check_line(void *s)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] == '1' || str[i] == '0')
		return (1);
	return (0);
}

int		ft_is_valid(char c, char *valid)
{
	int		i;

	i = 0;
	while (valid[i])
	{
		if (c == valid[i])
			return (1);
		i++;
	}
	return (0);
}
