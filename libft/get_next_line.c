/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvlassen <dvlassen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 11:51:44 by dvlassen          #+#    #+#             */
/*   Updated: 2020/07/09 20:02:49 by dvlassen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_line		*newlist(const int fd)
{
	t_line	*new;

	if (!(new = (t_line *)malloc(sizeof(t_line))))
		return (NULL);
	new->fd = fd;
	new->rest = ft_strnew(BUFF_SIZE);
	new->next = NULL;
	return (new);
}

char		*checkrest(char **newline, char *rest)
{
	char *str;

	if ((*newline = ft_strchr(rest, '\n')) != NULL)
	{
		str = ft_strsub(rest, 0, *newline - rest);
		ft_strcpy(rest, ++(*newline));
	}
	else
	{
		str = ft_strnew(ft_strlen(rest) + 1);
		ft_strcat(str, rest);
		ft_strclr(rest);
	}
	return (str);
}

int			get_line(const int fd, char **line, char *rest)
{
	char			buf[BUFF_SIZE + 1];
	char			*newline;
	char			*tmp;
	int				rd;

	newline = NULL;
	rd = 1;
	*line = checkrest(&newline, rest);
	while (newline == 0 && ((rd = read(fd, buf, BUFF_SIZE)) != 0))
	{
		buf[rd] = '\0';
		if ((newline = ft_strchr(buf, '\n')) != NULL)
		{
			ft_strcpy(rest, ++newline);
			ft_strclr(--newline);
		}
		tmp = *line;
		if (!(*line = ft_strjoin(tmp, buf)) || rd < 0)
			return (-1);
		ft_strdel(&tmp);
	}
	return ((ft_strlen(*line) || ft_strlen(rest) || rd) ? 1 : 0);
}

int			get_next_line(const int fd, char **line)
{
	static t_line	*list;
	t_line			*tmp;
	int				ret;

	if (fd < 0 || line == 0)
		return (-1);
	if (!list)
		list = newlist(fd);
	tmp = list;
	while (tmp->fd != fd)
	{
		if (tmp->next == NULL)
			tmp->next = newlist(fd);
		tmp = tmp->next;
	}
	ret = get_line(fd, line, tmp->rest);
	return (ret);
}
