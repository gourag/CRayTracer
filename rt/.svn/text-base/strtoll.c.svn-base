/*
** strtoll.c for lib in /home/corrad_f//lib/standart
**
** Made by florian corradin
** Login   <corrad_f@epitech.net>
**
** Started on  Sat Apr 27 18:58:52 2013 florian corradin
** Last update Mon Apr 29 21:13:40 2013 florian corradin
*/

#include "type.h"

int	digit(char *base, char c)
{
  int	i;

  i = 0;
  while (base[i] != c && base[i] != '\0')
    i++;
  return (base[i] == '\0' ? 0 : i);
}

int my_strtol(const char *nptr, char *base)
{
  long long int	a;
  char		c;

  a = 0;
  if (*nptr == '-')
    return (-my_strtoll(&nptr[1], base));
  while ((c = *nptr++) != '\0' && is_digit(c))
    a = a * my_strlen(base) + digit(base, c);
  return (a);
}
