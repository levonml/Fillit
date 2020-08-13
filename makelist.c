/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makelist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvlassen <dvlassen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 13:58:38 by dvlassen          #+#    #+#             */
/*   Updated: 2020/08/14 00:35:13 by lstepany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetramino	*align(t_tetramino *tetramino)
{
	int		c;

	c = -1;
	while (tetramino->coordinates[0] != 0 && tetramino->coordinates[2] != 0 && \
		   tetramino->coordinates[4] != 0 && tetramino->coordinates[6] != 0)
		{
		tetramino->coordinates[0] += c;
		tetramino->coordinates[2] += c;
		tetramino->coordinates[4] += c;
		tetramino->coordinates[6] += c;
		//tetramino->coordinates[0]--;
	}
	while (tetramino->coordinates[1] != 0 && tetramino->coordinates[3] != 0 && \
		tetramino->coordinates[5] != 0 && tetramino->coordinates[7] != 0) // isn't it enough just to check tetrimino->coordinate[1] != 0 ???
	{
		tetramino->coordinates[1] += c;
		tetramino->coordinates[3] += c;
		tetramino->coordinates[5] += c;
		tetramino->coordinates[7] += c;
	}
	return (tetramino);
}

t_tetramino	*ft_tetramino(char *buf, char alphabet)
{
	t_tetramino	*tetramino;
	int			x;
	int			y;
	int			c;

	c = 0;
	x = 0;
	y = 1;
	if (!(tetramino = (t_tetramino*)malloc(sizeof(t_tetramino))))
		return (NULL);
	while (c < 19)
	{
		if (buf[c] == '#')
		{
			tetramino->coordinates[x] = (c >= 5) ? (c % 5) : c;
			tetramino->coordinates[y] = c / 5;
			x = x + 2;
			y = y + 2;
		}
		c++;
	}
	tetramino->alphabet = alphabet;
	return (align(tetramino));
}

t_tetramino	*makelist(char *buf, int filesize)
{
	t_tetramino	*head;
	t_tetramino	*tmp;
	char		alphabet;
	int			c;

	c = 0;
	alphabet = 'A';
	while (c < filesize)
	{
		if (alphabet == 'A')
		{
			head = ft_tetramino(buf + c, alphabet);
			tmp = head;
		}
		else
		{
			tmp->next = ft_tetramino(buf + c, alphabet);
			tmp = tmp->next;
		}
		alphabet++;
		c = c + 21;
	}
	tmp->next = NULL;
	return (head);
}
