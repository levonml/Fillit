/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvlassen <dvlassen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 20:56:30 by dvlassen          #+#    #+#             */
/*   Updated: 2020/07/19 21:26:12 by dvlassen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	fillit(char *buf, int filesize)
{
	t_tetramino		*head;
	t_map			*map;
	int				mapsize;
	int				tetrapieces;

	head = makelist(buf, filesize);
	tetrapieces = ft_lists_counter(head) * 4;
	mapsize = ft_mapsize(tetrapieces);
	map = ft_map(mapsize);
	while (!ft_solver(map, head, mapsize))
	{
		free_map(map, mapsize);
		mapsize++;
		map = ft_map(mapsize);
	}
	print_map(map, mapsize);
	free_map(map, mapsize);
	free_tetramino(head);
}

int		main(int argc, char **argv)
{
	char	buf[SIZE + 1];
	int		fd;
	int		filesize;

	fd = open(argv[1], O_RDONLY);
	filesize = read(fd, buf, SIZE);
	buf[filesize] = '\0';
	close(fd);
	if (argc != 2)
	{
		ft_putstr("usage: ./fillit tetramino_file\n");
		return (0);
	}
	if (!(ft_validator(buf, filesize)))
	{
		ft_putstr("error\n");
		return (0);
	}
	fillit(buf, filesize);
	return (0);
}
