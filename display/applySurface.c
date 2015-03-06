/*
** applySurface.c for lemipc in /home/chazot_a/rendu/PSU_2014_lemipc/display
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Fri Mar  6 12:36:54 2015 Jordan Chazottes
** Last update Fri Mar  6 12:41:47 2015 Jordan Chazottes
*/

#include	"lemipc.h"

void		applySurface(int x, int y, SDL_Surface *src, SDL_Surface *dest, SDL_Rect *clip)
{
  SDL_Rect	offset;

  offset.x = x;
  offset.y = y;
  SDL_BlitSurface(src, clip, dest, &offset);
}
