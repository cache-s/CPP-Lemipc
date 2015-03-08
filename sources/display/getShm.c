/*
** getShm.c for lemipc in /home/chazot_a/rendu/PSU_2014_lemipc/display
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Fri Mar  6 12:35:32 2015 Jordan Chazottes
** Last update Sun Mar  8 19:58:50 2015 Jordan Chazottes
*/

#include	"lemipc.h"

void		*getShm()
{
  key_t		key;
  int		shm_id;

  key = ftok("/dev", 0);
  if ((shm_id = shmget(key, sizeof(t_battlefield), SHM_R)) == -1)
    {
      printf("There are no battles in the Middle-Earth, RUN YOU FOOLS.\n");
      return (NULL);
    }
  return (shmat(shm_id, NULL, SHM_R));
}
