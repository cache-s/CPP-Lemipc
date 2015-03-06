/*
** eventHandler.c for lemipc in /home/chazot_a/rendu/PSU_2014_lemipc/display
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Fri Mar  6 12:34:14 2015 Jordan Chazottes
** Last update Fri Mar  6 12:35:14 2015 Jordan Chazottes
*/

#include	"lemipc.h"

int		eventHandler()
{
  SDL_Event     event;

  while(SDL_PollEvent(&event))
    {
      if (event.type == SDL_QUIT ||
	  (event.type == SDL_KEYDOWN &&
	   event.key.keysym.sym == SDLK_ESCAPE))
        return (0);
    }
  return (1);
}
