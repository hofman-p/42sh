/*
** exec.c for 42sh in /home/salope_b//42sh/pipe_inf
**
** Made by brandon salopek
** Login   <salope_b@epitech.net>
**
** Started on  Fri May 24 02:29:26 2013 brandon salopek
** Last update Mon Jun  3 14:23:39 2013 styve simonneau
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "struct.h"
#include "protos.h"
#include "my.h"

char	*create_path(char *beg, char *end)
{
  int	size;
  char	*path;

  path = NULL;
  size = strlen(beg) + strlen(end);
  path = malloc(sizeof(char) * (size + 4));
  path[0] = '\0';
  path = strcat(path, beg);
  path = strcat(path, "/");
  path = strcat(path, end);
  return (path);
}

int	my_print_err(char *s)
{
  fprintf(stderr, "%s : Command not found.\n", s);
  return (-1);
}

int	my_exec(char **arg, t_msh *msh)
{
  int	i;
  int	ret;
  char	*path;

  i = 0;
  if ((ret = access(arg[0], F_OK)) != -1)
    return (-2);
  msh->av = arg;
  if ((ret = check_builtin(msh, arg, 1)) == 0)
    return (-3);
  else if (ret == -1)
    return (-4);
  path = NULL;
  path = create_path(msh->path[0], arg[0]);
  ret = access(path, F_OK);
  while (msh->path[++i] != NULL && ret == -1)
    {
      my_free(path);
      path = create_path(msh->path[i], arg[0]);
      ret = access(path, F_OK);
    }
  if (ret == -1)
    return (my_print_err(arg[0]));
  else
    return (i - 1);
}
