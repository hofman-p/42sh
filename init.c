/*
** init.c for 42sh in /home/switi/svn/perso/42sh-2017
**
** Made by Styve Simonneau
** Login   <simonn_s@epitech.net>
**
** Started on  Wed Mar 13 15:15:18 2013 Styve Simonneau
** Last update Tue Jun  4 05:56:22 2013 styve simonneau
*/

#include <stdlib.h>
#include "protos.h"

void	display(char **what)
{
  int	i;

  i = -1;
  while (what[++i])
    printf("tab[%d] = %s\n", i, what[i]);
}

int	entry_env(char **env)
{
  int	i;

  i = -1;
  while (env[++i]);
  return (i);
}

void	get_path(t_msh *pt, char **env)
{
  char	*path;

  if ((path = get(env, "PATH=")) != NULL)
    pt->path = my_str_to_wordtab(path, ":");
  else
    {
      if (!(pt->path = malloc(sizeof(char *) * 3)))
	{
	  my_error(1);
	  return;
	}
      pt->path[0] = strdup("/bin");
      pt->path[1] = strdup("/usr/bin");
      pt->path[2] = NULL;
    }
}

void	get_env(t_msh *pt, char **env)
{
  int	i;
  int	entries;

  i = -1;
  if ((entries = entry_env(env)) == 0)
    add_entries(pt);
  else
    {
      if (!(pt->env = malloc(sizeof(char *) * (entries + 1))))
	{
	  my_error(1);
	  return;
	}
      pt->env[entries] = NULL;
      while (env[++i])
	{
	  pt->env[i] = strdup(env[i]);
	  if (pt->env_modified == 1)
	    my_free(pt->env[i]);
	}
      if (pt->env_modified == 1)
	my_free(pt->env);
      pt->env_modified = 1;
    }
}

void	init(t_msh *pt, char **env)
{
  pt->env_modified = 0;
  pt->exit = 256;
  get_path(pt, env);
  get_env(pt, env);
  get_alias_(pt);
  change_env("setenv", "OLDPWD", get(pt->env, "PWD="), pt);
}
