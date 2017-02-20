/*
** add_entries.c for add_entries in /home/switi/svn/B2/42sh-2017-simonn_s
**
** Made by Styve Simonneau
** Login   <simonn_s@epitech.net>
**
** Started on  Sun May 26 15:56:14 2013 Styve Simonneau
** Last update Sun May 26 19:50:05 2013 pierre hofman
*/

#include "protos.h"

int	add_entries(t_msh *pt)
{
  char	*cwd;

  pt->env_modified = 1;
  if (!(cwd = malloc(300)))
    return (my_error(1));
  if (!(pt->env = malloc(sizeof(char *) * 3)))
    return (my_error(1));
  if (!(getcwd(cwd, 300)))
    {
      fprintf(stderr, "Error length cd\n");
      return (-1);
    }
  pt->env[0] = strdup("PATH=/bin:/usr/bin");
  if (!(pt->env[1] = malloc(strlen(cwd) + 4)))
    return (my_error(1));
  strcpy(pt->env[1], "PWD=");
  strcat(pt->env[1], cwd);
  pt->env[2] = NULL;
  return (0);
}
