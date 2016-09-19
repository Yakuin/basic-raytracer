#include "raytracer.h"

void        cam_init(t_env *e)
{
    e->cam.pos.x = 0;
    e->cam.pos.y = 0;
    e->cam.pos.z = 60;
    e->cam.dir.x = 0;
    e->cam.dir.y = 0;
    e->cam.dir.z = 0;
    e->cam.foc_dist = -(X_RES / 2 * tan(FOV / 2));
}

void        ray_init(t_env *e, t_ray *ray, int x, int y)
{
    t_vector3 B;
    
    B.x = (x - (X_RES / 2)) + e->cam.dir.x;
    B.y = (y - (Y_RES / 2)) + e->cam.dir.y;
    B.z = e->cam.foc_dist;
    vectorNormalize(&B);
    
    ray->dir.x = B.x - e->cam.pos.x;
    ray->dir.y = B.y - e->cam.pos.y;
    ray->dir.z = B.z - e->cam.pos.z;
    vectorNormalize(&ray->dir);
    
    ray->ori = e->cam.pos;
}

void        env_init(t_env *e)
{
    cam_init(e);
    
    // ugly and temporary for tests, will change this asap
    e->s.pos.x = 0;
    e->s.pos.y = 0;
    e->s.pos.z = 500;
    e->s.radius = 5;
}