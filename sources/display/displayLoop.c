/*
** displayLoop.c for lemipc in /home/chazot_a/rendu/PSU_2014_lemipc/display
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Fri Mar  6 12:43:00 2015 Jordan Chazottes
** Last update Sat Mar  7 12:58:22 2015 Jordan Chazottes
*/

#include	"lemipc.h"

void		displayLoop(SDL_Surface *screen)
{
  int		i;
  int		j;
  void		*addr;

  while (42)
    {
      i = 0;
      if ((addr = getShm()) == NULL || eventHandler() == 0)
        return;
      resetBackground(addr, screen);
      while (i < X)
        {
          j = 0;
          while (j < Y)
            {
              if (((t_battlefield*)addr)->battlefield[i][j] != '.')
                createSprite(addr, i, j, screen);
              ++j;
            }
          ++i;
        }
      SDL_Flip(screen);
      usleep(200000);
    }
}
