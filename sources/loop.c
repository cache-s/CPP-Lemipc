/*
** loop.c for lemipc in /home/chazot_a/rendu/PSU_2014_lemipc
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Tue Mar  3 11:25:04 2015 Jordan Chazottes
** Last update Wed Mar  4 18:09:19 2015 Jordan Chazottes
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
      init_sembuf(&sops, 1);
      semop(sem_id, &sops, 1);
      showBattlefield(w);
      showWarrior(w);
      /* algo(b, w); */
      sops.sem_op = 1;
      semop(sem_id, &sops, 1);
    }
}
