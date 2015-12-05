/*
** tools.c for rt in /home/corrad_f//rt
**
** Made by florian corradin
** Login   <corrad_f@epitech.net>
**
** Started on  Fri Apr 26 18:22:32 2013 florian corradin
** Last update Sat Apr 27 11:41:45 2013 florian corradin
*/

#include "raytracer.h"

void	translate(t_point t, t_point *v)
{
  v->x += t.x;
  v->y += t.y;
  v->z += t.z;
}

void            normaliser(t_point *v)
{
  double        norme;

  norme = sqrt(v->x * v->x + v->y * v->y + v->z * v->z);
  v->x = v->x / norme;
  v->y = v->y / norme;
  v->z = v->z / norme;
}


double		calc_scal(t_point v, t_point v2)
{
  double	n1;
  double	n2;
  double	ret;
  double	scal;

  scal = v.x * v2.x + v.y * v2.y + v.z * v2.z;
  n1 = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
  n2 = sqrt(v2.x * v2.x + v2.y * v2.y + v2.z * v2.z);
  ret = scal / (n1 * n2);
  return (ret);
}

void			rotate(t_point rot, t_point *ray)
{
  t_point		s;
  double		a;
  double		b;
  double		c;
  double		d;
  double		e;
  double		f;

  a = cos(rot.x);
  b = sin(rot.x);
  c = cos(rot.y);
  d = sin(rot.y);
  e = cos(rot.z);
  f = sin(rot.z);
  s = *ray;
  ray->y = ray->y * a - ray->z * b;
  ray->z = s.y * b + ray->z * a;
  s = *ray;
  ray->x = ray->x * c + ray->z * d;
  ray->z = -s.x * d + ray->z * c;
  s = *ray;
  ray->x = ray->x * e - ray->y * f;
  ray->y = s.x * f + ray->y * e;
}

void		get_the_rot(double *mat, t_point *v)
{
  t_point	s;

  s = *v;
  v->x = mat[0] * s.x + mat[1] * s.y + mat[2] * s.z;
  v->y = mat[3] * s.x + mat[4] * s.y + mat[5] * s.z;
  v->z = mat[6] * s.x + mat[7] * s.y + mat[8] * s.z;
}

void		my_rotation2(t_point *v, t_point *rot)
{
  double	a;
  double	b;
  double	c;
  double	d;
  double	e;
  double	f;
  double	mat[9];

  a = cos(rot->x);
  b = sin(rot->x);
  c = cos(rot->y);
  d = sin(rot->y);
  e = cos(rot->z);
  f = sin(rot->z);
  mat[0] = c * e;
  mat[1] = -c * f;
  mat[2] = -d;
  mat[3] = -b * d * e + a * f;
  mat[4] = -b * d * f + a * e;
  mat[5] = -b * c;
  mat[6] = a * d * e + b * f;
  mat[7] = -a * d * f + b * e;
  mat[8] = a * c;
  get_the_rot(mat, v);
}
