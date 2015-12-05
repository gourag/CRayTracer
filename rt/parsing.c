/*
** parsing.c for rt in /home/corrad_f//rt
**
** Made by florian corradin
** Login   <corrad_f@epitech.net>
**
** Started on  Mon Apr 29 19:52:55 2013 florian corradin
** Last update Tue Apr 30 10:40:12 2013 antoine simon
*/

#define PARS_H

#include "raytracer.h"

typedef void (*t_pars)(char *, int, t_rt *);

typedef struct s_type
{
  char		*name;
  int		t;
  t_pars	fct;
}		t_type;

/* typedef struct s_type t_type; */
t_type	g_type[50];
g_type[1] = 
  /* { */
  /*   {"s", 1, &pars_obj}, */
  /*   {"plan", 2, &pars_obj}, */
  /*   {"cone", 3, &pars_obj}, */
  /*   {"cyl", 4, &pars_obj}, */
  /*   {"eye", 5, &pars_eye}, */
  /*   {"light", 6, &pars_light}, */
  /*   {0,0} */
  /* }; */

char	*get_next_value(char *line, int *i)
{
  while (line[*i] && line[*i] != ' ' && line[*i] != '\t' && line[*i] != ',')
    *i = *i + 1;
  while (line[*i] == ' ' || line[*i] == '\t' || line[*i] == ',')
    *i = *i + 1;
  return (&line[*i]);
}

void	add_in_list(t_object *add, t_object *obj, int t)
{
  t_object	*tmp;

  tmp = obj;
  add->next = NULL;
  if (!obj)
    obj = add;
  else
    while (tmp->next != NULL)
      tmp = tmp->next;
  tmp->next = add;
}

void    add_in_list_light(t_light *add, t_light *obj, int t)
{
  t_light  *tmp;

  tmp = obj;
  add->next = NULL;
  if (!obj)
    obj = add;
  else
    while (tmp->next)
	    tmp = tmp->next;
  tmp->next = add;
}

void	pars_obj(char *line, int type, t_rt *r)
{
  t_object	*add;
  int	i;

  i = 0;
  add = malloc(sizeof(t_object));
  add->type = type;
  add->centre.x = my_atof(get_next_value(line, &i));
  add->centre.y = my_atof(get_next_value(line, &i));
  add->centre.z = my_atof(get_next_value(line, &i));
  add->rot.x = my_atof(get_next_value(line, &i));
  add->rot.y = my_atof(get_next_value(line, &i));
  add->rot.z = my_atof(get_next_value(line, &i));
  add->color = my_strtol(get_next_value(line, &i), "0123456789ABCDEF");
  add->r = ((type == SPHERE || type == CYLINDER) ? my_atoi(get_next_value(line, &i)) : 0);
  add->angle = (type == CONE ? RAD(my_atof(get_next_value(line, &i))) : 0.0);
  add_in_list(add, r->obj, 1);
}

void	pars_light(char *line, int type, t_rt *r)
{
  t_light	*add;
  int		i;

  i = 0;
  add = malloc(sizeof (t_light));
  add->pos.x = my_atof(get_next_value(line, &i));
  add->pos.y = my_atof(get_next_value(line, &i));
  add->pos.z = my_atof(get_next_value(line, &i));
  add->color = my_strtol(get_next_value(line, &i), "0123456789ABCDEF");
  add_in_list_light(add, r->light, 0);
}

void	pars_eye(char *line, int type, t_rt *r)
{
  int	i;

  i = 0;
  r->eye->rot.x = my_atof(get_next_value(line, &i));
  r->eye->rot.y = my_atof(get_next_value(line, &i));
  r->eye->rot.z = my_atof(get_next_value(line, &i));
  r->eye->pos.x = my_atof(get_next_value(line, &i));
  r->eye->pos.y = my_atof(get_next_value(line, &i));
  r->eye->pos.z = my_atof(get_next_value(line, &i));
}

t_rt	config(char *name, t_rt r)
{
  int	fd;
  char	*line;
  int	boacontructor;
  int	i;

  i = 0;
  boacontructor = -1;
  if ((fd = open(name, O_RDONLY)) == -1)
    my_put_error("No such file or directory\n");
  while ((line = get_next_line(fd)) != NULL)
    {
      while (g_type[i] != (t_type)NULL)
	{
	  if (my_strncmp(g_type[i], line, my_strlen(line)))
	    {
	      (*(g_type[i].fct))(line, g_type[i].t, &r);
	    }
	  i++;
	}
      free(line);
    }
  return (r);
}
