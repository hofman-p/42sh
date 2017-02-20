/*
** stdio.c for 42 in /home/switi/svn/perso/42sh-2017/lib
**
** Made by Styve Simonneau
** Login   <simonn_s@epitech.net>
**
** Started on  Mon May  6 14:42:26 2013 Styve Simonneau
** Last update Mon May  6 14:45:37 2013 Styve Simonneau
*/

int	my_putchar(char c)
{
  if (write(1, &c, 1) == -1)
    return (1);
  return (0);
}

int	my_putstr(char *str)
{
  while (*(str++))
    if (my_putchar(*str) == 1)
      return (1);
  return (0);
}
