/*
** main.c for autocompletion in /home/salope_b//auto_completion
** 
** Made by brandon salopek
** Login   <salope_b@epitech.net>
** 
** Started on  Thu Jun  6 11:27:55 2013 brandon salopek
** Last update Sun Jun  9 19:06:26 2013 styve simonneau
*/

#include "protos.h"

char	*erase_multi_star(char *str)
{
  int	i;
  int	j;
  char	*tmp;

  tmp = malloc(sizeof(char) * (strlen(str) + 1));
  i = 0;
  j = 0;
  while (str[i] != '\0')
    {
      tmp[j] = str[i];
      if (str[i] == '*')
	while (str[i + 1] == '*')
	++i;
      ++i;
      ++j;
    }
  tmp[j] = '\0';
  free(str);
  return (tmp);
}

int	my_match(char *s1, char *s2)
{
  int	i1;
  int	i2;

  i1 = 0;
  i2 = 0;
  while (s2[i2] != '\0')
    {
      if (s2[i2] == '*')
	{
	  ++i2;
	  while (s1[i1] != s2[i2] && s1[i1] != '\0')
	    ++i1;
	}
      if (s1[i1] != s2[i2])
	return (0);
      else if (s1[i1] == '\0' && s2[i2] == '\0')
	return (1);
      ++i1;
      ++i2;
    }
  return (1);
}

char	*last_word(char *str)
{
  int	i;
  char	*last;

  i = 0;
  while (str[i] != '\0')
    ++i;
  --i;
  while ((str[i] == ' ' || str[i] == '\t') && i >= 0)
    --i;
  str[i + 1] = '\0';
  while ((str[i] != ' ' && str[i] != '\t') && i >= 0)
    --i;
  ++i;
  if ((last = strdup(&str[i])) == NULL)
    return (NULL);
  return (last);
}
