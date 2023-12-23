
#ifndef BCT_H_
#define BCT_H_

    #include "vectors/vector2.h"


    extern double BCT_triangle_area_2d(vector_2_t, vector_2_t, vector_2_t);

    extern void BCT_area_bct_2d(double, vector_2_t, vector_2_t, vector_2_t, vector_2_t, double *, double *, double *);


    #define BCT_bct(a, b, c, p, alpha, beta, gamma) BCT_area_bct_2d(fabs(BCT_triangle_area_2d(a, b, c)), a, b, c, p, alpha, beta, gamma)
    
    #define BCT_area_bct(area, a, b, c, p, alpha, beta, gamma) BCT_area_bct_2d(area, a, b, c, p, alpha, beta, gamma)
    
#endif
