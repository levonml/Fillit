#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 546
# include <fcntl.h>
# include <unistd.h>
# include "libft.h"
# include <stdlib.h>
# include <stdio.h>
typedef struct	s_tetrimino
{
  int			coordinates[8];
  char			letter;
  struct s_tetrimino	*next;
}		t_tetrimino;
t_tetrimino	*ft_coordinates(char **buf);
//int		list_count(char **buf);
int ft_map(t_tetrimino *head);
#endif
