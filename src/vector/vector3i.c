#include "vector3i.h"

Vector3i Vector3i__create(int x_1, int x_2, int x_3)
{
    Vector3i vector;
    vector.x_1 = x_1;
    vector.x_2 = x_2;
    vector.x_3 = x_3;

    return vector;
}

Vector3i Vector3i__create_empty()
{
    Vector3i vector;
    vector.x_1 = 0;
    vector.x_2 = 0;
    vector.x_3 = 0;

    return vector;
}

Vector3i Vector3i__copy(Vector3i* vector_original)
{
    if(vector_original == NULL)
        return Vector3i__create_empty();

    return Vector3i__create(
        vector_original->x_1, 
        vector_original->x_2, 
        vector_original->x_3);
}

int Vector3i__scale(Vector3i* vector, int scalar)
{
    if(vector == NULL)
        return EXIT_FAILURE;
    
    vector->x_1 *= scalar;
    vector->x_2 *= scalar;
    vector->x_3 *= scalar;

    return EXIT_SUCCESS;
}

Vector3i Vector3i__add(Vector3i* first_addend, Vector3i* second_addend)
{
    if(first_addend  == NULL) return Vector3i__create_empty();
    if(second_addend == NULL) return Vector3i__create_empty();

    Vector3i sum = Vector3i__copy(first_addend);
    sum.x_1 += second_addend->x_1;
    sum.x_2 += second_addend->x_2;
    sum.x_3 += second_addend->x_3;

    return sum;
}

Vector3i Vector3i__subtract(Vector3i* minuend, Vector3i* subtrahend)
{
    if(minuend    == NULL) return Vector3i__create_empty();
    if(subtrahend == NULL) return Vector3i__create_empty();

    Vector3i difference = Vector3i__copy(minuend);
    difference.x_1 -= subtrahend->x_1;
    difference.x_2 -= subtrahend->x_2;
    difference.x_3 -= subtrahend->x_3;

    return difference;
}

double Vector3i__norm(Vector3i* vector)
{
    if(vector == NULL) return 0.0f;

    // Calculate the radicand of the norm.
    double radicand = vector->x_1 * vector->x_1 + 
                      vector->x_2 * vector->x_2 + 
                      vector->x_3 * vector->x_3;

    return sqrt(radicand);
}

float Vector3i__normf(Vector3i* vector)
{
    if(vector == NULL) return 0.0f;

    // Calculate the radicand of the norm.
    float radicand = vector->x_1 * vector->x_1 + 
                     vector->x_2 * vector->x_2 + 
                     vector->x_3 * vector->x_3;

    return sqrtf(radicand);
}

#define VECTOR3I__TO_STRING_FORMAT "Vector3i[%d, %d, %d]"
int Vector3i__to_string(char* serialize, Vector3i* vector)
{
    if(serialize == NULL) return EXIT_FAILURE;
    if(vector    == NULL) return EXIT_FAILURE;
    
    sprintf(serialize, VECTOR3I__TO_STRING_FORMAT,
        vector->x_1, vector->x_2, vector->x_3
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