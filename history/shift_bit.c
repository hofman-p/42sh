/*
** shift_bit.c for 42sh in /home/mace_j//42sh-2017/history
** 
** Made by jeanbaptiste mace
** Login   <mace_j@epitech.net>
** 
** Started on  Fri May 24 11:28:31 2013 jeanbaptiste mace
** Last update Fri May 24 19:20:28 2013 styve simonneau
*/

#include "list.h"

void    aff_fin_str(t_util *util)
{
  int   i;

  i = util->pos + 1;
  while (util->tableau[i] != '\0')
    {
      my_putchar(util->tableau[i]);
      i = i + 1;
    }
}

void    aff_fin_str2(t_util *util)
{
  int   i;
  int   lg;

  lg = 0;
  i = util->pos;
  while (util->tableau[i])
    {
      my_putchar(util->tableau[i]);
      i = i + 1;
      lg = lg + 1;
    }
  my_putchar(' ');
  while (lg >= 0)
    {
      tputs(tgetstr("le", NULL), 1, stv);
      lg = lg - 1;
    }
}

void     backslash(t_util *util)
{
  int   i;

  tputs(tgetstr("le", NULL), 1, stv);
  my_putchar(' ');
  util->pos = util->pos - 1;
  tputs(tgetstr("le", NULL), 1, stv);
  i = util->pos;
  while (util->tableau[i + 1])
    {
      util->tableau[i] = util->tableau[i + 1];
      i = i + 1;
    }
  util->tableau[i] = '\0';
  aff_fin_str2(util);
}

void	decalage_write(char *buffer, t_util *util)
{
  int   i;
  int   e;

  e = strlen(util->tableau);
  i = e;
  while (i >= util->pos)
    {
      util->tableau[i + 1] = util->tableau[i];
      i = i - 1;
    }
  my_putchar(buffer[0]);
  aff_fin_str(util);
  util->tableau[util->pos] = buffer[0];
  while (e > util->pos)
    {
      tputs(tgetstr("le", NULL), 1, stv);
      e = e - 1;
    }
  util->pos = util->pos + 1;
}
