/*
** createSprite.c for AVM in /home/chazot_a/rendu/PSU_2014_lemipc/display
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Fri Mar  6 12:29:03 2015 Jordan Chazottes
** Last update Sat Mar  7 13:12:11 2015 Jordan Chazottes
*/

#include	"lemipc.h"

void		createSprite(void *addr, int i, int j, SDL_Surface *screen)
{
  SDL_Rect      clip[5];
  SDL_Surface   *clp;

  if ((clp = IMG_Load("images/sprites.png")) == NULL)
    {
      createRect(addr, i, j, screen);
      return;
    }
  clip[0].x = clip[1].x = clip[2].x = clip[3].x = clip[4].x = clip[0].y = 0;
  clip[0].w = clip[1].w = clip[2].w = clip[3].w = clip[4].w = clip[0].h =
    clip[1].h = clip[2].h = clip[3].h = clip[4].h = clip[1].y = 32;
  clip[2].y = 64;
  clip[3].y = 96;
  clip[4].y = 128;
  if (((t_battlefield*)addr)->battlefield[i][j] == '1')
    applySurface(i*32, j*32, clp, screen, &clip[0]);
  if (((t_battlefield*)addr)->battlefield[i][j] == '2')
    applySurface(i*32, j*32, clp, screen, &clip[1]);
  if (((t_battlefield*)addr)->battlefield[i][j] == '3')
    applySurface(i*32, j*32, clp, screen, &clip[2]);
  if (((t_battlefield*)addr)->battlefield[i][j] == '4')
    applySurface(i*32, j*32, clp, screen, &clip[3]);
  if (((t_battlefield*)addr)->battlefield[i][j] == '5')
    applySurface(i*32, j*32, clp, screen, &clip[4]);
  SDL_FreeSurface(clp);
}
