/*
** replace_with_alias.c for 42 in /home/simonn_s//svn/42sh-2017-simonn_s
** 
** Made by styve simonneau
** Login   <simonn_s@epitech.net>
** 
** Started on  Tue Jun  4 17:24:29 2013 styve simonneau
** Last update Tue Jun  4 22:34:41 2013 styve simonneau
*/

#include "protos.h"

int	count_in_tab(char **tab)
{
  int	i;

  i = -1;
  while (tab[++i]);
  return (i);
}

void	replace_by_alias(char *alias, char ***tab, int *j, char *cmd)
{
  char	**alias_tab;
  char	**ctab;
  int	cnt;
  int	cnt2;
  int	i;
  int	n;

  i = -1;
  ctab = my_str_to_wordtab(cmd, " \t");
  alias_tab = my_str_to_wordtab(alias, " \t");
  cnt = count_in_tab(alias_tab);
  cnt2 = count_in_tab(ctab);
  if (!(tab[0] = realloc(tab[0], sizeof(char *) * (cnt + cnt2 + 1))))
    my_error(1);
  n = *j;
  --*j;
  while (alias_tab[++i])
    tab[0][++*j] = alias_tab[i];
  while (ctab[++n])
    tab[0][++*j] = ctab[n];
  tab[0][++*j] = NULL;
  --*j;
}

char	*replace_with_alias(char ***alias, char *cmd)
{
  char	*newcmd;
  char	**tab;
  int	i;
  int	j;

  i = -1;
  tab = my_str_to_wordtab(cmd, " \t");
  while (alias[++i])
    {
      j = -1;
      while (tab[++j])
	if (strcmp(alias[i][0], tab[j]) == 0)
	  replace_by_alias(alias[i][1], &tab, &j, cmd);
    }
  newcmd = get_line(tab, -1);
  return (newcmd);
}
