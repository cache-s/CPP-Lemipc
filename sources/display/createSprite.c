/*
** createSprite.c for AVM in /home/chazot_a/rendu/PSU_2014_lemipc/display
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Fri Mar  6 12:29:03 2015 Jordan Chazottes
** Last update Fri Mar  6 13:04:38 2015 Jordan Chazottes
*/

#include	"lemipc.h"

void		createSprite(void *addr, int i, int j, SDL_Surface *screen)
{
  SDL_Rect      clip[5];
  SDL_Surface   *clp;

  if ((clp = IMG_Load("images/sprites.png")) == NULL)
    {
      /* printf("Sprite image not found, loading default sprites\n"); */
      createRect(addr, i, j, screen);
      return;
    }
  clip[0].x = 0;
  clip[0].y = 0;
  clip[0].w = 32;
  clip[0].h = 32;

  clip[1].x = 0;
  clip[1].y = 32;
  clip[1].w = 32;
  clip[1].h = 32;

  clip[2].x = 0;
  clip[2].y = 64;
  clip[2].w = 32;
  clip[2].h = 32;

  clip[3].x = 0;
  clip[3].y = 96;
  clip[3].w = 32;
  clip[3].h = 32;

  clip[4].x = 0;
  clip[4].y = 128;
  clip[4].w = 32;
  clip[4].h = 32;

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
