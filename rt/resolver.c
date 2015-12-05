/*
** resolver.c for rt in /home/corrad_f//rt
**
** Made by florian corradin
** Login   <corrad_f@epitech.net>
**
** Started on  Fri Apr 26 21:41:09 2013 florian corradin
** Last update Sat Apr 27 11:23:02 2013 florian corradin
*/

#include "raytracer.h"

t_solution	equation_second(t_point c)
{
  double	sq;
  t_solution	ret;

  ret.a = 0;
  ret.b = 0;
  ret.delta = (c.y * c.y) - (4 * c.x * c.z);
  if (ret.delta >= 0)
    {
      sq = sqrt(ret.delta);
      ret.a = (-c.y + sq) / (2 * c.x);
      ret.b = (-c.y - sq) / (2 * c.x);
    }
  return (ret);
}
