/*
** displayWinScreen.c for lemipc in /home/chazot_a/rendu/PSU_2014_lemipc
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Sat Mar  7 13:38:59 2015 Jordan Chazottes
** Last update Sun Mar  8 19:48:07 2015 Jordan Chazottes
*/

#include	"lemipc.h"

char		*getWinnerTeam(int i)
{
  if (i == 1)
    return ("Humans Won !");
  if (i == 2)
    return ("Elves Won !");
  if (i == 3)
    return ("Dwarves Won !");
  if (i == 4)
    return ("Orcs Won !");
  return ("Goblins Won !");

}

void		displayWinScreen(int i, SDL_Surface *screen)
{
  SDL_Surface	*txt;
  char		*texte;
  SDL_Rect	pos;
  TTF_Font	*font;
  SDL_Color	color;

  texte = getWinnerTeam(i);
  color.r = 0;
  color.g = 0;
  color.b = 0;
  font = TTF_OpenFont("font/FKV.ttf", 100);
  txt = TTF_RenderText_Blended(font, texte, color);
  pos.x = (X*32)/4;
  pos.y = (Y*32)/2;
  SDL_BlitSurface(txt, NULL, screen, &pos);
  SDL_Flip(screen);
  TTF_CloseFont(font);
  sleep(5);
}
