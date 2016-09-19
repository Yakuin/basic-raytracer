#include "raytracer.h"

void            launch_ray(t_env *e, int recursive_lvl, int x, int y)
{
        bool hit;
        t_ray ray;
        
        recursive_lvl = 42; // unused for now
        recursive_lvl++;
        ray_init(e, &ray, x, y);
        hit = intersectRaySphere(&ray, &e->s);
        if (hit)
            printf("00");
        else
            printf("--");
}

int main(void)
{
    t_env *e;
    int x;
    int y;
    
    e = (t_env*)malloc(sizeof(t_env));
    env_init(e);
    y = -1;
    while (++y < Y_RES)
    {
        x = -1;
        while (++x < X_RES)
        {
            launch_ray(e, 0, x, y);
	}
        printf("\n");
    }
}