/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 14:21:24 by yboualla          #+#    #+#             */
/*   Updated: 2016/09/20 16:14:37 by yboualla         ###   ########.fr       */
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
    e->cam.dir.z = 0;
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

void        env_init(t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIN_WIDTH, WIN_HEIGHT, "1 TRUC 2 MERDE");
	if (!(e->img = (t_img *)malloc(sizeof(t_img))))
		err_handle(0);
	e->img->data = mlx_new_image(e->mlx, WIN_WIDTH, WIN_HEIGHT);
	e->buf = mlx_get_data_addr(
		e->img->data,
		&e->img->bpp,
		&e->img->size,
		&e->img->endian);
	cam_init(e);
    
// ugly and temporary for tests, will change this asap
    e->s.pos.x = 2;
    e->s.pos.y = 0;
    e->s.pos.z = 600;
    e->s.radius = 2;
}
