/*
** operand_cond.c for 42sh in /home/salope_b//42sh/pipe_inf
** 
** Made by brandon salopek
** Login   <salope_b@epitech.net>
** 
** Started on  Fri May 24 11:25:15 2013 brandon salopek
** Last update Sun May 26 17:32:07 2013 brandon salopek
*/

#include <string.h>
#include "pipes.h"
#include "my.h"

int	verif_cmd(char *cmd)
{
  int	i;

  i = -1;
  while (cmd[++i] != '\0' && cmd[i] == ' ');
  if (cmd[i] == '\0')
    return (-1);
  else
    return (0);
}

int	check_and_and(int ret, char *cmd, t_msh *msh, int i)
{
  char	*new;

  if ((new = strndup(cmd, i - 1)) == NULL)
    return (my_error_(3));
  else if (verif_cmd(new) == -1)
    return (-1);
  ret = check_pipe(msh, new);
  if ((ret != 0 && ret != -1) || ret == 42)
    return (0);
  else if (ret == -1)
    return (-1);
  return (1);
}

int	check_or_or(int ret, char *cmd, t_msh *msh, int i)
{
  char	*new;

  if ((new = strndup(cmd, i - 1)) == NULL)
    return (my_error(3));
  else if (verif_cmd(new) == -1)
    return (-1);
  ret = check_pipe(msh, new);
  if (ret == 0 || ret == 42)
    return (0);
  else if (ret == -1)
    return (-1);
  return (1);
}

int	operand_exec(char *cmd, t_msh *msh)
{
  int	i;
  int	ret;

  i = 0;
  while (cmd[++i] != '\0')
    {
      if (cmd[i] == '&' && cmd[i - 1] == '&' && cmd[i + 1] == ' ')
      	{
	  if ((ret = check_and_and(ret, cmd, msh, i)) != 1)
	    return (ret);
      	  cmd = cmd + i + 2;
      	  i = -1;
      	}
      else if (cmd[i] == '|' && cmd[i - 1] == '|' && cmd[i + 1] == ' ')
      	{
	  if ((ret = check_or_or(ret, cmd, msh, i)) != 1)
	    return (ret);
      	  cmd = cmd + i + 2;
      	  i = -1;
      	}
    }
  if (cmd[0] != '\0')
    return (check_pipe(msh, cmd));
  return (1);
}
