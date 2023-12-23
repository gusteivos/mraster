#include <vectors/vector4.h>

vector_4_t create_vector_4(float x, float y, float z, float w)
{

    vector_4_t _new_vector;
    
    _new_vector.x = x;
    
    _new_vector.y = y;
    
    _new_vector.z = z;
    
    _new_vector.w = w;
    
    return _new_vector;

}

vector_4_t create_vector_4_with_vector_2(vector_2_t vector2, float z, float w)
{

    vector_4_t _new_vector;
    
    _new_vector.vector3.vector2 = vector2;
    
    _new_vector.z = z;
    
    _new_vector.w = w;
    
    return _new_vector;

}

vector_4_t create_vector_4_with_vector_3(vector_3_t vector3, float w)
{
    
    vector_4_t _new_vector;
    
    _new_vector.vector3 = vector3;
    
    _new_vector.w = w;
    
    return _new_vector;

}

vector_4_t create_vector_4_with_elements(float *elements)
{

    vector_4_t _new_vector;
    
    _new_vector.elements[0] = elements[0];
    
    _new_vector.elements[1] = elements[1];
    
    _new_vector.elements[2] = elements[2];

    _new_vector.elements[3] = elements[3];

    return _new_vector;

}

double get_vector_4_length(vector_4_t vector)
{
 
    return sqrt((vector.x * vector.x) + (vector.y * vector.y) + (vector.z * vector.z) + (vector.w * vector.w));

}

vector_4_t normalize_vector_4(vector_4_t vector)
{

    double length = get_vector_4_length(vector);

    return create_vector_4(vector.x / length, vector.y / length, vector.z / length, vector.w / length);

}

vector_4_t div_vector_4(vector_4_t a, vector_4_t b)
{

    return create_vector_4(a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w);

}

vector_4_t div_vector_4_linearly(vector_4_t vector, float scalar)
{

    return create_vector_4(vector.x / scalar, vector.y / scalar, vector.z / scalar, vector.w / scalar);

}

vector_4_t mul_vector_4(vector_4_t a, vector_4_t b)
{

    return create_vector_4(a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w);

}

vector_4_t mul_vector_4_linearly(vector_4_t vector, float scalar)
{

    return create_vector_4(vector.x * scalar, vector.y * scalar, vector.z * scalar, vector.w * scalar);

}

vector_4_t sub_vector_4(vector_4_t a, vector_4_t b)
{

    return create_vector_4(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);

}

vector_4_t sub_vector_4_linearly(vector_4_t vector, float scalar)
{

    return create_vector_4(vector.x - scalar, vector.y - scalar, vector.z - scalar, vector.w - scalar);

}

vector_4_t sum_vector_4(vector_4_t a, vector_4_t b)
{

    return create_vector_4(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);

}

vector_4_t sum_vector_4_linearly(vector_4_t vector, float scalar)
{

    return create_vector_4(vector.x + scalar, vector.y + scalar, vector.z + scalar, vector.w + scalar);

}
