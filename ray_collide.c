/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_collide.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 14:21:33 by yboualla          #+#    #+#             */
/*   Updated: 2016/09/27 14:35:21 by yboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

static bool intersectRaySphere(t_ray *r, t_sphere *s, float *t)
{
	t_vector3 dist;
	float a;
	float b;
	float c;
	float discr;
	float sqrtdiscr;
	float t0;
	float t1;


	a = vectorDot(&r->dir, &r->dir);
	dist = vectorSub(&r->ori, &s->pos);
	b = 2 * vectorDot(&r->dir, &dist);
	c = vectorDot(&dist, &dist) - (s->radius * s->radius);
	discr = b * b - 4 * a * c;
	if (discr < 0)
		return (false);
	else
	{
		sqrtdiscr = sqrtf(discr);
		t0 = (-b + sqrtdiscr) / 2;
		t1 = (-b - sqrtdiscr) / 2;
		if (t0 > t1)
			t0 = t1;
		if ((t0 > 0.001f) && (t0 < t[1]))
		{
			t[1] = t0;
			return (true);
		}
	}
	return (false);
}

int intersect(t_ray *r, t_primlist *prim)
{
	int i;
	float rslt[2];
	
	rslt[0] = -1;
	rslt[1] = 9999999;
	i = -1;
	while (++i < prim->nbspheres)
	{
		if(intersectRaySphere(r, &prim->s[i], rslt))
			rslt[0] = i;
	}
	return (rslt[0]);
}
