/*
** parser.c for 42sh in /home/switi/svn/perso/42sh-2017
**
** Made by Styve Simonneau
** Login   <simonn_s@epitech.net>
**
** Started on  Thu Mar 14 20:27:19 2013 Styve Simonneau
** Last update Tue Jun  4 22:35:35 2013 styve simonneau
*/

#include <stdio.h>
#include "protos.h"
#include "pipes.h"

int			check_builtin(t_msh *pt, char **cmd, int n)
{
  static const char	*bins[] = {"setenv", "unsetenv", "env", "cd", "echo",
				   "alias", "source", NULL};
  static const fct	tab[] = {exec_setenv, exec_unsetenv, exec_env, exec_cd,
				 exec_echo, exec_alias, exec_source};
  int			i;

  i = -1;
  if (cmd[0])
    {
      while (bins[++i])
	if (strcmp(bins[i], cmd[0]) == 0)
	  return (tab[i](pt, cmd, n));
      if (strcmp(cmd[0], "exit") == 0)
	{
	  if (cmd[1])
	    pt->exit = my_getnbr(cmd[1]) % 256;
	  else
	    pt->exit = 0;
	  return (-1);
	}
    }
  return (1);
}

int	command(t_msh *pt, char *cmd)
{
  int	value;
  int	i;

  i = -1;
  while (cmd[++i] != '\0' && cmd[i] == ' ');
  if (cmd[i] == '\0')
    return (257);
  cmd = analyze_string(pt, cmd);
  cmd = replace_with_alias(pt->alias, cmd);
  if ((value = operand_exec(strdup(cmd), pt)) == 42)
    return (-1);
  else
    return (0);
}

int	separate(t_msh *pt, char *s)
{
  char	**instructions;
  int	i;
  int	value;

  i = -1;
  instructions = my_str_to_wordtab(s, ";\n");
  my_free(s);
  my_putchar('\n');
  while (instructions[++i])
    {
      pt->av = my_str_to_wordtab(instructions[i], " \t");
      if ((value = command(pt, instructions[i])) == -1)
	return (pt->exit);
    }
  return (256);
}
