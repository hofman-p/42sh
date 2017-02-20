/*
** for_bins.c for mysh in /home/simonn_s//svn/minishell1-2017-simonn_s
**
** Made by styve simonneau
** Login   <simonn_s@epitech.net>
**
** Started on  Sun Dec 16 16:56:48 2012 styve simonneau
** Last update Mon Jun  3 14:21:35 2013 styve simonneau
*/

#include <stdlib.h>
#include "protos.h"

void	modify_in_env(t_msh *pt)
{
  int	i;
  int	j;
  int	k;
  char	*cut;

  i = -1;
  j = -1;
  k = 0;
  while (pt->env[++i])
    {
      cut = cutenv(pt->env[i]);
      if (strcmp(pt->av[1], cut) == 0)
	{
	  pt->env[i] = check_av2(pt->env[i], pt);
	  while (pt->av[1][++j])
	    pt->env[i][j] = pt->av[1][j];
	  pt->env[i][j++] = '=';
	  if (pt->av[2])
	    while (pt->av[2][k])
	      pt->env[i][j++] = pt->av[2][k++];
	}
      my_free(cut);
    }
}

void	add_to_env(t_msh *pt, char **newenv, int i, int nb)
{
  clean_it(newenv[i], nb - 1);
  strcat(newenv[i], pt->av[1]);
  strcat(newenv[i], "=");
  if (pt->av[2] != NULL)
    strcat(newenv[i], pt->av[2]);
  newenv[i + 1] = NULL;
  pt->env = newenv;
}

char	*cutenv(char *env)
{
  int	i;
  char	*cut;

  i = -1;
  if ((cut = malloc(strlen(env) + 1)) == NULL)
    {
      my_error(1);
      return (NULL);
    }
  while (env[++i])
    cut[i] = env[i];
  i = 0;
  while (cut[i])
    {
      if (cut[i] == '=')
	cut[i] = '\0';
      else
	i++;
    }
  return (cut);
}

int	already_in_env(char **env, char **av)
{
  int	i;
  char	*cut;

  i = 0;
  while (env[i])
    {
      cut = cutenv(env[i++]);
      if (strcmp(av[1], cut) == 0)
	{
	  my_free(cut);
	  return (1);
	}
      my_free(cut);
    }
  return (0);
}

int	length_to_malloc(t_msh *pt)
{
  int	j;
  int	length;

  j = 1;
  length = 0;
  while (pt->av[j])
    length += strlen(pt->av[j++]);
  return (length);
}
