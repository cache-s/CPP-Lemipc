/*
** createRect.c for lemipc in /home/chazot_a/rendu/PSU_2014_lemipc/display
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Fri Mar  6 12:30:13 2015 Jordan Chazottes
** Last update Fri Mar  6 12:33:52 2015 Jordan Chazottes
*/

#include	"lemipc.h"

void		createRect(void *addr, int i, int j, SDL_Surface *screen)
{
  SDL_Surface	*rectangle;
  SDL_Rect	pos;

  rectangle = SDL_CreateRGBSurface(SDL_HWSURFACE, 10, 10, 32, 0, 0, 0, 0);
  if (((t_battlefield*)addr)->battlefield[i][j] == '1')
    SDL_FillRect(rectangle, NULL, SDL_MapRGB(screen->format, 9, 0, 255));
  if (((t_battlefield*)addr)->battlefield[i][j] == '2')
    SDL_FillRect(rectangle, NULL, SDL_MapRGB(screen->format, 87, 255, 0));
  if (((t_battlefield*)addr)->battlefield[i][j] == '3')
    SDL_FillRect(rectangle, NULL, SDL_MapRGB(screen->format, 125, 125, 125));
  if (((t_battlefield*)addr)->battlefield[i][j] == '4')
    SDL_FillRect(rectangle, NULL, SDL_MapRGB(screen->format, 255, 0, 15));
  if (((t_battlefield*)addr)->battlefield[i][j] == '5')
    SDL_FillRect(rectangle, NULL, SDL_MapRGB(screen->format, 30, 84, 6));
  pos.x = i * 32;
  pos.y = j * 32;
  SDL_BlitSurface(rectangle, NULL, screen, &pos);
}
