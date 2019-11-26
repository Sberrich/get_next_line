/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sberrich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 17:59:32 by sberrich          #+#    #+#             */
/*   Updated: 2019/11/18 20:22:34 by sberrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	char	*ft_newline(char *s, char **line)
{
	char	*tmp;
	int		i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	*line = ft_strsub(s, 0, i);
	if (s[i] == '\n')
		tmp = ft_strdup(&s[i] + 1);
	if (!s[i])
		tmp = ft_strnew(0);
	return (tmp);
}

int				get_next_line(const int fd, char **line)
{
	static char		*str[FD_MAX];
	char			*tmp;
	int				ret;
	char			buff[BUFF_SIZE + 1];

	if (fd < 0 || !line || (read(fd, buff, 0) < 0) || BUFF_SIZE < 0)
		return (-1);
	if (!str[fd])
		str[fd] = ft_strnew(0);
	while (!ft_strchr(str[fd], '\n') && (ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		tmp = ft_strjoin(str[fd], buff);
		free(str[fd]);
		str[fd] = tmp;
	}
	if (ret < 0)
		return (-1);
	if (ret == 0 && !ft_strlen(str[fd]))
		return (0);
	tmp = ft_newline(str[fd], line);
	free(str[fd]);
	str[fd] = tmp;
	return (1);
}
