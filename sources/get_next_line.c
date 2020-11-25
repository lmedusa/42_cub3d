/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 16:10:30 by lmedusa           #+#    #+#             */
/*   Updated: 2020/07/29 16:10:31 by lmedusa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*ft_new(size_t size)
{
	char	*str;

	if (size == (size_t)-1)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	ft_bzero(str, size);
	str[size] = '\0';
	return (str);
}

char	*ft_strchr(const char *str, int ch)
{
	int		i;
	char	*str_f;

	str_f = (char *)str;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ch)
			return (&str_f[i]);
		else
			i++;
	}
	if (ch == '\0')
		return (&str_f[i]);
	return (NULL);
}

void	ft_strdel(char **s)
{
	if (s != NULL)
	{
		free(*s);
		*s = NULL;
	}
}

int		proc_gnl(int fd, char **doc, char **line)
{
	t_gnl	v;

	ft_bzero(&v, sizeof(v));
	while (doc[fd][v.i] != '\n' && doc[fd][v.i] != '\0')
		v.i++;
	if (doc[fd][v.i] == '\n')
	{
		*line = ft_substr(doc[fd], 0, v.i);
		v.t = ft_strdup(doc[fd] + v.i + 1);
		free(doc[fd]);
		doc[fd] = v.t;
		if (doc[fd][0] == '\0')
			ft_strdel(&doc[fd]);
	}
	else if (doc[fd][v.i] == '\0')
	{
		*line = ft_strdup(doc[fd]);
		ft_strdel(&doc[fd]);
		return (0);
	}
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char		*doc[2000];
	t_gnl			v;

	ft_bzero(&v, sizeof(v));
	if (!(v.s = ft_new(BUFFER_SIZE + 1)) || fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	while ((v.r = read(fd, v.s, BUFFER_SIZE)) > 0)
	{
		v.s[v.r] = '\0';
		if (doc[fd] == NULL)
			doc[fd] = ft_new(1);
		v.t = ft_strjoin(doc[fd], v.s);
		free(doc[fd]);
		doc[fd] = v.t;
		if (ft_strchr(v.s, '\n'))
			break ;
	}
	free(v.s);
	if (v.r == 0 && doc[fd] == NULL)
	{
		*line = ft_strdup("\0");
		return (0);
	}
	return ((v.r < 0) ? (-1) : proc_gnl(fd, doc, line));
}
