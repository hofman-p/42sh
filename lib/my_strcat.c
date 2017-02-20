/*
** my_strcat.c for my_strcat in /home/salope_b//prog/my_lib
**
** Made by brandon salopek
** Login   <salope_b@epitech.net>
**
** Started on  Tue Oct  9 17:47:49 2012 brandon salopek
** Last update Sun May 26 21:39:03 2013 Styve Simonneau
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char	*my_strcat(char *dest, char *src)
{
  int	x;
  int	y;

  y = 0;
  x = 0;
  while (dest[x] != '\0')
    x++;
  while (src[y] != '\0')
    {
      dest[x] = src[y];
      x = x + 1;
      y = y + 1;
    }
  dest[x] = '\0';
  return (dest);
}

char	*my_strcat_2(char *dest, char *src)
{
  char	*tmp;
  int	s;

  if (dest != NULL)
    {
      tmp = strdup(dest);
      s = strlen(src) + strlen(tmp);
      if ((dest = malloc(sizeof(char) * s)) == NULL)
	printf("erreur malloc\n");
      dest[0] = '\0';
      dest = strcat(dest, tmp);
      dest = strcat(dest, src);
      dest = strcat(dest, "\n");
    }
  else
    {
      s = strlen(src);
      if ((dest = malloc(sizeof(char) * s)) == NULL)
	printf("erreur malloc\n");
      dest[0] = '\0';
      dest = strcat(dest, src);
      dest = strcat(dest, "\n");
    }
  return (dest);
}
