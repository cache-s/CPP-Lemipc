/*
** loop.c for lemipc in /home/chazot_a/rendu/PSU_2014_lemipc
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Tue Mar  3 11:25:04 2015 Jordan Chazottes
** Last update Thu Mar  5 16:59:29 2015 Sebastien Cache-Delanos
*/

#include			"lemipc.h"

void				loop(t_warrior *w)
{
  int                           sem_id;
  struct sembuf                 sops;
  key_t				key;

  key = ftok("/dev", 0);
  sem_id = semget(key, 1, SHM_R | SHM_W);
  while (w->state != DEAD)
    {
      init_sembuf(&sops, -1);
      semop(sem_id, &sops, 1);
      algo(w);
      //      showBattlefield(w);
      sops.sem_op = 1;
      semop(sem_id, &sops, 1);
      sleep(1);
    }
  printf("You died !\n");
  free(w);
}
