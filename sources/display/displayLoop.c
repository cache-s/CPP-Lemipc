/*
** displayLoop.c for lemipc in /home/chazot_a/rendu/PSU_2014_lemipc/display
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Fri Mar  6 12:43:00 2015 Jordan Chazottes
** Last update Fri Mar  6 12:49:38 2015 Jordan Chazottes
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
      SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 122, 122, 122));
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
    }
}
