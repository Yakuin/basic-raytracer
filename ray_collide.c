/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_collide.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 14:21:33 by yboualla          #+#    #+#             */
/*   Updated: 2016/10/18 17:52:34 by yboualla         ###   ########.fr       */
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

static bool intersectRayPlane(t_ray *r, t_plane *p, float *t)
{
	float denom;
	float t2;
	t_vector3 a;

	denom = vectorDot(&p->normal, &r->dir);
	denom = -denom;
    if (denom > 0.001f)
	{
		a = vectorSub(&p->origin, &r->ori);
        t2 = vectorDot(&a, &p->normal) / denom;
	t2 = -t2;
		if (t2 < t[1] && t2 >= 0)
		{
			t[1] = t2;
			return (true);
		}
	}
	return (false);
}

float *intersect(t_ray *r, t_primlist *prim)
{
	int i;
	float *rslt; // selected prim / hit distance / type of prim
	
	rslt = (float *)malloc(sizeof(float) * 3);
	rslt[0] = -1; // prim id
	rslt[1] = RAY_MAX_RANGE; // hit distance
	rslt[2] = -1; // 0 = Sphere / 1 = Plan / 2 = Cone / 3 = Cylindre
	i = -1;
	while (++i < prim->nbspheres)
	{
		if (intersectRaySphere(r, &prim->s[i], rslt))
		{
			rslt[0] = i;
			rslt[2] = 0;
		}
	}
	i = -1;
	while (++i < prim->nbplanes)
	{
		if (intersectRayPlane(r, &prim->p[i], rslt))
		{
			rslt[0] = i;
			rslt[2] = 1;
		}
	}
	return (rslt);
}
