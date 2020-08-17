#include "fillit.h"
void ft_print(char **map, int length)
{
  int x;
  int y;

  y = 0;
  while (y < length)
    {
      x = 0;
      while(x < length)
	{
	  map[y][x] = '.';
	  ft_putchar(map[y][x]);
	  x++;
	}
      ft_putchar('\n');
      y++;
    }
  
}

int ft_map(t_tetrimino *head)
{
  char **map;
  int length;
  int surface;
  int listnum;
  t_tetrimino *temp;
  int i;
  temp = head;
  listnum = 0;
  while(temp)
    {
      listnum++;
      temp = temp->next;
    }
  surface = 4 * listnum;
  length = 0;
  while(length * length <= surface)
    length++;
  if(!(map = (char **)malloc(sizeof(char *) * length)))
    return(1);
  i = 0;
  while(i < length)
    {
      if(!(map[i] = (char *)malloc(sizeof(char) * length)))
	return (1);
      i++;
    }
  ft_print(map, length);
  return (0);
}
