/*
** resetBackground.c for lemipc in /home/chazot_a/rendu/PSU_2014_lemipc/sources/display
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Fri Mar  6 19:03:46 2015 Jordan Chazottes
** Last update Fri Mar  6 20:10:38 2015 Jordan Chazottes
*/

#include	"lemipc.h"

void		resetBackground(void *addr, SDL_Surface *screen)
{
  int		i;
  int		j;
  SDL_Rect	clip[2];
  SDL_Surface	*bg;

  i = 0;
  bg = IMG_Load("images/env.png");
  clip[0].x = clip[1].x = 0;
  clip[0].y = 0;
  clip[0].w = clip[1].w = 32;
  clip[0].h = clip[1].h = 32;
  clip[1].y = 32;
  while (i < X)
    {
      j = 0;
      while (j < Y)
	{
	  applySurface(i*32, j*32, bg, screen, &clip[0]);
	  if (((t_battlefield*)addr)->battlefield[i][j] == 'X')
	    applySurface(i*32, j*32, bg, screen, &clip[1]);
	  ++j;
	}
      ++i;
    }
  SDL_FreeSurface(bg);
}
