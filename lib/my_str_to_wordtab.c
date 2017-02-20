/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/simonn_s//piscine/Jour_08/ex_04
**
** Made by styve simonneau
** Login   <simonn_s@epitech.net>
**
** Started on  Fri Oct 12 10:15:16 2012 styve simonneau
** Last update Sun May 26 22:09:39 2013 Styve Simonneau
*/

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int	is_delim(char c, char *delim)
{
  int	i;

  i = -1;
  while (delim[++i])
    if (c == delim[i])
      return (1);
  return (0);
}

char	*my_strdup_word(char *src, char *delim)
{
  char	*str;
  int	size;
  int	i;
  int	index;

  size = 0;
  i = 0;
  while (src[i] && is_delim(src[i], delim) == 1)
    i = i + 1;
  index = i;
  while (src[i] && is_delim(src[i], delim) == 0)
    {
      size++;
      i = i + 1;
    }
  if (!(str = malloc(size + 1)))
    return (NULL);
  str = strncpy(str, &src[index], size);
  str[size] = '\0';
  return (str);
}

int	count_words_to_malloc(char *str, char *delim)
{
  int	i;
  int	count;

  i = 0;
  count = 0;
  while (str[i])
    {
      while (str[i] && is_delim(str[i], delim) == 1)
	i++;
      count++;
      while (str[i] && is_delim(str[i], delim) == 0)
	i++;
      while (str[i] && is_delim(str[i], delim) == 1)
	i++;
    }
  return (count);
}

void	next_i(char *str, int *i, char *delim)
{
  while (str[*i] && is_delim(str[*i], delim) == 1)
    *i = *i + 1;
  while (str[*i] && is_delim(str[*i], delim) == 0)
    *i = *i + 1;
}

char	**my_str_to_wordtab(char *str, char *delim)
{
  int	word;
  char	**copy;
  int	i;
  int	length;

  i = 0;
  word = 0;
  length = count_words_to_malloc(str, delim);
  if (!(copy = malloc(sizeof(char *) * (length + 1))))
    return (NULL);
  while (word < length)
    {
      if (!(copy[word] = my_strdup_word(&str[i], delim)))
	return (NULL);
      next_i(str, &i, delim);
      word++;
    }
  copy[word] = NULL;
  return (copy);
}
