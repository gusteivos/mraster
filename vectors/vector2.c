#include <vectors/vector2.h>

vector_2_t create_vector_2(float x, float y)
{

    vector_2_t _new_vector;

    _new_vector.x = x;

    _new_vector.y = y;

    return _new_vector;

}

vector_2_t create_vector_2_with_elements(float *elements)
{

    vector_2_t _new_vector;
    
    _new_vector.elements[0] = elements[0];

    _new_vector.elements[1] = elements[1];
    
    return _new_vector;

}

double get_vector_2_length(vector_2_t vector)
{

   return sqrt((vector.x * vector.x) + (vector.y * vector.y)); 

}

vector_2_t normalize_vector_2(vector_2_t vector)
{
    
    double length = get_vector_2_length(vector);
    
    return create_vector_2(vector.x / length, vector.y / length);

}

vector_2_t div_vector_2(vector_2_t a, vector_2_t b)
{

    return create_vector_2(a.x / b.x, a.y / b.y);

}

vector_2_t div_vector_2_linearly(vector_2_t vector, float scalar)
{

    return create_vector_2(vector.x / scalar, vector.y / scalar);

}

vector_2_t mul_vector_2(vector_2_t a, vector_2_t b)
{

    return create_vector_2(a.x * b.x, a.y * b.y);

}

vector_2_t mul_vector_2_linearly(vector_2_t vector, float scalar)
{

    return create_vector_2(vector.x * scalar, vector.y * scalar);

}

vector_2_t sub_vector_2(vector_2_t a, vector_2_t b)
{

    return create_vector_2(a.x - b.x, a.y - b.y);

}

vector_2_t sub_vector_2_linearly(vector_2_t vector, float scalar)
{

    return create_vector_2(vector.x - scalar, vector.y - scalar);

}

vector_2_t sum_vector_2(vector_2_t a, vector_2_t b)
{

    return create_vector_2(a.x + b.x, a.y + b.y);

}

vector_2_t sum_vector_2_linearly(vector_2_t vector, float scalar)
{

    return create_vector_2(vector.x + scalar, vector.y + scalar);

}
