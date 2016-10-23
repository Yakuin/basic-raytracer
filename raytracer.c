/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 14:21:44 by yboualla          #+#    #+#             */
/*   Updated: 2016/10/18 16:16:53 by yboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

//TODO gestion d'erreurs
void		err_handle(int errnum)
{
	ft_putnbr(errnum);
}

void		color_check(t_color *c)
{
	c->r = c->r * 255.0f;
	c->g = c->g * 255.0f;
	c->b = c->b * 255.0f;
	if (c->r > 255.0f)
		c->r = 255.0f;
	if (c->g > 255.0f)
		c->g = 255.0f;
	if (c->b > 255.0f)
		c->b = 255.0f;
	if (c->r < 0.0f)
		c->r = 0.0f;
	if (c->g < 0.0f)
		c->g = 0.0f;
	if (c->b < 0.0f)
		c->b = 0.0f;	
}

// TODO :
//t_color		shader_lambert;
//t_vector3		lightnewstart;
//void			lightiteration;

static void 		raylight(t_env *e, t_vector3 *newStart, t_vector3 *n, t_mat *currentMat, t_color *c, float *coef)
{
	int j = -1;
	while (++j < e->primlist.nblights)
	{
		t_light currentLight = e->primlist.l[j];
		t_vector3 dist = vectorSub(&currentLight.pos, newStart);
		if (vectorDot(n, &dist) <= 0.0f)
			continue;
		float t = sqrtf(vectorDot(&dist,&dist));
		if (t <= 0.0f)
			continue;
		
		t_ray lightRay;
		lightRay.ori = *newStart;
		lightRay.dir = vectorScale((1/t), &dist);

		bool inShadow = false;
		float *hitb;
		hitb = intersect(&lightRay, &e->primlist);
		if (hitb[0] != -1)
			inShadow = true;
		if (!inShadow)
		{
			float lambert = vectorDot(&lightRay.dir, n) * *coef;
			c->r += lambert * currentLight.intensity.r * currentMat->diffuse.r;
			c->g += lambert * currentLight.intensity.g * currentMat->diffuse.g;
			c->b += lambert * currentLight.intensity.b * currentMat->diffuse.b;
		}
		else
		{
			float lambert = vectorDot(&lightRay.dir, n) * *coef;
			c->r += (lambert * currentLight.intensity.r * currentMat->diffuse.r) / 4;
			c->g += (lambert * currentLight.intensity.g * currentMat->diffuse.g) / 4;
			c->b += (lambert * currentLight.intensity.b * currentMat->diffuse.b) / 4;
		}
	}
}

void            launch_ray(t_env *e, int x, int y, t_ray *ray)
{
	float *hit;
	t_color c;
	int depth;
	float coef;

	c.r = 0.0;
	c.g = 0.0;
	c.b = 0.0;
	coef = 1.0f;
	depth = -1;
	hit = intersect(ray, &e->primlist);
	if (hit[0] != -1)
	{
		while ((++depth <= MAX_DEPTH) && (coef > 0.0f))
		{
			t_vector3 scaled = vectorScale(hit[1], &ray->dir);
			t_vector3 newStart = vectorAdd(&ray->ori, &scaled);

			t_vector3 n = vectorSub(&newStart, &e->primlist.s[(int)hit[0]].pos);
			float temp = vectorDot(&n, &n);
			if (temp == 0)
				break;
			
			temp = 1.0f / sqrtf(temp);
			n = vectorScale(temp, &n);

			// getting current material
			t_mat currentMat;
			if (hit[2] == 0)
				currentMat = e->primlist.m[e->primlist.s[(int)hit[0]].material];
			else if (hit[2] == 1)
				currentMat = e->primlist.m[e->primlist.p[(int)hit[0]].material];
			// lights
			raylight(e, &newStart, &n, &currentMat, &c, &coef);

			coef *= currentMat.reflection;
			
			ray->ori = newStart;
			float reflect = 2.0f * vectorDot(&ray->dir, &n);
			t_vector3 tmp = vectorScale(reflect, &n);
			ray->dir = vectorSub(&ray->dir, &tmp);
		}
		color_check(&c);
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
