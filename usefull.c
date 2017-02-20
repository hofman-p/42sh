/*
** small_func.c for mysh in /home/simonn_s//svn/minishell1-2017-simonn_s
**
** Made by styve simonneau
** Login   <simonn_s@epitech.net>
**
** Started on  Wed Dec 12 16:46:30 2012 styve simonneau
** Last update Sun May 26 18:29:48 2013 Styve Simonneau
*/

#include <stdlib.h>
#include "protos.h"

char	*clean_it(char *str, int nb)
{
  int	i;

  i = 0;
  while (i != nb)
    str[i++] = '\0';
  return (str);
}

void	change_env(char *s1, char *s2, char *s3, t_msh *pt)
{
  if (!(pt->av = malloc(sizeof(char *) * 4)))
    return;
  pt->av[0] = strdup(s1);
  pt->av[1] = strdup(s2);
  pt->av[2] = strdup(s3);
  pt->av[3] = NULL;
  check_builtin(pt, pt->av, 0);
}

void	remove_bn(char file[])
{
  int	i;

  i = 0;
  while (file[i])
    {
      if (file[i] == ' ' || file[i] == '\n')
	file[i] = '\0';
      else
	i++;
    }
}

void	my_putstr(char *str)
{
  int	i;

  i = -1;
  while (str[++i])
    write(1, &str[i], 1);
}

void	putprompt()
{
  my_putstr("\n$>");
}
