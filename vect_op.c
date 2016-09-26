/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 15:27:35 by yboualla          #+#    #+#             */
/*   Updated: 2016/09/26 18:03:46 by yboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_vector3   vectorSub(t_vector3 *v1, t_vector3 *v2)
{
	t_vector3 result;
        
        result.x = v1->x - v2->x;
        result.y = v1->y - v2->y;
        result.z = v1->z - v2->z;
	return result;
}

float       vectorDot(t_vector3 *v1, t_vector3 *v2)
{
	return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
}

t_vector3 vectorScale(float c, t_vector3 *v)
{
	t_vector3 result;

	result.x = v->x * c;
	result.y = v->y * c;
	result.z = v->z * c;
	return (result);
}

t_vector3 vectorAdd(t_vector3 *v1, t_vector3 *v2)
{
	t_vector3 result;

	result.x = v1->x + v2->x;
	result.y = v1->y + v2->y;
	result.z = v1->z + v2->z;
	return (result);
}

void        vectorNormalize(t_vector3 *v1)
{
    double length;
    
    length = sqrt((v1->x * v1->x) + (v1->y * v1->y) + (v1->z * v1->z));
    v1->x /= length;
    v1->y /= length;
    v1->z /= length;
}
