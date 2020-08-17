
#include "fillit.h"
#include <stdio.h>
void ft_fillit(char **buf)
{
  t_tetrimino *crd;
  t_tetrimino *temp;
  
  crd = ft_coordinates(buf);
  temp = crd;
  /* while(temp)
    {
      printf("cord1 = %d,%d - %c\ncord2 = %d,%d - %c\ncord3 = %d,%d - %c\ncord4 = %d,%d - %c\n",\
      temp->coordinates[0],temp->coordinates[1], temp->letter,		\
      temp->coordinates[2],temp->coordinates[3],temp->letter,		\
      temp->coordinates[4],temp->coordinates[5],temp->letter,		\
      temp->coordinates[6],temp->coordinates[7],temp->letter);
      ft_putchar('\n');
      temp = temp->next;
      }*/
  ft_map(crd);
}

int main (int argc, char **argv)
{
  int	fd;
  int	ret;
  char	buf[BUFF_SIZE + 1];
  char *bf;
  
  if (argc != 2)
    ft_putstr("usage: ./fillit test_file\n");
  else
    {
      if((fd = open(argv[1], O_RDONLY)) < 0)
	ft_putstr("error");
      ret = read(fd, buf, BUFF_SIZE);
      buf[ret] = '\0';
      close (fd);
      bf = buf;
      //ft_putstr("this is what was read\n");
      //ft_putstr(buf);
      ft_fillit(&bf);
    }
  return (0);
}
