/*
** get_next_line.c for raytracer in /home/cheval_y//raytracer
** 
** Made by franck chevallier
** Login   <cheval_y@epitech.net>
** 
** Started on  Tue Apr  9 15:20:01 2013 franck chevallier
** Last update Thu Apr 11 15:54:37 2013 franck chevallier
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"get_next_line.h"

char	*my_strcat(char *s1, char *s2)
{
  int	cnt;
  int	index;

  index = my_strlen(s1);
  cnt = 0;
  while (s2[cnt] != '\0')
    {
      s1[index + cnt] = s2[cnt];
      cnt++;
    }
  s1[index + cnt] = '\0';
  return (s1);
}

char	*my_realloc(char *str, int size)
{
  char	*new_str;

  if (size == 0)
    return (str);
  new_str = malloc((my_strlen(str) + size + 1) * sizeof(*str));
  if (new_str == NULL)
    return (NULL);
  *new_str = '\0';
  my_strcat(new_str, str);
  *str = '\0';
  free(str);
  return (new_str);
}

int	next_line(char *line, char *buff)
{
  int	nb;

  nb = 0;
  while (line[nb] != '\0')
    {
      if (line[nb] == '\n')
	{
	  line[nb] = '\0';
	  *buff = '\0';
	  my_strcat(buff, &line[nb + 1]);
	  return (-1);
	}
      nb++;
    }
  *buff = '\0';
  return (0);
}

char		*get_next_line(const int fd)
{
  int		i;
  char		*line;
  static char	buff[BUFF];

  line = malloc(BUFF * sizeof(*line));
  if (fd < 0)
    return (NULL);
  *line = '\0';
  my_strcat(line, buff);
  *buff = '\0';
  i = READ;
  while (next_line(line, buff) != -1 && i == READ)
    {
      i = read(fd, buff, READ);
      if (i == -1)
	return (NULL);
      buff[i] = '\0';
      line = my_realloc(line, i);
      my_strcat(line, buff);
    }
  if (*line == '\0' && my_strlen(buff) == 0 && i != READ)
    return (0);
  return (line);
}
