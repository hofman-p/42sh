/*
** exec.c for mysh in /home/simonn_s//svn/minishell1-2017-simonn_s
**
** Made by styve simonneau
** Login   <simonn_s@epitech.net>
**
** Started on  Fri Dec 14 19:55:49 2012 styve simonneau
** Last update Wed Jun  5 00:25:02 2013 styve simonneau
*/

#include <unistd.h>
#include <stdlib.h>
#include "protos.h"
#include "error.h"

int	exec_echo(t_msh *pt, char **arg, int n)
{
  (void) pt;
  (void) n;
  if (arg[1] == NULL)
    {
      write(2, "Too few arguments to echo\n", 26);
      return (-1);
    }
  else
    printf("%s\n", arg[1]);
  return (0);
}

char	**mcit(char **env)
{
  int	i;
  char	**newenv;

  i = 0;
  while (env[i])
    i++;
  if (!(newenv = malloc(sizeof(char *) * (i + 2))))
    {
      my_error(1);
      return (NULL);
    }
  return (newenv);
}

int	exec_setenv(t_msh *pt, char **buff, int n)
{
  (void) n;
  int	i;
  int	tomalloc;
  char	**newenv;

  i = -1;
  if (pt->av[1] == NULL)
    return (exec_env(pt, buff, 0));
  if (pt->av[2] != NULL && pt->av[3] != NULL)
    printf("Usage: setenv <NAME> [VALUE]\n");
  newenv = mcit(pt->env);
  while (pt->env[++i])
    newenv[i] = pt->env[i];
  tomalloc = length_to_malloc(pt) + 2;
  if ((newenv[i] = malloc(tomalloc)) == NULL)
    return (my_error(1) + 1);
  newenv[i][tomalloc - 1] = '\0';
  if (already_in_env(pt->env, pt->av) == 0)
    add_to_env(pt, newenv, i, tomalloc);
  else
    modify_in_env(pt);
  return (0);
}

int	exec_unsetenv(t_msh *pt, char **buff, int n)
{
  int	i;
  int	k;
  char	**newenv;

  (void) n;
  (void) buff;
  i = 1;
  if (pt->av[1] == NULL)
    return (my_error(UNSETENV) + 1);
  while (pt->av[i])
    {
      newenv = mcit(pt->env);
      k = copy_in_newenv(pt, i, newenv);
      newenv[k] = NULL;
      pt->env = newenv;
      i++;
    }
  return (0);
}

int	exec_env(t_msh *pt, char **buff, int n)
{
  int	i;

  (void) n;
  (void) buff;
  i = 0;
  while (pt->env[i])
    printf("%s\n", pt->env[i++]);
  return (0);
}
