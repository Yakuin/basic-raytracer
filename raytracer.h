/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 14:21:52 by yboualla          #+#    #+#             */
/*   Updated: 2016/09/20 15:52:10 by yboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdio.h>
# include <stdbool.h>
# include <math.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <mlx.h>

# define BG_COLOR 0x3399ff //r51 g153 b255, might be handy later (unused atm)
# define WIN_WIDTH 1000
# define WIN_HEIGHT 1000
# define FOV 90

typedef struct  s_vector3
{
    double		x;
	double		y;
	double		z;
}               t_vector3;

typedef struct	s_sphere
{
    t_vector3	pos;
    double		radius;
}				t_sphere;

typedef struct	s_ray
{
    t_vector3	ori;
    t_vector3	dir;
}				t_ray;

typedef struct	s_camera
{
    t_vector3	pos;
    t_vector3	dir;
    double		foc_dist;
}				t_camera;

typedef struct		s_img
{
	void			*data;
	int				bpp;
	int				size;
	int				endian;
}					t_img;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	t_img		*img;
	char		*buf;
    t_camera	cam;
    t_sphere	s;
}				t_env;

void        err_handle(int errnum);
void        cam_init(t_env *e);
void        raytrace(t_env *e);
void        draw(t_env *e);
void        env_init(t_env *e);
void        ray_init(t_env *e, t_ray *ray, int x, int y);
t_vector3   vectorSub(t_vector3 *v1, t_vector3 *v2);
float       vectorDot(t_vector3 *v1, t_vector3 *v2);
void        vectorNormalize(t_vector3 *v1);
bool        intersectRaySphere(t_ray *r, t_sphere *s);
void		draw_pixel(char *buf, int x, int y, int color);
int			expose_event(t_env *e);
void		print_overlay(t_env *e);
int			print(t_env *e);
void		err_handle(int errnum);
int			exit_event(t_env *e);
void        launch_ray(t_env *e, int recursive_lvl, int x, int y);
int			key_events_press(int keycode, t_env *e);
#endif
