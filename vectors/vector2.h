
#ifndef VECTOR_2_H_
#define VECTOR_2_H_

    #include <stdlib.h>
    #include <math.h>

    #define NUMBER_OF_VECTOR_2_ELEMENTS 2

    typedef union vector_2
    {

        float elements[NUMBER_OF_VECTOR_2_ELEMENTS];
        
        struct { float x, y; };

        struct { float r, g; };
        
        struct { float s, t; };

    } vector_2_t;

    extern vector_2_t create_vector_2(float, float);

    extern vector_2_t create_vector_2_with_elements(float *);

    extern double get_vector_2_length(vector_2_t);

    extern vector_2_t normalize_vector_2(vector_2_t);

    extern vector_2_t div_vector_2(vector_2_t, vector_2_t);

    extern vector_2_t div_vector_2_linearly(vector_2_t, float);

    extern vector_2_t mul_vector_2(vector_2_t, vector_2_t);

    extern vector_2_t mul_vector_2_linearly(vector_2_t, float);

    extern vector_2_t sub_vector_2(vector_2_t, vector_2_t);

    extern vector_2_t sub_vector_2_linearly(vector_2_t, float);

    extern vector_2_t sum_vector_2(vector_2_t, vector_2_t);

    extern vector_2_t sum_vector_2_linearly(vector_2_t, float);

#endif
