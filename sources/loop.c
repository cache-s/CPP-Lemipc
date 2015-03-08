/*
** loop.c for lemipc in /home/chazot_a/rendu/PSU_2014_lemipc
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Tue Mar  3 11:25:04 2015 Jordan Chazottes
** Last update Sun Mar  8 15:41:06 2015 Sebastien Cache-Delanos
*/

#include			"lemipc.h"

int	lastPlayer(void* addr)
{
  int	i;

  i = 0;
  while (i < 5)
    {
      if (((t_battlefield*)addr)->recap[i] > 0)
	return (-1);
      ++i;
    }
  return (0);
}

void	loop2(t_warrior* w, void* addr, struct sembuf sops, int sem_id)
{
  while (w->state != DEAD && checkAlone(w, addr) == 0)
    {
      usleep(250000);
      sops.sem_op = -1;
      semop(sem_id, &sops, 1);
      algo(w, addr);
      sops.sem_op = 1;
      semop(sem_id, &sops, 1);
    }
  ((t_battlefield*)addr)->recap[w->army - 1] -= 1;
  if (lastPlayer(addr) == 0)
    {
      sops.sem_op = -1;
      semop(sem_id, &sops, 1);
      ((t_battlefield*)addr)->winner = w->army;
      sops.sem_op = 1;
      semop(sem_id, &sops, 1);
      sleep(1);
      semctl(sem_id, 0, IPC_RMID, 0);
      shmctl(w->shm_id, IPC_RMID, NULL);
    }
}

void				loop(t_warrior *w)
{
  int                           sem_id;
  struct sembuf                 sops;
  key_t				key;
  void*				addr;

  key = ftok("/dev", 0);
  sem_id = semget(key, 1, SHM_R | SHM_W);
  addr = shmat(w->shm_id, NULL, SHM_R | SHM_W);
  if (sem_id == -1)
    {
      sem_id = semget(key, 1, IPC_CREAT | SHM_R | SHM_W);
      semctl(sem_id, 0, SETVAL, 1);
    }
  sops.sem_num = 0;
  sops.sem_flg = 0;
  while (checkAlone(w, addr) != 0)
    sleep(1);
  loop2(w, addr, sops, sem_id);
  free(w);
}
