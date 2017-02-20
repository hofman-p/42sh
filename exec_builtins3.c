/*
** exec_builtins3.c for 42 in /home/simonn_s//svn/42sh-2017-simonn_s
** 
** Made by styve simonneau
** Login   <simonn_s@epitech.net>
** 
** Started on  Tue Jun  4 20:55:28 2013 styve simonneau
** Last update Tue Jun  4 21:05:59 2013 styve simonneau
*/

#include "protos.h"

int	exec_source(t_msh *pt, char **arg, int n)
{
  int	i;

  (void) n;
  if (arg[1])
    {
      i = -1;
      while (pt->alias[++i])
	{
	  my_free(pt->alias[i][0]);
	  my_free(pt->alias[i][1]);
	  my_free(pt->alias[i]);
	}
      my_free(pt->alias);
      pt->nb_alias = 0;
      pt->alias = NULL;
      read_in_file(pt, arg[1]);
    }
  else
    fprintf(stderr, "source: usage: source <file>\n");
  return (0);
}
