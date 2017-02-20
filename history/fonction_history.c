/*
** fonction_history.c for fonction in /home/mace_j//afs/unix/42sh/history
**
** Made by jeanbaptiste mace
** Login   <mace_j@epitech.net>
**
** Started on  Mon Apr 22 17:54:34 2013 jeanbaptiste mace
** Last update Sat Jun  8 15:08:33 2013 jeanbaptiste mace
*/

#include "list.h"

int     copy_str(char *str, char *str2, int a)
{
  if (str2 && str)
    {
      str2[a] = str[0];
      a = a + 1;
      str2[a] = '\0';
    }
  return (0);
}

char	*copy_str_full(char *str, char *str2)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      str2[i] = str[i];
      i = i + 1;
    }
  return (str2);
}

void    clean_tab(char *str, int nb)
{
  int   i;

  i = 0;
  while (i < nb)
    str[i++] = '\0';
}

int     stv(int c)
{
  write(1, &c, 1);
  return (0);
}

int     del_touch()
{
  my_putchar('\b');
  tputs(tgetstr("dc", NULL), 1, stv);
  return (0);
}
