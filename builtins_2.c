/*
** for_bins2.c for mysh in /home/simonn_s//svn/minishell1-2017-simonn_s
**
** Made by styve simonneau
** Login   <simonn_s@epitech.net>
**
** Started on  Fri Dec 21 16:19:38 2012 styve simonneau
** Last update Mon Jun  3 14:21:29 2013 styve simonneau
*/

#include <stdlib.h>
#include "protos.h"

char	*check_av2(char *line, t_msh *pt)
{
  int	i;

  i = strlen(pt->av[1]);
  if (pt->av[2])
    {
      if (!(line = malloc(i + strlen(pt->av[2]) + 2)))
	{
	  my_error(1);
	  return (NULL);
	}
      line[i + strlen(pt->av[2]) + 1] = '\0';
    }
  else
    {
      if (!(line = malloc(i + 1)))
	{
	  my_error(1);
	  return (NULL);
	}
      line[i] = '\0';
    }
  return (line);
}

int	copy_in_newenv(t_msh *pt, int i, char **newenv)
{
  int	j;
  int	k;
  char	*cut;

  j = 0;
  k = 0;
  while (pt->env[j])
    {
      cut = cutenv(pt->env[j]);
      if (strcmp(pt->av[i], cut) != 0)
	newenv[k++] = pt->env[j++];
      else
	j++;
      my_free(cut);
    }
  return (k);
}

char	*get_user(t_msh *pt)
{
  int	i;
  int	j;
  int	k;
  char	*cut;
  char	*user;

  i = -1;
  k = 0;
  j = 5;
  if (!(user = malloc(40)))
    return (NULL);
  while (pt->env[++i])
    {
      cut = cutenv(pt->env[i]);
      if (strcmp(cut, "USER") == 0)
	{
	  while (pt->env[i][j])
	    user[k++] = pt->env[i][j++];
	  user[k] ='\0';
	  return (user);
	}
      my_free(cut);
    }
  return (NULL);
}
