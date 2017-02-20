/*
** init.c for init.c in /home/mace_j//afs/unix/42sh/history
**
** Made by jeanbaptiste mace
** Login   <mace_j@epitech.net>
**
** Started on  Mon Apr 22 17:51:27 2013 jeanbaptiste mace
** Last update Sat Jun  8 14:56:46 2013 jeanbaptiste mace
*/

#include "list.h"
#include "error.h"

int	raw_mode(struct termios *t)
{
  t->c_lflag &= ~ICANON;
  t->c_lflag &= ~ECHO;
  if (tcsetattr(0, TCSANOW, t) == -1)
    return (-1);
  return (0);
}

int     init_term()
{
  char	*term;

  if ((term = getenv("TERM")) == NULL)
    return (-1);
  if (tgetent(NULL , term) < 1)
    return (-1);
  return (0);
}

int			icanon()
{
  struct termios	t;

  if (init_term() == -1)
    return (-1);
  if (tcgetattr(0, &t) == -1)
    return (-1);
  if (raw_mode(&t) == -1)
    return (-1);
  return (0);
}
