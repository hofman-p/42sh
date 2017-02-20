/*
** my_strcmp.c for my_strcmp in /home/simonn_s//piscine/Jour_06/ex_05
**
** Made by styve simonneau
** Login   <simonn_s@epitech.net>
**
** Started on  Mon Oct  8 19:28:42 2012 styve simonneau
** Last update Tue Nov 20 11:30:21 2012 styve simonneau
*/

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] != '\0')
    {
      if (s1[i] == s2[i])
	i++;
      if (s1[i] != s2[i])
	return (s1[i] - s2[i]);
    }
  return (0);
}

int	my_cstrcmp(char *s1, const char *s2)
{
  int	i;

  i = 0;
  while (s1[i] != '\0')
    {
      if (s1[i] == s2[i])
	i++;
      if (s1[i] != s2[i])
	return (s1[i] - s2[i]);
    }
  return (0);
}
