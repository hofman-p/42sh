/*
** cd2.c for cd2.c in /home/hofman_p/W/Projets/42sh/42sh-2017
**
** Made by Pierre Hofman
** Login   <hofman_p@epitech.net>
**
** Started on  Fri May 17 18:48:54 2013 Pierre Hofman
** Last update Sun May 26 23:29:25 2013 brandon salopek
*/

#include "protos.h"

int	my_getcwd(t_msh *cd)
{
  size_t	size;

  size = 300;
  if (!(cd->cwd = malloc(300)))
    return (-1);
  if (!(getcwd(cd->cwd, size)))
    {
      fprintf(stderr, "Error length cd\n");
      return (-1);
    }
  return (0);
}

void	print_change_cd(char *pwd, char *way, t_msh *cd)
{
  printf("%s\n", pwd);
  change_env("setenv", "OLDPWD", way, cd);
}
