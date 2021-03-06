/*
** raytracer.h for raytracer in /home/cheval_y//raytracer/includes
** 
** Made by franck chevallier
** Login   <cheval_y@epitech.net>
** 
** Started on  Tue Apr  9 14:25:15 2013 franck chevallier
** Last update Tue Apr 30 10:07:57 2013 antoine simon
*/

#ifndef RAYTRACER_H_
#define RAYTRACER_H_

#include <mlx.h>
#include <math.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"

#define WINDOW_X (1024)
#define WINDOW_Y (1024)
#define RAD(x) ((x * (3.14159265358979323846)) / 180)
#define SPHERE (1)
#define PLANE (2)
#define CONE (3)
#define CYLINDER (4)
#define EYE (5)
#define LIGHT (6)

/*manque les vecteur de l'oeil*/
typedef struct	s_point
{
  double	x;
  double	y;
  double	z;
}		t_point;

typedef struct	s_eye
{
  t_point	pos;
  t_point	rot;
}		t_eye;

typedef struct	s_solution
{
  double	a;
  double	b;
  double	delta;
}		t_solution;

typedef struct	s_object
{
  t_point	centre;
  double	angle;
  int		color;
  int		type;
  t_point	rot;
  int		r;
  double	k;
  t_point	n;
  t_point	intersection;
  struct s_object	*next;
}		t_object;

typedef struct	s_light
{
  int			color;
  t_point		pos;
  struct s_light	*next;
}		t_light;

typedef struct	s_rt
{
  t_object	*obj; /* contient la liste des objets */
  t_object	*select; /* contient l'objet le plus proche */
  t_eye		*eye;
  t_light	*light;
  void		*win_ptr;
  void		*mlx_ptr;
  void		*img;
  char		*data;
  int		bpp;
  int		sizeline;
  int		endian;
}		t_rt;

char    *get_next_value(char *line, int *i);
void    add_in_list(t_object *add, t_object *obj, int t);
void    pars_obj(char *line, int type, t_rt *r);
void    pars_light(char *line, int type, t_rt *r);
void    pars_eye(char *line, int type, t_rt *r);
t_rt    config(char *name, t_rt r);
void    add_in_list_light(t_light *add, t_light *obj, int t);
/* void            conf_file(t_rt *mlx, char *file); */
/* char            *get_next_line(const int fd); */
/* int             my_put_in_list(t_object **list, t_object *object); */
/* long int        my_strtol(const char *nptr, char *base); */
/* void            set_eye(t_rt *mlx, char **tab); */
/* void            set_light(t_rt *mlx, char **tab); */
/* int             set_object(char **tab, int type, t_object **list, t_rt *mlx); */
/* char            **str_to_wordtab(char *str); */
void	inter_plan(t_rt *list, t_object *obj, t_point ray);
void	inter_cone(t_rt *list, t_object *obj, t_point ray);
void	inter_cylindre(t_rt *list, t_object *obj, t_point ray);
void	inter_sphere(t_rt *list, t_object *obj, t_point ray);
t_solution	equation_second(t_point c);
void		throw_ray(t_rt *obj, t_point ray);
t_point		get_eye_ray(t_rt *obj, int x, int y);
void		get_pixel_color(t_rt *obj, int x, int y);
void	calcul(t_rt *obj);
double	get_good_k_res(t_solution s);
void    open_window(t_rt *mini);
int     put_img(t_rt *mini);
char    *my_pixel_put_to_image(int x, int y, t_rt *mini, int coulor);
int     event_key(int key, t_rt *mini);
int	my_putchar(char c);
void	my_putstr(char *str);
void	translate(t_point t, t_point *v);
void    normaliser(t_point *v);
void	rotate(t_point rot, t_point *ray);

#endif
