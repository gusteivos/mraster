
#ifndef BCT_H_
#define BCT_H_

    #include "vectors/vector2.h"


    extern float BCT_triangle_area_2d(vector_2_t vertex_a, vector_2_t vertex_b, vector_2_t vertex_c);

    extern void  BCT_area_2d         (vector_2_t vertex_a, vector_2_t vertex_b, vector_2_t vertex_c, vector_2_t point, float *alpha, float *beta, float *gamma, float area);


    #define BCT     (a, b, c, p, alpha, beta, gamma)       BCT_area_2d(a, b, c, p, alpha, beta, gamma, BCT_triangle_area_2d(a, b, c))

    #define BCT_area(a, b, c, p, alpha, beta, gamma, area) BCT_area_2d(a, b, c, p, alpha, beta, gamma, area)

#endif /* BCT_H_ == barycentric coordinates triangle h */
