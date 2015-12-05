/*
** inter.c for rt in /home/corrad_f//rt
**
** Made by florian corradin
** Login   <corrad_f@epitech.net>
**
** Started on  Fri Apr 26 19:43:46 2013 florian corradin
** Last update Sat Apr 27 11:37:11 2013 florian corradin
*/

#include "raytracer.h"

double	get_good_k_res(t_solution s)
{
  if (s.delta >= 0)
    {
      if (s.a < 0 && s.b >= 0)
	return (s.b);
      else if (s.a >= 0 && s.b < 0)
	return (s.a);
      else if (s.a < s.b)
	return (s.a);
      else
	return (s.b);
    }
  else
    return (-1.0);
}

void	inter_plan(t_rt *list, t_object *obj, t_point ray)
{
  t_point	v;
  t_point	eye;

  v = ray;
  eye = list->eye->pos;
  rotate(obj->rot, &eye);
  rotate(obj->rot, &v);
  translate(obj->centre, &eye);
  obj->k = (obj->angle - eye.z) / v.z;
  obj->intersection.x = list->eye->pos.x + obj->k * ray.x;
  obj->intersection.y = list->eye->pos.y + obj->k * ray.y;
  obj->intersection.z = list->eye->pos.z + obj->k * ray.z;
  obj->n.x = 0;
  obj->n.y = 0;
  obj->n.z = 100; /* apliquer rot sur n */
}

void	inter_cone(t_rt *list, t_object *obj, t_point ray)
{
  t_point	v;
  t_point	eye;
  t_point	coef;
  t_solution	s;
  double	sq;

  sq = tan(obj->angle) * tan(obj->angle);
  v = ray;
  eye = list->eye->pos;
  rotate(obj->rot, &eye);
  rotate(obj->rot, &v);
  translate(obj->centre, &eye);
  coef.x = v.x * v.x + v.y * v.y - ((v.z * v.z) / sq);
  coef.y = 2 * (eye.x * v.x + eye.y * v.y - ((eye.z * v.z) / sq));
  coef.z = eye.x * eye.x + eye.y * eye.y - ((eye.z * eye.z) / sq);
  s = equation_second(coef);
  obj->k = get_good_k_res(s);
  obj->intersection.x = list->eye->pos.x + obj->k * ray.x;
  obj->intersection.y = list->eye->pos.y + obj->k * ray.y;
  obj->intersection.z = list->eye->pos.z + obj->k * ray.z;
  obj->n.x = obj->intersection.x; /* apliquer rot sur n */
  obj->n.y = obj->intersection.y;
  obj->n.z = -obj->angle * obj->intersection.z;
}

void	inter_cylindre(t_rt *list, t_object *obj, t_point ray)
{
  t_point	v;
  t_point	eye;
  t_point	coef;
  t_solution	s;

  v = ray;
  eye = list->eye->pos;
  rotate(obj->rot, &eye);
  rotate(obj->rot, &v);
  translate(obj->centre, &eye);
  coef.x = v.x * v.x + v.y * v.y;
  coef.y = 2 * (eye.x * v.x + eye.y * v.y);
  coef.z = eye.x * eye.x + eye.y * eye.y - (obj->r * obj->r);
  s = equation_second(coef);
  obj->k = get_good_k_res(s);
  obj->intersection.x = list->eye->pos.x + obj->k * ray.x;
  obj->intersection.y = list->eye->pos.y + obj->k * ray.y;
  obj->intersection.z = list->eye->pos.z + obj->k * ray.z;
  obj->n = obj->intersection; /* apliquer rot sur n */
  obj->n.z = 0.0;
}

void	inter_sphere(t_rt *list, t_object *obj, t_point ray)
{
  t_point	v;
  t_point	eye;
  t_point	coef;
  t_solution	s;

  v = ray;
  eye = list->eye->pos;
  rotate(obj->rot, &eye);
  rotate(obj->rot, &v);
  translate(obj->centre, &eye);
  coef.x = v.x * v.x + v.y * v.y + v.z * v.z;
  coef.y = 2 * (eye.x * v.x + eye.y * v.y + eye.z * v.z);
  coef.z = (eye.x * eye.x) + (eye.y * eye.y) + (eye.z * eye.z) - ((double)obj->r * (double)obj->r);
  s = equation_second(coef);
  obj->k = get_good_k_res(s);
  obj->intersection.x = list->eye->pos.x + obj->k * ray.x;
  obj->intersection.y = list->eye->pos.y + obj->k * ray.y;
  obj->intersection.z = list->eye->pos.z + obj->k * ray.z;
  obj->n = obj->intersection; /* apliquer rot sur n */
}
