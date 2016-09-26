/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_collide.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 14:21:33 by yboualla          #+#    #+#             */
/*   Updated: 2016/09/26 16:40:58 by yboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

static bool intersectRaySphere(t_ray *r, t_sphere *s)
{
	t_vector3 dist;
	float a;
	float b;
	float c;
	float discr;
    
	a = vectorDot(&r->dir, &r->dir);
	dist = vectorSub(&r->ori, &s->pos);
	b = 2 * vectorDot(&r->dir, &dist);
	c = vectorDot(&dist, &dist) - (s->radius * s->radius);
	discr = b * b - 4 * a * c;
	if (discr < 0)
		return false;
	else
		return true;
}

int intersect(t_ray *r, t_primlist *prim)
{
	int i;

	i = -1;
	while (++i < prim->nbspheres)
	{
		if(intersectRaySphere(r, &prim->s[i]))
			return (i);
	}
	return (-1);
}
