/*
** my_getnbr.c for my_getnbr in /home/simonn_s/
**
** Made by styve simonneau
** Login   <simonn_s@epitech.net>
**
** Started on  Mon Oct 22 14:52:57 2012 styve simonneau
** Last update Thu Mar 14 21:14:17 2013 Styve Simonneau
*/

void	post(char *p_str, int *p_neg, int *p_stat)
{
  if (*p_str == 45 || *p_str == 43)
    {
      if (*p_str == 45)
	*p_neg = 0 - *p_neg;
    }
  else
    *p_stat = 0;
}

void	toobig(char *p_str, int *p_stat, int *p_neg, int *p_nbr)
{
  if (*p_nbr >= 214748364 && *p_neg == 1 && *p_str > 55)
    {
      *p_stat = 0;
      *p_nbr = 0;
    }
  if (*p_nbr >= 214748364 && *p_neg == -1 && *p_str > 56)
    {
      *p_stat = 0;
      *p_nbr = 0;
    }
  if (*p_nbr >= 1000000000)
    {
      *p_stat = 0;
      *p_nbr = 0;
    }
}

int	makeint(char *p_str, int *p_stat, int *p_neg)
{
  int	nbr;

  nbr = 0;
  while (*p_str > 47 && *p_str < 58 && *p_stat == 2)
    {
      toobig(p_str, p_stat, p_neg, &nbr);
	if (*p_stat == 2)
	  {
	    nbr = nbr * 10;
	    nbr = nbr + (*p_str - '0');
	    p_str = p_str + 1;
	  }
    }
  return (nbr);
}

int	my_getnbr(char *str)
{
  int	nb;
  int	stat;
  int	neg;

  stat = 1;
  neg = 1;
  while (*str != 0 && stat == 1)
    {
      if (*str < '0' || *str > '9')
	post(str, &neg, &stat);
      else
	stat = 2;
      str++;
    }
  nb = makeint(str - 1, &stat, &neg);
  return (nb * neg);
}
