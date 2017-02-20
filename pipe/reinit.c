/*
** reinit.c for 42sh in /home/salope_b//42sh-2017-simonn_s/test/42sh-2017-simonn_s/history
**
** Made by brandon salopek
** Login   <salope_b@epitech.net>
**
** Started on  Sun May 26 08:08:30 2013 brandon salopek
** Last update Sun May 26 22:22:27 2013 Styve Simonneau
*/

#include "list.h"
#include "error.h"

int	no_raw_mode(struct termios *termios_p)
{
  termios_p->c_lflag &= (ECHO | ECHONL | ICANON | ISIG | IEXTEN);
  if (tcsetattr(0, TCSANOW, termios_p) == -1)
    return (TCSETATTR);
  return (0);
}

int			no_icanon()
{
  struct termios	t;

  init_term();
  if (tcgetattr(0, &t) == -1)
    return (TCGETATTR);
  if (no_raw_mode(&t) == -1)
    return (-1);
  return (0);
}
