/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 18:07:42 by yboualla          #+#    #+#             */
/*   Updated: 2016/10/25 19:28:20 by yboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

// TODO
void		parser(t_env *e)
{
	e->primlist.nbspheres = 1;
	e->primlist.nbplanes = 2;
	e->primlist.nblights = 1;
	e->primlist.nbmaterial = 3;
	e->primlist.s = (t_sphere *)malloc(sizeof(t_sphere) * e->primlist.nbspheres);
	e->primlist.p = (t_plane *)malloc(sizeof(t_plane) * e->primlist.nbplanes);
	e->primlist.l = (t_light *)malloc(sizeof(t_light) * e->primlist.nblights);
	e->primlist.m = (t_mat *)malloc(sizeof(t_mat) * e->primlist.nbmaterial);

// ugly and temporary for tests, will delete this asap once the parser is done
	e->primlist.m[0].diffuse.r = 1.0;
	e->primlist.m[0].diffuse.g = 1.0;
	e->primlist.m[0].diffuse.b = 1.0;
	e->primlist.m[0].reflection = 0.0;

	e->primlist.m[1].diffuse.r = 0.0;
	e->primlist.m[1].diffuse.g = 1.0;
	e->primlist.m[1].diffuse.b = 1.0;
	e->primlist.m[1].reflection = 0.0;

	e->primlist.m[2].diffuse.r = 1.0;
	e->primlist.m[2].diffuse.g = 0.0;
	e->primlist.m[2].diffuse.b = 1.0;
	e->primlist.m[2].reflection = 0.0;

	e->primlist.s[0].pos.x = 100.0;
	e->primlist.s[0].pos.y = 200.0;
	e->primlist.s[0].pos.z = 0.0;
	e->primlist.s[0].radius = 200;
	e->primlist.s[0].material = 0;

/*	e->primlist.s[1].pos.x = 407.0;
	e->primlist.s[1].pos.y = 340.0;
	e->primlist.s[1].pos.z = 0.0;
	e->primlist.s[1].radius = 100;
	e->primlist.s[1].material = 1;

	e->primlist.s[2].pos.x = 320.0;
	e->primlist.s[2].pos.y = 140.0;
	e->primlist.s[2].pos.z = 0.0;
	e->primlist.s[2].radius = 100;
	e->primlist.s[2].material = 2;*/

	e->primlist.p[0].origin.x = 0;
	e->primlist.p[0].origin.y = 600;
	e->primlist.p[0].origin.z = 0;
	e->primlist.p[0].normal.x = 0;
	e->primlist.p[0].normal.y = -1;
	e->primlist.p[0].normal.z = 0;
	e->primlist.p[0].material = 1;

	e->primlist.p[1].origin.x = 0;
	e->primlist.p[1].origin.y = 0;
	e->primlist.p[1].origin.z = 400;
	e->primlist.p[1].normal.x = 0;
	e->primlist.p[1].normal.y = 0;
	e->primlist.p[1].normal.z = -1;
	e->primlist.p[1].material = 0;

	e->primlist.l[0].pos.x = -800.0;
	e->primlist.l[0].pos.y = 500.0;
	e->primlist.l[0].pos.z = 350.0;
	e->primlist.l[0].intensity.r = 1.0;
	e->primlist.l[0].intensity.g = 1.0;
	e->primlist.l[0].intensity.b = 1.0;

/*	e->primlist.l[1].pos.x = -500.0;
	e->primlist.l[1].pos.y = 200.0;
	e->primlist.l[1].pos.z = -800;
	e->primlist.l[1].intensity.r = 0.6;
	e->primlist.l[1].intensity.g = 0.7;
	e->primlist.l[1].intensity.b = 1.0;

	e->primlist.l[2].pos.x = 1000.0;
	e->primlist.l[2].pos.y = 0.0;
	e->primlist.l[2].pos.z = 1000.0;
	e->primlist.l[2].intensity.r = 1.0;
	e->primlist.l[2].intensity.g = 1.0;
	e->primlist.l[2].intensity.b = 1.0;*/
}
