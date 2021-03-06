/*
** main.c for rt in /home/simon_o//scratch
**
** Made by antoine simon
** Login   <simon_o@epitech.net>
**
** Started on  Fri Apr 26 13:41:00 2013 antoine simon
** Last update Tue Apr 30 09:23:00 2013 antoine simon
*/

#include "raytracer.h"

void    open_window(t_rt *mini)
{
  if ((mini->mlx_ptr = mlx_init()) == NULL)
    exit(0);
  mini->win_ptr = mlx_new_window(mini->mlx_ptr, WINDOW_X, WINDOW_Y,
				 " //!\\\\ RT by Vallium's TEAM //!\\\\");
  mini->img = mlx_new_image(mini->mlx_ptr, WINDOW_X, WINDOW_Y);
}

int     put_img(t_rt *mini)
{
  mlx_put_image_to_window(mini->mlx_ptr, mini->win_ptr, mini->img, 0, 0);
  return (0);
}

char            *my_pixel_put_to_image(int x, int y, t_rt *mini,
				       int coulor)
{
  char          *color;

  color = (char *)&coulor;
  if ((x < WINDOW_X && x >= 0.f) && (y < WINDOW_Y && y >= 0.f))
    {
      mini->data[y * mini->sizeline + x * (mini->bpp / 8)] = color[0];
      mini->data[y * mini->sizeline + x * (mini->bpp / 8) + 1] = color[1];
      mini->data[y * mini->sizeline + x * (mini->bpp / 8) + 2] = color[2];
    }
  return (NULL);
}

int     event_key(int key, t_rt *mini)
{
  if (key == 65307)
    {
      mlx_destroy_window(mini->mlx_ptr, mini->win_ptr);
      exit(0);
    }
  return (0);
}

int	main(int ac, char **av)
{
  t_rt	mlx;

  if (ac < 2)
    {
      my_putstr("Usage : ./rt [scene].cfg\n");
      return (0);
    }
  open_window(&mlx);
  mlx_key_hook(mlx.win_ptr, &event_key, &mlx);
  mlx.data = mlx_get_data_addr(mlx.img, &mlx.bpp, &mlx.sizeline, &mlx.endian);
  mlx = config(av[1], mlx);
  calcul(&mlx);
  mlx_expose_hook(mlx.win_ptr, &put_img, &mlx);
  mlx_do_sync(mlx.mlx_ptr);
  mlx_loop(mlx.mlx_ptr);
  return (0);
}
