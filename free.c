/*
** free.c for 42sh in /home/switi/svn/perso/42sh-2017
**
** Made by Styve Simonneau
** Login   <simonn_s@epitech.net>
**
** Started on  Mon Mar 18 19:34:18 2013 Styve Simonneau
** Last update Mon Jun  3 14:29:48 2013 styve simonneau
*/

#include "protos.h"

void	my_free(void *ptr)
{
  if (ptr)
    free(ptr);
}

void	free_tab(char **tab)
{
  int	i;

  i = -1;
  if (tab)
    {
      while (tab[++i])
	my_free(tab[i]);
      my_free(tab);
    }
}
