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