#include "bct.h"


double BCT_triangle_area_2d(vector_2_t a, vector_2_t b, vector_2_t c)
{

    return 0.5 * (double)((b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y));

}

void BCT_area_bct_2d(double area, vector_2_t a, vector_2_t b, vector_2_t c, vector_2_t p, double *alpha, double *beta, double *gamma)
{

    double _area_p_b_c = BCT_triangle_area_2d(p, b, c);

    double _area_p_c_a = BCT_triangle_area_2d(p, c, a);
 
    double _area_p_a_b = BCT_triangle_area_2d(p, a, b);

    *alpha = _area_p_b_c / area;
    
    *beta  = _area_p_c_a / area;

    // *gamma = 1.0 - *alpha - *beta;
    
    *gamma = _area_p_a_b / area;

}
