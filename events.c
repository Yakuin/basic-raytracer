/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 12:13:36 by yboualla          #+#    #+#             */
/*   Updated: 2016/09/29 17:50:50 by yboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

int					expose_event(t_env *e)
{
	mlx_put_image_to_window(e->mlx, e->win, e->buf, 0, 0);
	return (1);
}

int					exit_event(t_env *e)
{
	if (e)
		exit(1);
	return (1);
}

int					key_events_press(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(1);
	if (keycode == 12)
		e->overlay = (e->overlay == 1 ? 0 : 1);
	if (keycode == 123)
		e->cam.pos.x += 0.1;
	if (keycode == 124)
		e->cam.pos.x -= 0.1;
	if (keycode == 126)
		e->cam.pos.y += 0.1;
	if (keycode == 125)
		e->cam.pos.y -= 0.1;
	if (keycode == 69)
		e->cam.pos.z += 1;
	if (keycode == 78)
		e->cam.pos.z -= 1;
	print(e);
	return (0);
}
