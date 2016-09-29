/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 14:21:44 by yboualla          #+#    #+#             */
/*   Updated: 2016/09/29 18:49:00 by yboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

//TODO gestion d'erreurs
void		err_handle(int errnum)
{
	ft_putnbr(errnum);
}

//t_vector3 lightnewstart;

//void lightiteration;

//t_color 		raylight(t_env *e, ;

void            launch_ray(t_env *e, int x, int y, t_ray *ray)
{
	float *hit;
	t_color c;
	int depth;
	float coef;

	c.r = 0;
	c.g = 0;
	c.b = 0;
	coef = 1.0f;
	depth = -1;
	hit = intersect(ray, &e->primlist);
	if (hit[0] != -1)
	{
		while ((++depth <= MAX_DEPTH) && (coef > 0.0f))
		{
			t_vector3 scaled = vectorScale(hit[1], &ray->dir);
			t_vector3 newStart = vectorAdd(&ray->ori, &scaled);

			/* Find the normal for this new vector at the point of intersection */
			t_vector3 n = vectorSub(&newStart, &e->primlist.s[(int)hit[0]].pos);
			float temp = vectorDot(&n, &n);
			if (temp == 0) break;
			
			temp = 1.0f / sqrtf(temp);
			n = vectorScale(temp, &n);

			/* Find the material to determine the colour */
			t_mat currentMat = e->primlist.m[e->primlist.s[(int)hit[0]].material];
			
			/* Find the value of the light at this point */
			int j = -1;
			while (++j < e->primlist.nblights)
			{
				t_light currentLight = e->primlist.l[j];
				t_vector3 dist = vectorSub(&currentLight.pos, &newStart);
				if (vectorDot(&n, &dist) <= 0.0f) continue;
				float t = sqrtf(vectorDot(&dist,&dist));
				if (t <= 0.0f) continue;
				
				t_ray lightRay;
				lightRay.ori = newStart;
				lightRay.dir = vectorScale((1/t), &dist);
				
				/* Lambert diffusion */
				float lambert = vectorDot(&lightRay.dir, &n) * coef; 
				c.r += lambert * currentLight.intensity.r * currentMat.diffuse.r;
				c.g += lambert * currentLight.intensity.g * currentMat.diffuse.g;
				c.b += lambert * currentLight.intensity.b * currentMat.diffuse.b;
			}
			/* Iterate over the reflection */
			coef *= currentMat.reflection;
			
			/* The reflected ray start and direction */
			ray->ori = newStart;
			float reflect = 2.0f * vectorDot(&ray->dir, &n);
			t_vector3 tmp = vectorScale(reflect, &n);
			ray->dir = vectorSub(&ray->dir, &tmp);
		}
		c.r = c.r * 255.0f;
		c.g = c.g * 255.0f;
		c.b = c.b * 255.0f;
		draw_pixel(e->buf, x, y, hex_color(c));
	}
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
