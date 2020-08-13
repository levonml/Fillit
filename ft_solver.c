/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvlassen <dvlassen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 18:22:53 by dvlassen          #+#    #+#             */
/*   Updated: 2020/08/04 15:39:11 by dvlassen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_solver(t_map *map, t_tetramino *head, int mapsize)
{
	if (!head)
		return (1);
	head->x_line = 0;
	head->y_line = 0;
	while (ft_borders(head, mapsize, 'y'))
	{
		while (ft_borders(head, mapsize, 'x'))
		{
			if (!overlap(map, head))
			{
				place(head, map, head->alphabet);
				if (ft_solver(map, head->next, mapsize))
					return (1);
				else
					place(head, map, '.');
			}
			head->x_line++;
		}
		head->x_line = 0;
		head->y_line++;
	}
	return (0);
}

int		ft_borders(t_tetramino *head, int mapsize, char axis)
{
	if (axis == 'y')
	{
		return (head->coordinates[1] + head->y_line < mapsize && \
			head->coordinates[3] + head->y_line < mapsize && \
			head->coordinates[5] + head->y_line < mapsize && \
			head->coordinates[7] + head->y_line < mapsize);
	}
	else
		return (head->coordinates[0] + head->x_line < mapsize && \
			head->coordinates[2] + head->x_line < mapsize && \
			head->coordinates[4] + head->x_line < mapsize && \
			head->coordinates[6] + head->x_line < mapsize);
}

int		overlap(t_map *map, t_tetramino *head)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	x = 0;
	y = 0;
	x = head->coordinates[i] + head->x_line;
	y = head->coordinates[i + 1] + head->y_line;
	while (i <= 6 && map->array[y][x] == '.')
	{
		i = i + 2;
		x = head->coordinates[i] + head->x_line;
		y = head->coordinates[i + 1] + head->y_line;
	}
	return (i != 8);
}

void	place(t_tetramino *head, t_map *map, char letter)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	x = 0;
	y = 0;
	while (i <= 6)
	{
		x = head->coordinates[i] + head->x_line;
		y = head->coordinates[i + 1] + head->y_line;
		map->array[y][x] = letter;
		i = i + 2;
	}
}
