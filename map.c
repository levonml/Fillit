/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvlassen <dvlassen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 14:48:15 by dvlassen          #+#    #+#             */
/*   Updated: 2020/08/03 20:10:07 by dvlassen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_lists_counter(t_tetramino *head)
{
	int		c;

	c = 0;
	while (head)
	{
		head = head->next;
		c++;
	}
	return (c);
}

int		ft_mapsize(int tetrapieces)
{
	int		size;

	size = 2;
	while (size * size < tetrapieces)
		size++;
	return (size);
}

t_map	*ft_map(int mapsize)
{
	t_map	*map;
	int		c;

	c = 0;
	map = (t_map *)ft_memalloc(sizeof(t_map));
	map->array = (char**)ft_memalloc(sizeof(char*) * mapsize);
	while (c < mapsize)
	{
		map->array[c] = ft_strnew(mapsize);
		ft_memset(map->array[c], '.', mapsize);
		c++;
	}
	return (map);
}

void	print_map(t_map *map, int size)
{
	int		c;

	c = 0;
	while (c < size)
	{
		ft_putstr(map->array[c]);
		ft_putchar('\n');
		c++;
	}
}
