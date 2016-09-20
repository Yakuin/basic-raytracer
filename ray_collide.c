/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_collide.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 14:21:33 by yboualla          #+#    #+#             */
/*   Updated: 2016/09/20 14:21:36 by yboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

bool intersectRaySphere(t_ray *r, t_sphere *s)
{
    	t_vector3 dist;
	float A;
        float B;
        float C;
        float discr;
        
        A = vectorDot(&r->dir, &r->dir);
        dist = vectorSub(&r->ori, &s->pos);
        B = 2 * vectorDot(&r->dir, &dist);
        C = vectorDot(&dist, &dist) - (s->radius * s->radius);
        discr = B * B - 4 * A * C;
	if (discr < 0)
		return false;
	else
		return true;
}
