/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 14:21:44 by yboualla          #+#    #+#             */
/*   Updated: 2016/09/20 15:18:48 by yboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

//TODO gestion d'erreurs
void		err_handle(int errnum)
{
	ft_putnbr(errnum);
}

void            launch_ray(t_env *e, int recursive_lvl, int x, int y)
{
	bool hit;
	t_ray ray;
	
	recursive_lvl = 42; // unused for now
	recursive_lvl++;
	ray_init(e, &ray, x, y);
	hit = intersectRaySphere(&ray, &e->s);
	if (hit)
		draw_pixel(e->buf, x, y, 400);
	else
		draw_pixel(e->buf, x, y, 1);
}

int main(void)
{
    t_env *e;
    
    e = (t_env*)malloc(sizeof(t_env));
    env_init(e);
	mlx_expose_hook(e->win, expose_event, e);
	mlx_hook(e->win, 17, 1L << 17, exit_event, e);
	mlx_hook(e->win, 2, 1L << 0, key_events_press, e);
	print(e);
	mlx_loop(e->mlx);
    return (0);
}
