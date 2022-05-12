#include "vector3d.h"

Vector3d Vector3d__create(double x_1, double x_2, double x_3)
{
    Vector3d vector;
    vector.x_1 = x_1;
    vector.x_2 = x_2;
    vector.x_3 = x_3;

    return vector;
}

Vector3d Vector3d__create_empty()
{
    Vector3d vector;
    vector.x_1 = 0.0d;
    vector.x_2 = 0.0d;
    vector.x_3 = 0.0d;

    return vector;
}

Vector3d Vector3d__copy(Vector3d* vector_original)
{
    if(vector_original == NULL)
        return Vector3d__create_empty();
    
    return Vector3d__create(
        vector_original->x_1,
        vector_original->x_2,
        vector_original->x_3);
}