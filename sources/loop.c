/*
** loop.c for lemipc in /home/chazot_a/rendu/PSU_2014_lemipc
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Tue Mar  3 11:25:04 2015 Jordan Chazottes
** Last update Wed Mar  4 11:11:32 2015 Jordan Chazottes
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
      sops.sem_num = 0;
      sops.sem_flg = 0;
      sops.sem_op = -1;
      semop(sem_id, &sops, 1);
      /* showBattlefield(b); */
      showWarrior(w);
      /* algo(b, w); */
      /* showBattlefield(b); */
      sops.sem_op = 1;
      semop(sem_id, &sops, 1);
    }
}
