/*
** showMap.c for lemipc in /home/chazot_a/rendu/PSU_2014_lemipc
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Mon Mar  2 16:54:39 2015 Jordan Chazottes
** Last update Mon Mar  2 19:04:32 2015 Sebastien Cache-Delanos
*/

#include	"lemipc.h"

void		showMap(t_struct *s)
{
  int		i;
  int		j;

  i = 0;
  while (i < X) 
    {
      j = 0;
      while (j < Y)
	{
	  printf("|%d", s->map[i][j]);
	  ++j;
	}
      printf("|\n");
      ++i;
    }
}
