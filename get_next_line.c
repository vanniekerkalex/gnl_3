/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 17:09:08 by avan-ni           #+#    #+#             */
/*   Updated: 2018/06/15 12:59:18 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_read_line(char *buf, char **l,
		const int fd, char *left[fd])
{
	char	*temp;

	temp = left[fd];
	left[fd] = ft_strjoin(temp, buf);
	if (ft_delchr(left[fd], '\n') >= 0)
	{
		*l = ft_strnew_del(left[fd], '\n');
		left[fd] = ft_strnew_delaft(ft_strjoin(temp, buf), '\n');
		ft_strdel(&temp);
		ft_strdel(&buf);
		return (1);
	}
	else if (ft_strlen(buf) == 0 && ft_strlen(left[fd]) != 0)
	{
		*l = ft_strdup(left[fd]);
		ft_strdel(&temp);
		ft_strdel(&left[fd]);
		ft_strdel(&buf);
		return (1);
	}
	else if (ft_strlen(buf) == 0 && ft_strlen(left[fd]) == 0)
		return (0);
	ft_strdel(&temp);
	return (2);
}

int			get_next_line(const int fd, char **l)
{
	char		*buf;
	int			size;
	int			res;
	static char	*left[52001];

	buf = ft_strnew(BUFF_SIZE);
	if (fd < 0 || l == NULL || buf == NULL || BUFF_SIZE < 1)
		return (-1);
	if (left[fd] == NULL)
		left[fd] = ft_strnew(0);
	while (1)
	{
		if ((size = read(fd, buf, BUFF_SIZE)) < 0)
			return (-1);
		*(buf + size) = '\0';
		res = ft_read_line(buf, l, fd, left);
		if (res != 2)
			return (res);
	}
}
