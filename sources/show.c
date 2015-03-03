/*
** showMap.c for lemipc in /home/chazot_a/rendu/PSU_2014_lemipc
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Mon Mar  2 16:54:39 2015 Jordan Chazottes
** Last update Tue Mar  3 11:05:24 2015 Sebastien Cache-Delanos
*/

#include	"lemipc.h"

void		showMap(t_map *s)
{
  int		i;
  int		j;

  i = 0;
  while (i < X) 
    {
      j = 0;
      while (j < Y)
	{
	  printf("%c", s->map[i][j]);
	  ++j;
	}
      printf("\n");
      ++i;
    }
}

void			showPlayer(t_player* p)
{
  printf("id : %d\n", p->id);
  printf("team : %d\n", p->team);
  if (p->state == ALIVE)
    printf("state : alive\n");
  if (p->state == DEAD)
    printf("state : dead\n");
  printf("posX : %d\nposY : %d\n", p->posX, p->posY);
}
