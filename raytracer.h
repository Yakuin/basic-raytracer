#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

#define BG_COLOR 0x3399ff //r51 g153 b255
#define X_RES 40
#define Y_RES 40
#define FOV 30

typedef struct  s_vector3
{
    float x, y, z;
}               t_vector3;

typedef struct  s_sphere
{
    t_vector3 pos;
    float  radius;
}               t_sphere;

typedef struct  s_ray
{
    t_vector3 ori;
    t_vector3 dir;
}               t_ray;

typedef struct  s_camera
{
    t_vector3   pos;
    t_vector3   dir;
    float       foc_dist;
}               t_camera;

typedef struct  s_env
{
    t_camera    cam;
    t_sphere    s;
}               t_env;

void        err_handle(int errnum);
void        cam_init(t_env *e);
void        raytrace(t_env *e);
void        draw(t_env *e);
void        env_init(t_env *e);
void        ray_init(t_env *e, t_ray *ray, int x, int y);
t_vector3   vectorSub(t_vector3 *v1, t_vector3 *v2);
float       vectorDot(t_vector3 *v1, t_vector3 *v2);
void        vectorNormalize(t_vector3 *v1);
bool        intersectRaySphere(t_ray *r, t_sphere *s);

#endif /* MAIN_H */

