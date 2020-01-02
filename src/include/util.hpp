#ifndef _UTIL_H
#define _UTIL_H

#include <random>
#include <functional>
#include "ray.hpp"
#include "camera.hpp"
#include "sphere.hpp"
#include "directives.hpp"
#include "hittable_list.hpp"

#ifdef __CUDACC__
#include <curand_kernel.h>
CUDA_GLOBAL void init_random(int nx, int ny, curandState *rand);
CUDA_GLOBAL void paint_pixel(int nx, int ny, int ns, camera **cam,
			     hittable **world, curandState *rand, float *output);
#endif

CUDA_DEVICE vec3 color(const ray& r, hittable *world);
CUDA_HOST double random_double();
CUDA_GLOBAL void initiate_world(hittable **list, hittable **world, camera **cam);
CUDA_GLOBAL void paint_pixel(int nx, int ny, int ns, camera **cam,
			     hittable **world, float *output);

#endif
