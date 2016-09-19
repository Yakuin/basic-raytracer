#include "raytracer.h"

/* Subtract two vectors and return the resulting vector */
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
	return v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
}

void        vectorNormalize(t_vector3 *v1)
{
    float length;
    
    length = sqrt((v1->x * v1->x) + (v1->y * v1->y) + (v1->z * v1->z));
    v1->x /= length;
    v1->y /= length;
    v1->z /= length;
}