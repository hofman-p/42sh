/*
** main.c for 42sh in /home/switi/svn/perso/42sh-2017
**
** Made by Styve Simonneau
** Login   <simonn_s@epitech.net>
**
** Started on  Wed Mar 13 15:14:48 2013 Styve Simonneau
** Last update Sun Sep 15 10:16:54 2013 pierre hofman
*/

#include "protos.h"

int	qdxsh(t_msh *pt, char *s)
{
  if (strlen(s) > 256)
    {
      fprintf(stderr, "\nCommand too long : %s\n", s);
      return (256);
    }
  return (separate(pt, s));
}

int	main(int ac, char **av, char **env)
{
  t_msh	pt;
  int	value;

  (void) ac;
  (void) av;
  signal(SIGINT, putprompt);
  init(&pt, env);
  value = save_all(&pt);
  return (value);
}
