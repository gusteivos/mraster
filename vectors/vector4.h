
#ifndef VECTOR_4_H_
#define VECTOR_4_H_

    #include <vectors/vector3.h>

    #define NUMBER_OF_VECTOR_4_ELEMENTS 4

    typedef union vector_4
    {

        float elements[NUMBER_OF_VECTOR_4_ELEMENTS];

        struct
        {

            union
            {

                vector_3_t vector3;

                struct { float x, y, z; };

                struct { float r, g, b; };

                struct { float s, t, p; };

            };

            union
            {

                float w;

                float a;

                float q;

            };

        };

    } vector_4_t;

    extern vector_4_t create_vector_4(float, float, float, float);

    extern vector_4_t create_vector_4_with_vector_2(vector_2_t, float, float);
    
    extern vector_4_t create_vector_4_with_vector_3(vector_3_t, float);

    extern vector_4_t create_vector_4_with_elements(float *);

    extern double get_vector_4_length(vector_4_t);

    extern vector_4_t normalize_vector_4(vector_4_t);

    extern vector_4_t div_vector_4(vector_4_t, vector_4_t);

    extern vector_4_t div_vector_4_linearly(vector_4_t, float);

    extern vector_4_t mul_vector_4(vector_4_t, vector_4_t);

    extern vector_4_t mul_vector_4_linearly(vector_4_t, float);

    extern vector_4_t sub_vector_4(vector_4_t, vector_4_t);

    extern vector_4_t sub_vector_4_linearly(vector_4_t, float);

    extern vector_4_t sum_vector_4(vector_4_t, vector_4_t);

    extern vector_4_t sum_vector_4_linearly(vector_4_t, float);

#endif
