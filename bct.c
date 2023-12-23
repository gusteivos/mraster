#include "bct.h"


float BCT_triangle_area_2d(vector_2_t vertex_a, vector_2_t vertex_b, vector_2_t vertex_c)
{

    return ((vertex_b.x - vertex_a.x) * (vertex_c.y - vertex_a.y) - (vertex_c.x - vertex_a.x) * (vertex_b.y - vertex_a.y)) / 2.0f;

}

void  BCT_area_2d         (vector_2_t vertex_a, vector_2_t vertex_b, vector_2_t vertex_c, vector_2_t point, float *alpha, float *beta, float *gamma, float area)
{

    float area_p_b_c = BCT_triangle_area_2d(point, vertex_b, vertex_c);

    float area_p_c_a = BCT_triangle_area_2d(point, vertex_c, vertex_a);

    float area_p_a_b = BCT_triangle_area_2d(point, vertex_a, vertex_b);


    if (alpha != NULL)
    {

        *alpha = area_p_b_c / area;

    }

    if (beta  != NULL)
    {

        *beta  = area_p_c_a / area;

    }

    if (gamma != NULL)
    {

        *gamma = area_p_a_b / area;

    }

}
