/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 14:21:24 by yboualla          #+#    #+#             */
/*   Updated: 2016/10/18 18:06:02 by yboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

void        cam_init(t_env *e)
{
    e->cam.pos.x = 0;
    e->cam.pos.y = 0;
    e->cam.pos.z = -1000;
    e->cam.dir.x = 0;
    e->cam.dir.y = 1;
    e->cam.dir.z = 0;
    e->cam.foc_dist = -(WIN_WIDTH / 2 * tan(FOV / 2));
}

void        ray_init(t_env *e, t_ray *ray, int x, int y)
{
    t_vector3 b;

    b.x = (x - (WIN_WIDTH / 2)) + e->cam.dir.x;
    b.y = (y - (WIN_HEIGHT / 2)) + e->cam.dir.y;
    b.z = e->cam.foc_dist;
    vectorNormalize(&b);
    
    ray->dir.x = b.x;
    ray->dir.y = b.y;
    ray->dir.z = b.z;
    vectorNormalize(&ray->dir);

    ray->ori = e->cam.pos;
}

// TODO
void		parser(t_env *e)
{
	e->primlist.nbspheres = 3;
	e->primlist.nbplanes = 1;
	e->primlist.nblights = 2;
	e->primlist.nbmaterial = 3;
	e->primlist.s = (t_sphere *)malloc(sizeof(t_sphere) * e->primlist.nbspheres);
	e->primlist.p = (t_plane *)malloc(sizeof(t_plane) * e->primlist.nbplanes);
	e->primlist.l = (t_light *)malloc(sizeof(t_light) * e->primlist.nblights);
	e->primlist.m = (t_mat *)malloc(sizeof(t_mat) * e->primlist.nbmaterial);

// ugly and temporary for tests, will delete this asap once the parser is done
	e->primlist.m[0].diffuse.r = 1.0;
	e->primlist.m[0].diffuse.g = 1.0;
	e->primlist.m[0].diffuse.b = 1.0;
	e->primlist.m[0].reflection = 0.0;

	e->primlist.m[1].diffuse.r = 0.0;
	e->primlist.m[1].diffuse.g = 1.0;
	e->primlist.m[1].diffuse.b = 1.0;
	e->primlist.m[1].reflection = 0.0;

	e->primlist.m[2].diffuse.r = 1.0;
	e->primlist.m[2].diffuse.g = 0.0;
	e->primlist.m[2].diffuse.b = 1.0;
	e->primlist.m[2].reflection = 0.0;

	e->primlist.s[0].pos.x = 100.0;
    e->primlist.s[0].pos.y = 400.0;
    e->primlist.s[0].pos.z = 0.0;
    e->primlist.s[0].radius = 200;
	e->primlist.s[0].material = 0;

	e->primlist.s[1].pos.x = 407.0;
    e->primlist.s[1].pos.y = 340.0;
    e->primlist.s[1].pos.z = 100.0;
    e->primlist.s[1].radius = 100;
	e->primlist.s[1].material = 1;

	e->primlist.s[2].pos.x = 320.0;
    e->primlist.s[2].pos.y = 140.0;
    e->primlist.s[2].pos.z = 200.0;
    e->primlist.s[2].radius = 100;
	e->primlist.s[2].material = 2;

       	e->primlist.p[0].origin.x = 0;
	e->primlist.p[0].origin.y = 600;
	e->primlist.p[0].origin.z = 0;
	e->primlist.p[0].normal.x = 0;
	e->primlist.p[0].normal.y = -1;
	e->primlist.p[0].normal.z = 0;
	e->primlist.p[0].material = 0;

	/*	e->primlist.l[0].pos.x = -500.0;
    e->primlist.l[0].pos.y = 700.0;
    e->primlist.l[0].pos.z = -100;
	e->primlist.l[0].intensity.r = 1.0;
	e->primlist.l[0].intensity.g = 1.0;
	e->primlist.l[0].intensity.b = 1.0;*/

	e->primlist.l[0].pos.x = -1000.0;
	e->primlist.l[0].pos.y = 240.0;
	e->primlist.l[0].pos.z = -200;
	e->primlist.l[0].intensity.r = 0.6;
	e->primlist.l[0].intensity.g = 0.7;
	e->primlist.l[0].intensity.b = 1.0;

/*	e->primlist.l[1].pos.x = 0.0;
    e->primlist.l[1].pos.y = 0.0;
    e->primlist.l[1].pos.z = -10;
	e->primlist.l[1].intensity.r = 1.0;
	e->primlist.l[1].intensity.g = 1.0;
	e->primlist.l[1].intensity.b = 1.0;*/
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
