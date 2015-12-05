/*
** calc_all.c for rt in /home/corrad_f//rt
**
** Made by florian corradin
** Login   <corrad_f@epitech.net>
**
** Started on  Fri Apr 26 18:08:08 2013 florian corradin
** Last update Mon Apr 29 14:27:02 2013 antoine simon
*/

#include "raytracer.h"

typedef void (*t_fptr)(t_rt *, t_object *, t_point);

t_object	*get_closest_obj(t_object *obj)
{
  t_object	*ret;

  ret = obj;
  while (obj)
    {
      if (ret->k < 0)
	ret = obj;
      else if (obj->k >= 0 && obj->k < ret->k)
	ret = obj;
      obj = obj->next;
    }
  return (ret);
}

void		throw_ray(t_rt *obj, t_point ray)
{
  t_fptr	ftab[4];
  t_object	*tmp;

  tmp = obj->obj;
  ftab[0] = &inter_sphere;
  ftab[1] = &inter_plan;
  ftab[2] = &inter_cylindre;
  ftab[3] = &inter_cone;
  while (tmp)
    {
      (*(ftab[(int)tmp->type]))(obj, tmp, ray);
      tmp = tmp->next;
    }
  obj->select = get_closest_obj(obj->obj);
}

t_point		get_eye_ray(t_rt *obj, int x, int y)
{
  t_point	ray;

  ray.x = (100.0 - obj->eye->pos.x);
  ray.y = (WINDOW_X / 2.0 - (double)x) - obj->eye->pos.y;
  ray.z = (WINDOW_Y / 2.0 - (double)y) - obj->eye->pos.z;
  normaliser(&ray);
  return (ray);
}

void		get_pixel_color(t_rt *obj, int x, int y)
{
  t_point	ray;

  ray = get_eye_ray(obj, x, y);
  rotate(obj->eye->rot, &ray);
  throw_ray(obj, ray);
}

void	calcul(t_rt *obj)
{
  int	x;
  int	y;

  y = 0;
  while (y < WINDOW_Y)
    {
      x = 0;
      while (x < WINDOW_X)
	{
	  get_pixel_color(obj, x, y);
	  //my_pixel_put_to_image();
	  x++;
	}
      y++;
    }
}
