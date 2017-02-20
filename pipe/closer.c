/*
** closer.c for 42sh in /home/salope_b//42sh-2017-simonn_s/test/42sh-2017-simonn_s
**
** Made by brandon salopek
** Login   <salope_b@epitech.net>
**
** Started on  Sun May 26 09:58:57 2013 brandon salopek
** Last update Sun May 26 22:45:37 2013 pierre hofman
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "pipes.h"
#include "error.h"
#include "my.h"

int	**close_execption(int **pipe, int no)
{
  int	i;

  i = -1;
  while (pipe[++i] != NULL)
    {
      if (i != no)
	{
	  if (close(pipe[i][0]) == -1 || close(pipe[i][1]) == -1)
	    {
	      my_error_(4);
	      return (NULL);
	    }
	}
    }
  return (pipe);
}

int	**close_pipe(int **pipe)
{
  int	i;

  i = -1;
  while (pipe[++i] != NULL)
    {
      if ((close(pipe[i][0])) == -1 || close(pipe[i][1]) == -1)
	{
	  my_error_(0);
	  return (NULL);
	}
    }
  return (pipe);
}
