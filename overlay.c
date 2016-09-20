/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overlay.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 12:43:58 by yboualla          #+#    #+#             */
/*   Updated: 2016/09/20 15:06:01 by yboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

void	print_overlay(t_env *e)
{
	mlx_string_put(e->mlx, e->win, WIN_HEIGHT - 370,
				   10, 0xFFFFFF, "Use directional keys to move around");
	mlx_string_put(e->mlx, e->win, WIN_HEIGHT - 130,
				   30, 0xFFFFFF, "ESC to exit");
	mlx_string_put(e->mlx, e->win, WIN_HEIGHT - 280,
				   50, 0xFFFFFF, "Press Q to hide/show infos");
}
