/*
** showMap.c for lemipc in /home/chazot_a/rendu/PSU_2014_lemipc
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Mon Mar  2 16:54:39 2015 Jordan Chazottes
** Last update Fri Mar  6 12:12:01 2015 Sebastien Cache-Delanos
*/

#include		"lemipc.h"

void			showBattlefield(t_warrior* w)
{
  int			i;
  int			j;
  void			*addr;
  
  addr = shmat(w->shm_id, NULL, SHM_R);
  i = -1;
  while (++i < X) 
    {
      j = 0;
      while (j < Y)
	{
	  printf("%c", ((t_battlefield*)addr)->battlefield[i][j]);
	  ++j;
	}
      printf("\n");
    }
  printf("\n");
  //  while (++i < 5)
  //    printf("Army number %d : %d Warriors\n", i + 1, ((t_battlefield*)addr)->recap[i]);
}

void			showWarrior(t_warrior* w)
{
  if (w->army == 1)
    printf("You are a Human ");
  if (w->army == 1)
    printf("You are an Elf ");
  if (w->army == 1)
    printf("You are a Dwarf ");
  if (w->army == 1)
    printf("You are an Orc ");
  if (w->army == 1)
    printf("You are a Goblin ");
  printf("at x%d and y%d\n", w->posX, w->posY);
}
