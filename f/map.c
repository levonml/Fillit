#include "fillit.h"
/*void ft_print(char **map, int length)
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
  
}*/

char **ft_create_map(int length)
{
    int i;
    char **map;
    i = 0;
    if(!(map = (char **)malloc(sizeof(char *) * length)))
        return(NULL);
    i = 0;
    while(i < length)
    {
        if(!(map[i] = (char *)malloc(sizeof(char) * length)))
            return (NULL);
        i++;
    }
    return(map);
}

int ft_solve(char **map, t_tetrimino *head, int length)
{
	return(0);
}

int ft_map(t_tetrimino *head)
{
	char **map;
	int length;
	int surface;
	int listnum;
	t_tetrimino *temp;

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
	map = ft_create_map(length);
//	ft_print(map, length);
	while(ft_solve(map, head, length))
	{
		ft_free_map(map);//will free the previouse map
		length++;
		map = ft_create_map(length);
	}
	return (0);
}
