/*
** loop.c for lemipc in /home/chazot_a/rendu/PSU_2014_lemipc
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Tue Mar  3 11:25:04 2015 Jordan Chazottes
** Last update Tue Mar  3 19:38:09 2015 Sebastien Cache-Delanos
*/

#include			"lemipc.h"

void				loop(t_battlefield *b, t_warrior *w)
{
  int                           sem_id;
  struct sembuf                 sops;
  key_t                         key;

  (void)b;
  key = ftok("/dev", 0);
  if ((sem_id = semget(key, 1, SHM_R | SHM_W)) == -1)
    {
      sem_id = semget(key, 2, IPC_CREAT | SHM_R | SHM_W);
      printf("Created sem %d\n", sem_id);
      semctl(sem_id, 0, SETVAL, 1);
    }
  printf("Using sem %d\n", sem_id);
  while (w->state != DEAD)
    {
      sops.sem_num = 0;
      sops.sem_flg = 0;
      sops.sem_op = -1;
      printf("Before %d\n", semctl(sem_id, 0, GETVAL));
      semop(sem_id, &sops, 1);
      sleep(2);
      printf("After %d\n", semctl(sem_id, 0, GETVAL));
      sops.sem_op = 1;
      semop(sem_id, &sops, 1);
      printf("After add %d\n\n", semctl(sem_id, 0, GETVAL));
    }
}

/*
t_warrior                   *p; 
while (p->state != DEAD || team victory) 
  { 
    wait signal : get "mutex"                                                                                  
      on change la pos                                          
      on catch les message msgq                                                       
      }
isLast() ? destroyIPCS
*/