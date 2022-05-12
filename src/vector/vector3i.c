#include "vector3i.h"

Vector3i Vector3i__create(int x, int y, int z)
{
    Vector3i vector;
    vector.x = x;
    vector.y = y;
    vector.z = z;

    return vector;
}

Vector3i Vector3i__create_empty()
{
    Vector3i vector;
    vector.x = 0;
    vector.y = 0;
    vector.z = 0;

    return vector;
}

Vector3i Vector3i__copy(Vector3i* vector_original)
{
    if(vector_original == NULL)
        return Vector3i__create_empty();

    return Vector3i__create(
        vector_original->x, 
        vector_original->y, 
        vector_original->z);
}

int Vector3i__scale(Vector3i* vector, int scalar)
{
    if(vector == NULL)
        return EXIT_FAILURE;
    
    vector->x *= scalar;
    vector->y *= scalar;
    vector->z *= scalar;

    return EXIT_SUCCESS;
}

Vector3i Vector3i__add(Vector3i* first_addend, Vector3i* second_addend)
{
    if(first_addend  == NULL) return Vector3i__create_empty();
    if(second_addend == NULL) return Vector3i__create_empty();

    Vector3i sum = Vector3i__copy(first_addend);
    sum.x += second_addend->x;
    sum.y += second_addend->y;
    sum.z += second_addend->z;

    return sum;
}

Vector3i Vector3i__subtract(Vector3i* minuend, Vector3i* subtrahend)
{
    if(minuend    == NULL) return Vector3i__create_empty();
    if(subtrahend == NULL) return Vector3i__create_empty();

    Vector3i difference = Vector3i__copy(minuend);
    difference.x -= subtrahend->x;
    difference.y -= subtrahend->y;
    difference.z -= subtrahend->z;

    return difference;
}

double Vector3i__norm(Vector3i* vector)
{
    if(vector == NULL) return 0.0f;

    // Calculate the radicand of the norm.
    double radicand = vector->x * vector->x + 
                      vector->y * vector->y + 
                      vector->z * vector->z;

    return sqrt(radicand);
}

float Vector3i__normf(Vector3i* vector)
{
    if(vector == NULL) return 0.0f;

    // Calculate the radicand of the norm.
    float radicand = vector->x * vector->x + 
                     vector->y * vector->y + 
                     vector->z * vector->z;

    return sqrtf(radicand);
}

#define VECTOR3I__TO_STRING_FORMAT "Vector at [%d, %d, %d]"
int Vector3i__to_string(char* serialize, Vector3i* vector)
{
    if(serialize == NULL) return EXIT_FAILURE;
    if(vector    == NULL) return EXIT_FAILURE;
    
    sprintf(serialize, VECTOR3I__TO_STRING_FORMAT,
        vector->x, vector->y, vector->z
    );

    return EXIT_SUCCESS;
}

int Vector3i__print(Vector3i* vector)
{
    char string[50];
    if(Vector3i__to_string(string, vector))
        return EXIT_FAILURE;

    printf("%s\n", string);
    return EXIT_SUCCESS;
}