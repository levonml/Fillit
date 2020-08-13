/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvlassen <dvlassen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 21:42:57 by dvlassen          #+#    #+#             */
/*   Updated: 2020/08/03 17:45:21 by dvlassen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_charcount(char *buf)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (i < 19)
	{
		if (buf[i] && buf[i] != '\n' && buf[i] != '#' && buf[i] != '.')
			return (0);
		if (buf[i] == '\n' && !(((i + 1) % 5) == 0))
			return (0);
		if (buf[i] == '#')
			count++;
		i++;
	}
	if (buf[i] != '\n' || !buf[i])
		return (0);
	return (count);
}

int		ft_valid_tetramino(char *buf)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (i < 19)
	{
		if (buf[i] == '#')
		{
			if (i + 1 <= 18 && buf[i + 1] == '#')
				count++;
			if (i - 1 >= 0 && buf[i - 1] == '#')
				count++;
			if (i + 5 <= 18 && buf[i + 5] == '#')
				count++;
			if (i - 5 >= 0 && buf[i - 5] == '#')
				count++;
		}
		i++;
	}
	return (count);
}

int		ft_valid(char *buf, int size)
{
	int		i;

	i = 0;
	while (i <= size)
	{
		if (ft_charcount(buf + i) != 4)
			return (0);
		if (ft_valid_tetramino(buf + i) != 6 && \
			ft_valid_tetramino(buf + i) != 8)
			return (0);
		i += 21;
	}
	return (1);
}

int		ft_validator(char *buf, int filesize)
{
	if (filesize < 19 || filesize > SIZE)
		return (0);
	if (!ft_valid(buf, filesize))
		return (0);
	return (1);
}
