/*
** my_putstr.c for lib in /home/corrad_f//rt
**
** Made by florian corradin
** Login   <corrad_f@epitech.net>
**
** Started on  Fri Apr 26 18:02:05 2013 florian corradin
** Last update Tue Apr 30 09:08:09 2013 antoine simon
*/

#include "raytracer.h"

int	my_strlen(char *c)
{
  int	i;

  i = 0;
  while (c[i])
    {
      i++;
    }
  return (i);
}

int	my_putchar(char c)
{
  return (write(1, &c, 1));
}

void	my_putstr(char *str)
{
  while (my_putchar(*str) && *str++);
}
