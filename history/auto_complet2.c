/*
** main.c for autocompletion in /home/salope_b//auto_completion
** 
** Made by brandon salopek
** Login   <salope_b@epitech.net>
** 
** Started on  Thu Jun  6 11:27:55 2013 brandon salopek
** Last update Sun Jun  9 19:05:48 2013 styve simonneau
*/

#include "protos.h"

char	*check_directory(char *dir, char *path)
{
  int	i;

  i = 0;
  while (path[i] != '\0' && path[i] != '/')
    ++i;
  if (path[i] != '\0')
    {
      free(dir);
      i = 0;
      while (path[i + 1] != '\0')
	++i;
      while (path[i] != '/')
	--i;
      if ((dir = strndup(path, i)) == NULL)
	return (NULL);
    }
  return (dir);
}

void	check_in_directory(DIR *dir, char *path)
{
  struct dirent	*ret;
  int		count;
  int		matched;

  count = 0;
  while ((ret = readdir(dir)) != NULL)
    {
      if ((matched = my_match(ret->d_name, path)) == 1 && count == 0)
	{
	  ++count;
	  printf("%s", ret->d_name);
	}
      else if (matched == 1)
	{
	  ++count;
	  printf("\t%s", ret->d_name);
	}
    }
  printf("\n");
}

int	check_complet(char *dir, char *path)
{
  DIR	*ret;

  printf("\n");
  fflush(stdout);
  ret = opendir(dir);
  if (ret != NULL)
    {
      check_in_directory(ret, path);
      closedir(ret);
    }
  else
    printf("\nouverture fail\n");
  return (0);
}

char	*check_pathern(char *path, char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    ++i;
  while (i >= 0 && str[i] != '/')
    --i;
  if (i >= 0)
    {
      path = strdup(&str[i + 1]);
      return (path);
    }
  return (NULL);
}

int	auto_complet(char *str)
{
  char	*pathern;
  char	*directory;
  char	*last_w;

  pathern = NULL;
  if (((directory = strdup("."))) == NULL)
    return (-1);
  if ((last_w = last_word(str)) == NULL)
    return (-1);
  directory = check_directory(directory, last_w);
  if ((pathern = check_pathern(pathern, last_w)) == NULL)
    pathern = last_w;
  pathern = erase_multi_star(pathern);
  check_complet(directory, pathern);
  printf("$>%s", str);
  fflush(stdout);
  return (1);
}
