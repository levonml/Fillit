/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_lists.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvlassen <dvlassen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 18:03:51 by dvlassen          #+#    #+#             */
/*   Updated: 2020/08/03 17:16:47 by dvlassen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_map(t_map *map, int mapsize)
{
	int		c;

	c = 0;
	while (c < mapsize)
	{
		ft_memdel((void **)&(map->array[c]));
		c++;
	}
	ft_memdel((void **)&(map->array));
	ft_memdel((void **)&map);
}

void	free_tetramino(t_tetramino *head)
{
	t_tetramino *tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
