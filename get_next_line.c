/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbxaba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 12:06:49 by sbxaba            #+#    #+#             */
/*   Updated: 2018/07/02 15:09:32 by sbxaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int			ft_check_line(char **str, char **line, int fd)
{
	char			*temp;
	int				len;

	len = 0;
	while (str[fd][len] != '\n' && str[fd][len] != '\0')
		len++;
	if (str[fd][len] == '\n')
	{
		*line = ft_strsub(str[fd], 0, len);
		temp = ft_strdup(str[fd] + len + 1);
		free(str[fd]);
		str[fd] = temp;
		if (str[fd][0] == '\0')
			ft_strdel(&str[fd]);
	}
	else if (str[fd][len] == '\0')
	{
		if (len == 0)
			return (0);
		*line = ft_strdup(str[fd]);
		ft_strdel(&str[fd]);
	}
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	static char		*str[255];
	char			buf[BUFF_SIZE + 1];
	char			*temp;
	int				res;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((res = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[res] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strnew(0);
		temp = ft_strjoin(str[fd], buf);
		free(str[fd]);
		str[fd] = temp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (res < 0)
		return (-1);
	else if (res == 0 && (str[fd] == NULL || str[fd][0] == '\0'))
		return (0);
	return (ft_check_line(str, line, fd));
}
