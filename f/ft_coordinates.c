
#include "fillit.h"

t_tetrimino *ft_aline(t_tetrimino *head)
{
  t_tetrimino *temp;
  char c;

  c = 'A';
  temp = head;
  while(temp)
    {
      temp->letter = c;
      c++;
      while(temp->coordinates[1] != 0)
	{
	  temp->coordinates[1]--;
	  temp->coordinates[3]--;
	  temp->coordinates[5]--;
	  temp->coordinates[7]--;
	}
      while(temp->coordinates[0] != 0 && temp->coordinates[2] != 0 && temp->coordinates[4] != 0 && temp->coordinates[6] != 0)
	{
	  temp->coordinates[0]--;
          temp->coordinates[2]--;
          temp->coordinates[4]--;
          temp->coordinates[6]--;
	}
      temp = temp->next;
    }
  return (head);
}

int list_count(char **buf)
{
  int n;

  n = (ft_strlen(*buf) + 1) / 21;
  return (n);
}

t_tetrimino *ft_coordinates(char **buf)
{
  t_tetrimino	*head;
  t_tetrimino	*temp;
  int		count;
  int		coord;
  int		section;
  int		listnum;
  int		i;

  listnum = list_count(buf);
  if(!(head = (t_tetrimino *)malloc(sizeof(t_tetrimino))))
    return(NULL);
  temp = head;
  count = 0;
  section = 21;
  while(listnum > 0)
    {
      coord = 0;
      i = 0;
      while(count < section)
	{
	  if(buf[0][count] == '#')
	    {
	      temp->coordinates[coord] = i % 5;
	      temp->coordinates[coord + 1] = i/5;
	      coord = coord + 2;
	    }
	  count++;
	  i++;
	}
      section = section + 21;
      if(listnum > 1)
	{
	  if(!(temp->next = (t_tetrimino *)malloc(sizeof(t_tetrimino))))
	    return (NULL);
	}
      temp = temp->next;
      listnum--;
    }
  temp = NULL;
  return (ft_aline(head));
}
