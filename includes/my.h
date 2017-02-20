/*
** my.h for my.h in /home/simonn_s//include
**
** Made by styve simonneau
** Login   <simonn_s@epitech.net>
**
** Started on  Thu Oct 11 11:33:56 2012 styve simonneau
** Last update Sun May 26 22:03:04 2013 Styve Simonneau
*/

#ifndef MY_H_
# define MY_H_

# include "struct.h"

void	my_putchar(char);
char	**my_str_to_wordtab(char *, char *);
void	my_putstr(char *);
int	my_getnbr(char *);
int	my_cstrcmp(char *, const char *);
char	*get_next_line(const int);
int	is_delim(char c, char *);
char	*my_strdup_word(char *, char *);
int	count_words_to_malloc(char *, char *);
void	next_i(char *, int *, char *);
char	*my_strcat_2(char *, char *);
char	*create_path(char *, char *);
int	size_tab(char **);
int	**close_execption(int **, int);
int	**close_pipe(int **);
int	exec_one(char **, t_msh *);
int	pars_in_out(char **);
int	my_error(int);

#endif /* !MY_H_ */
