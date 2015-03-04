/*
** showMap.c for lemipc in /home/chazot_a/rendu/PSU_2014_lemipc
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Mon Mar  2 16:54:39 2015 Jordan Chazottes
** Last update Wed Mar  4 17:09:55 2015 Jordan Chazottes
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
  i = -1;
  while (++i < 5)
    printf("Army number %d : %d Warriors\n", i + 1, ((t_battlefield*)addr)->recap[i]);
}

void			showWarrior(t_warrior* w)
{
  printf("id : %d\n", w->id);
  printf("army : %d\n", w->army);
  if (w->state == ALIVE)
    printf("state : alive\n");
  if (w->state == DEAD)
    printf("state : dead\n");
  printf("posX : %d\nposY : %d\n", w->posX, w->posY);
}
