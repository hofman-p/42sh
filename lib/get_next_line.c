/*
** get_next_line.c for rtv1 in /home/simonn_s//TP/RTv1
**
** Made by styve simonneau
** Login   <simonn_s@epitech.net>
**
** Started on  Tue Feb 12 10:38:42 2013 styve simonneau
** Last update Mon Jun  3 16:00:00 2013 styve simonneau
*/

#include <stdlib.h>
#include <unistd.h>
#include "protos.h"

char     *add_to_line(char *line, int pos, char *buff, int *beg)
{
  char          *new_elem;
  int           old_len;

  old_len = (line) ? strlen(line) : 0;
  if (!(new_elem = malloc((old_len + pos + 1) * sizeof(*new_elem))))
    my_error(1);
  strncpy(new_elem, line ? line : "", old_len);
  strncpy(new_elem + old_len, buff + *beg, pos);
  new_elem[old_len + pos] = 0;
  if (line)
    free(line);
  *beg += pos + 1;
  return (new_elem);
}

char            *get_next_line(const int fd)
{
  static char   buff[256 + 1];
  static int    beg;
  static int    countbuff = 0;
  char          *line;
  int           pos;

  line = 0;
  pos = 0;
  while (1)
    {
      if (beg >= countbuff)
        {
          beg = 0;
          if (!(countbuff = read(fd, buff, 256)))
            return (line);
          if (countbuff == -1)
            return (NULL);
          pos = 0;
        }
      if (buff[beg + pos] == '\n')
        return (line = add_to_line(line, pos, buff, &beg));
      if (beg + pos == countbuff - 1)
        line = add_to_line(line, pos + 1, buff, &beg);
      ++pos;
    }
}
