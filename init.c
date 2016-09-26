/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 14:21:24 by yboualla          #+#    #+#             */
/*   Updated: 2016/09/26 16:30:57 by yboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

void        cam_init(t_env *e)
{
    e->cam.pos.x = 0;
    e->cam.pos.y = 0;
    e->cam.pos.z = 60;
    e->cam.dir.x = 0;
    e->cam.dir.y = 0;
    e->cam.dir.z = 1;
    e->cam.foc_dist = -(WIN_WIDTH / 2 * tan(FOV / 2));
}

void        ray_init(t_env *e, t_ray *ray, int x, int y)
{
    t_vector3 B;
    
    B.x = (x - (WIN_WIDTH / 2)) + e->cam.dir.x;
    B.y = (y - (WIN_HEIGHT / 2)) + e->cam.dir.y;
    B.z = e->cam.foc_dist;
	vectorNormalize(&B);
    
    ray->dir.x = B.x;// - e->cam.pos.x;
	ray->dir.y = B.y;// - e->cam.pos.y;
	ray->dir.z = B.z;// - e->cam.pos.z;
    vectorNormalize(&ray->dir);
    
    ray->ori = e->cam.pos;
}

// TODO
void		parser(t_env *e)
{
	e->primlist.nbspheres = 2;
	e->primlist.nblights = 0;
	e->primlist.s = (t_sphere *)malloc(sizeof(t_sphere) * e->primlist.nbspheres);
	e->primlist.l = (t_light *)malloc(sizeof(t_light) * e->primlist.nblights);

// ugly and temporary for tests, will delete this asap once the parser is done
	e->primlist.s[0].pos.x = 2;
    e->primlist.s[0].pos.y = 0;
    e->primlist.s[0].pos.z = 100;
    e->primlist.s[0].radius = 2;
	e->primlist.s[0].c.r = 50;
	e->primlist.s[0].c.g = 50;
	e->primlist.s[0].c.b = 200;
	e->primlist.s[0].material = 1;

	e->primlist.s[1].pos.x = 2.5;
    e->primlist.s[1].pos.y = 0;
    e->primlist.s[1].pos.z = 200;
    e->primlist.s[1].radius = 3;
	e->primlist.s[1].c.r = 200;
	e->primlist.s[1].c.g = 50;
	e->primlist.s[1].c.b = 50;
	e->primlist.s[1].material = 1;
}

void        env_init(t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIN_WIDTH, WIN_HEIGHT, "Basic Raytracer");
	if (!(e->img = (t_img *)malloc(sizeof(t_img))))
		err_handle(0);
	e->img->data = mlx_new_image(e->mlx, WIN_WIDTH, WIN_HEIGHT);
	e->buf = mlx_get_data_addr(
		e->img->data,
		&e->img->bpp,
		&e->img->size,
		&e->img->endian);
	e->overlay = 1;
	cam_init(e);
	parser(e);
}
