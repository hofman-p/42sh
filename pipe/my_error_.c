/*
** my_error_.c for 42sh in /home/salope_b//42sh-2017-simonn_s/test/toto/42sh-2017-simonn_s
** 
** Made by brandon salopek
** Login   <salope_b@epitech.net>
** 
** Started on  Sun May 26 20:51:46 2013 brandon salopek
** Last update Sun May 26 20:53:47 2013 brandon salopek
*/

#include <stdlib.h>
#include <stdio.h>
#include "pipes.h"
#include "my.h"

void	fork_err()
{
  write(2, "fork error\n", 11);
}

void	pipe_err()
{
  write(2, "pipe error\n", 11);
}

void	malloc_err()
{
  write(2, "error malloc\n", 12);
}

void	dup_err()
{
  write(2, "dup error\n", 10);
}

void	close_err()
{
  write(2, "close error\n", 11);
}
