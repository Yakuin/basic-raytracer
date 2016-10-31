/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 14:21:24 by yboualla          #+#    #+#             */
/*   Updated: 2016/10/25 18:08:02 by yboualla         ###   ########.fr       */
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
