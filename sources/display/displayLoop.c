/*
** displayLoop.c for lemipc in /home/chazot_a/rendu/PSU_2014_lemipc/display
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Fri Mar  6 12:43:00 2015 Jordan Chazottes
** Last update Sat Mar  7 14:29:59 2015 Jordan Chazottes
*/

#include	"lemipc.h"

void		displayLoop(SDL_Surface *screen)
{
  int		i;
  int		j;
  void		*addr;

  while (42)
    {
      if ((addr = getShm()) == NULL || eventHandler() == 0)
	return;
      if ((i = checkWin(addr)) == 0)
	{
	  i = -1;
	  resetBackground(addr, screen);
	  while (++i < X)
	    {
	      j = -1;
	      while (++j < Y)
		if (((t_battlefield*)addr)->battlefield[i][j] != '.')
		  createSprite(addr, i, j, screen);
	    }
	  SDL_Flip(screen);
	  usleep(50000);
	}
      else
	{
	  displayWinScreen(i, screen);
	  sleep(5);
	  return;
	}
    }
}
