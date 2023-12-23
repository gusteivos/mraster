#include <vectors/vector3.h>

vector_3_t create_vector_3(float x, float y, float z)
{

    vector_3_t _new_vector;
    
    _new_vector.x = x;
    
    _new_vector.y = y;
    
    _new_vector.z = z;
    
    return _new_vector;

}

vector_3_t create_vector_3_with_vector_2(vector_2_t vector2, float z)
{

    vector_3_t _new_vector;

    _new_vector.vector2 = vector2;
    
    _new_vector.z = z;

    return _new_vector;

}

vector_3_t create_vector_3_with_elements(float *elements)
{

    vector_3_t _new_vector;
    
    _new_vector.elements[0] = elements[0];
    
    _new_vector.elements[1] = elements[1];
    
    _new_vector.elements[2] = elements[2];

    return _new_vector;

}

double get_vector_3_length(vector_3_t vector)
{

    return sqrt((vector.x * vector.x) + (vector.y * vector.y) + (vector.z * vector.z));

}

vector_3_t normalize_vector_3(vector_3_t vector)
{

    double length = get_vector_3_length(vector);

    return create_vector_3(vector.x / length, vector.y / length, vector.z / length);

}

vector_3_t div_vector_3(vector_3_t a, vector_3_t b)
{

    return create_vector_3(a.x / b.x, a.y / b.y, a.z / b.z);

}

vector_3_t div_vector_3_linearly(vector_3_t vector, float scalar)
{

    return create_vector_3(vector.x / scalar, vector.y / scalar, vector.z / scalar);

}

vector_3_t mul_vector_3(vector_3_t a, vector_3_t b)
{

    return create_vector_3(a.x * b.x, a.y * b.y, a.z * b.z);

}

vector_3_t mul_vector_3_linearly(vector_3_t vector, float scalar)
{

    return create_vector_3(vector.x * scalar, vector.y * scalar, vector.z * scalar);

}

vector_3_t sub_vector_3(vector_3_t a, vector_3_t b)
{

    return create_vector_3(a.x - b.x, a.y - b.y, a.z - b.z);

}

vector_3_t sub_vector_3_linearly(vector_3_t vector, float scalar)
{

    return create_vector_3(vector.x - scalar, vector.y - scalar, vector.z - scalar);

}

vector_3_t sum_vector_3(vector_3_t a, vector_3_t b)
{

    return create_vector_3(a.x + b.x, a.y + b.y, a.z + b.z);

}

vector_3_t sum_vector_3_linearly(vector_3_t vector, float scalar)
{

    return create_vector_3(vector.x + scalar, vector.y + scalar, vector.z + scalar);

}
