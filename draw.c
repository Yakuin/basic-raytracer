/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 12:11:57 by yboualla          #+#    #+#             */
/*   Updated: 2016/09/29 20:08:32 by yboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

int					hex_color(t_color c)
{
	return (((int)c.r << 16) + ((int)c.g << 8) + (int)c.b);
}

inline void			draw_pixel(char *buf, int x, int y, int color)
{
	if (x > 0 && x < WIN_WIDTH && y > 0 && y < WIN_HEIGHT)
	{
		x *= 4;
		y *= 4;
		buf[(x++) + (y * WIN_WIDTH)] = color;
		buf[(x++) + (y * WIN_WIDTH)] = color >> 8;
		buf[(x) + (y * WIN_WIDTH)] = color >> 16;
	}
}

int					print(t_env *e)
{
	int x;
	int y;
	t_ray ray;

	y = -1;
    while (++y < WIN_HEIGHT)
    {
        x = -1;
        while (++x < WIN_WIDTH)
        {
			ray_init(e, &ray, x, y);
            launch_ray(e, x, y, &ray);
		}
    }
	mlx_put_image_to_window(e->mlx, e->win, e->img->data, 0, 0);
	print_overlay(e);
	return (1);
}
