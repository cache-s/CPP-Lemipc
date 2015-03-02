/*
** showMap.c for lemipc in /home/chazot_a/rendu/PSU_2014_lemipc
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Mon Mar  2 16:54:39 2015 Jordan Chazottes
** Last update Mon Mar  2 17:12:07 2015 Jordan Chazottes
*/

#include	"lemipc.h"

void		showMap(int **map)
{
  int i;
  int j;

  i = 0;
  while (i < 250) 
    {
      j = 0;
      while (j < 250)
	{
	  printf("|%d", map[i][j]);
	  ++j;
	}
      printf("|\n");
      ++i;
    }
}
