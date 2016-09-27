/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 14:21:24 by yboualla          #+#    #+#             */
/*   Updated: 2016/09/27 16:30:54 by yboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

void        cam_init(t_env *e)
{
    e->cam.pos.x = 0;
    e->cam.pos.y = 0;
    e->cam.pos.z = 220;
    e->cam.dir.x = 0;
    e->cam.dir.y = 0;
    e->cam.dir.z = 1;
    e->cam.foc_dist = -(WIN_WIDTH / 2 * tan(FOV / 2));
}

void        ray_init(t_env *e, t_ray *ray, int x, int y)
{
    t_vector3 b;
    
    b.x = (x - (WIN_WIDTH / 2)) + e->cam.dir.x;
    b.y = (y - (WIN_HEIGHT / 2)) + e->cam.dir.y;
    b.z = e->cam.foc_dist;
	vectorNormalize(&b);
    
    ray->dir.x = b.x;// - e->cam.pos.x;
	ray->dir.y = b.y;// - e->cam.pos.y;
	ray->dir.z = b.z;// - e->cam.pos.z;
    vectorNormalize(&ray->dir);
    
    ray->ori = e->cam.pos;
}

// TODO
void		parser(t_env *e)
{
	e->primlist.nbspheres = 2;
	e->primlist.nblights = 2;
	e->primlist.nbmaterial = 2;
	e->primlist.s = (t_sphere *)malloc(sizeof(t_sphere) * e->primlist.nbspheres);
	e->primlist.l = (t_light *)malloc(sizeof(t_light) * e->primlist.nblights);
	e->primlist.m = (t_mat *)malloc(sizeof(t_mat) * e->primlist.nbmaterial);


// ugly and temporary for tests, will delete this asap once the parser is done
	e->primlist.m[0].diffuse.red = 255;
	e->primlist.m[0].diffuse.green = 0;
	e->primlist.m[0].diffuse.blue = 0;
	e->primlist.m[0].reflection = 0.2;

	e->primlist.m[1].diffuse.red = 0;
	e->primlist.m[1].diffuse.green = 255;
	e->primlist.m[1].diffuse.blue = 0;
	e->primlist.m[1].reflection = 0.5;

	e->primlist.s[0].pos.x = 2;
    e->primlist.s[0].pos.y = 0;
    e->primlist.s[0].pos.z = 200;
    e->primlist.s[0].radius = 2;
	e->primlist.s[0].c.r = 50;
	e->primlist.s[0].c.g = 50;
	e->primlist.s[0].c.b = 200;
	e->primlist.s[0].material = 0;

	e->primlist.s[1].pos.x = 2.5;
    e->primlist.s[1].pos.y = 1;
    e->primlist.s[1].pos.z = 100;
    e->primlist.s[1].radius = 3;
	e->primlist.s[1].c.r = 200;
	e->primlist.s[1].c.g = 50;
	e->primlist.s[1].c.b = 50;
	e->primlist.s[1].material = 1;

	e->primlist.l[0].pos.x = 0;
    e->primlist.l[0].pos.y = 3;
    e->primlist.l[0].pos.z = 100;
	e->primlist.l[0].intensity.r = 250;
	e->primlist.l[0].intensity.g = 250;
	e->primlist.l[0].intensity.b = 250;

	e->primlist.l[1].pos.x = 3.5;
    e->primlist.l[1].pos.y = 3;
    e->primlist.l[1].pos.z = 0;
	e->primlist.l[0].intensity.r = 80;
	e->primlist.l[0].intensity.g = 120;
	e->primlist.l[0].intensity.b = 250;
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
