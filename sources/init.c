/*
** start.c for lemipc in /home/cache-_s/rendu/PSU_2014_lemipc/sources
** 
** Made by Sebastien Cache-Delanos
** Login   <cache-_s@epitech.net>
** 
** Started on  Mon Mar  2 12:12:35 2015 Sebastien Cache-Delanos
** Last update Wed Mar  4 11:48:23 2015 Jordan Chazottes
*/

#include			"lemipc.h"

t_battlefield				initStruct(t_battlefield b)
{
  int				i;
  int				j;

  i = -1;
  while (++i < X)
    {
      j = -1;
      while (++j < Y)
	b.battlefield[i][j] = '.';
    }
  i = -1;
  while (++i < 5)
    b.recap[i] = 0;
  return (b);
}

t_battlefield*				initBattlefield()
{
  t_battlefield			b;
  key_t				key;
  int				shm_id;
  void				*addr;

  key = ftok("/dev", 0);
  if ((shm_id = shmget(key, sizeof(b), SHM_R | SHM_W)) == -1)
    {
      b = initStruct(b);
      shm_id = shmget(key, sizeof(b), IPC_CREAT | SHM_R  | SHM_W);
      addr = shmat(shm_id, NULL, SHM_R | SHM_W);
      memcpy(addr, &b, sizeof(b));
    }
  addr = shmat(shm_id, NULL, SHM_R | SHM_W);
  /*shmctl(shm_id, IPC_RMID, NULL); A METTRE A LA MORT DU DENIER PLAYER */
  return ((t_battlefield*)addr);
}

void				initWarriorPos(t_warrior **w, void *addr)
{
  int				r_x;
  int				r_y;
  struct sembuf			sops;

  r_x = -1;
  sops.sem_num = 0;
  sops.sem_flg = 0;
  sops.sem_op = -1;
  semop((*w)->shm_id, &sops, 1);
  while (r_x == -1)
    {
      r_x = (rand() % X);
      r_y = (rand() % Y);
      if (((t_battlefield*)addr)->battlefield[r_x][r_y] != '.')
	r_x = -1;
    }
  sops.sem_op = 1;
  semop((*w)->shm_id, &sops, 1);
  (*w)->posX = r_x;
  (*w)->posY = r_y;
}

t_warrior*			initWarrior(int army)
{
  t_warrior			*w;
  key_t				key;
  void				*addr;

  key = ftok("/dev", 0);
  w = malloc(sizeof(*w));

  if (w != NULL)
    {
      w->id = 0;
      w->state = ALIVE;
      w->shm_id = shmget(key, sizeof(t_battlefield), SHM_R | SHM_W);
      addr = shmat(w->shm_id, NULL, SHM_R | SHM_W);
      initWarriorPos(&w, addr);
      w->army = army;
    }
  else
    printf("Malloc fail in initWarrior()\n");
  return (w);
}
