/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvlassen <dvlassen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 21:34:08 by dvlassen          #+#    #+#             */
/*   Updated: 2020/08/04 15:37:43 by dvlassen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include "libft/libft.h"
# include <fcntl.h>
# define SIZE 546

typedef struct			s_tetramino
{
	int					coordinates[8];
	int					x_line;
	int					y_line;
	char				alphabet;
	struct s_tetramino	*next;
}						t_tetramino;

typedef struct			s_map
{
	char				**array;
}						t_map;

int						ft_validator(char *buf, int filesize);
t_tetramino				*makelist(char *buf, int filesize);
int						ft_lists_counter(t_tetramino *head);
t_map					*ft_map(int mapsize);
int						ft_mapsize(int tetrapieces);
int						ft_solver(t_map *map, t_tetramino *head, int mapsize);
int						ft_mapsize(int tetrapieces);
void					print_map(t_map *map, int size);
void					free_map(t_map *map, int mapsize);
int						ft_borders(t_tetramino *head, int mapsize, char axis);
int						overlap(t_map *map, t_tetramino *head);
void					place(t_tetramino *head, t_map *map, char letter);
void					free_tetramino(t_tetramino *head);

#endif
