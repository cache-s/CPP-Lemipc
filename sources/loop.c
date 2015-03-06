/*
** loop.c for lemipc in /home/chazot_a/rendu/PSU_2014_lemipc
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Tue Mar  3 11:25:04 2015 Jordan Chazottes
** Last update Fri Mar  6 11:23:55 2015 Sebastien Cache-Delanos
*/

#include			"lemipc.h"

void				loop(t_warrior *w)
{
  int                           sem_id;
  struct sembuf                 sops;
  key_t				key;

  key = ftok("/dev", 0);
  sem_id = semget(key, 1, SHM_R | SHM_W);
  if (sem_id == -1)
    {
      sem_id = semget(key, 1, IPC_CREAT | SHM_R | SHM_W);
      semctl(sem_id, 0, SETVAL, 1);
    }
  sops.sem_num = 0;
  sops.sem_flg = 0;
  while (w->state != DEAD)
    {
      sops.sem_op = -1;
      semop(sem_id, &sops, 1);
      showBattlefield(w);
      sleep(1);
      algo(w);
      showBattlefield(w);
      sleep(1);
      sops.sem_op = 1;
      semop(sem_id, &sops, 1);
    }
  printf("You died !\n");
  free(w);
}
