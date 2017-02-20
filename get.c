/*
** get.c for 42sh in /home/simonn_s//svn/minishell1-2017-simonn_s
**
** Made by styve simonneau
** Login   <simonn_s@epitech.net>
**
** Started on  Sat Feb 23 12:55:49 2012 styve simonneau
** Last update Mon Jun  3 14:20:51 2013 styve simonneau
*/

#include <stdlib.h>
#include <unistd.h>
#include "protos.h"

int	is_oldvalue(char *str, char *what)
{
  int	i;
  char	*value;

  i = 0;
  value = strdup(what);
  while (value[i])
    {
      if (value[i] != str[i])
	{
	  my_free(value);
	  return (0);
	}
      i++;
    }
  my_free(value);
  return (1);
}

char	*get_oldvalue(char *str)
{
  char	*path;
  int	i;
  int	j;

  i = 0;
  while (str[i++] != '=');
  j = 0;
  while (str[i++])
    j++;
  if (!(path = malloc(j + 1)))
    my_error(1);
  path[j] = '\0';
  i = 0;
  while (str[i++] != '=');
  j = 0;
  while (str[i])
    path[j++] = str[i++];
  return (path);
}

char	*get(char **env, char *what)
{
  int	i;
  char	*value;

  i = 0;
  while (env[i])
    {
      if (is_oldvalue(env[i], what) == 0)
	i++;
      else
	{
	  value = get_oldvalue(env[i]);
	  return (value);
	}
    }
  return (NULL);
}
