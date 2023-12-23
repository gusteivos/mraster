
#ifndef VECTOR_3_H_
#define VECTOR_3_H_

    #include <vectors/vector2.h>

    #define NUMBER_OF_VECTOR_3_ELEMENTS 3

    typedef union vector_3
    {

        float elements[NUMBER_OF_VECTOR_3_ELEMENTS];

        struct
        {

            union
            {

                vector_2_t vector2;

                struct { float x, y; };

                struct { float r, g; };

                struct { float s, t; };

            };

            union
            {

                float z;

                float b;

                float p;

            };
            

        };

    } vector_3_t;

    extern vector_3_t create_vector_3(float, float, float);

    extern vector_3_t create_vector_3_with_vector_2(vector_2_t, float);

    extern vector_3_t create_vector_3_with_elements(float *);

    extern double get_vector_3_length(vector_3_t);

    extern vector_3_t normalize_vector_3(vector_3_t);

    extern vector_3_t div_vector_3(vector_3_t, vector_3_t);

    extern vector_3_t div_vector_3_linearly(vector_3_t, float);

    extern vector_3_t mul_vector_3(vector_3_t, vector_3_t);

    extern vector_3_t mul_vector_3_linearly(vector_3_t, float);

    extern vector_3_t sub_vector_3(vector_3_t, vector_3_t);

    extern vector_3_t sub_vector_3_linearly(vector_3_t, float);

    extern vector_3_t sum_vector_3(vector_3_t, vector_3_t);

    extern vector_3_t sum_vector_3_linearly(vector_3_t, float);

#endif
