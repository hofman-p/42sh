/*
** fonction_util.c for fonction in /home/mace_j//afs/unix/42sh/history
**
** Made by jeanbaptiste mace
** Login   <mace_j@epitech.net>
**
** Started on  Mon Apr 22 17:53:44 2013 jeanbaptiste mace
** Last update Sun Jun  9 19:18:55 2013 styve simonneau
*/

#include <unistd.h>
#include "list.h"

void    my_putchar(char c)
{
  write(1, &c, 1);
}

void	move_end(t_util *util)
{
  while (util->pos < (int)(strlen(util->tableau)))
    {
      tputs(tgetstr("nd", NULL), 1, stv);
      ++util->pos;
    }
}
