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

int Vector3d__scale(Vector3d* vector, int scalar)
{
    if(vector == NULL)
        return EXIT_FAILURE;
    
    vector->x_1 *= scalar;
    vector->x_2 *= scalar;
    vector->x_3 *= scalar;

    return EXIT_SUCCESS;
}

Vector3d Vector3d__scale_from(Vector3d* input_vector, int scalar)
{
    Vector3d vector = Vector3d__create_empty();
    if(input_vector == NULL)
        return vector;
    
    vector.x_1 = scalar * input_vector->x_1;
    vector.x_2 = scalar * input_vector->x_2;
    vector.x_3 = scalar * input_vector->x_3;

    return vector;
}

int Vector3d__add(Vector3d* addend, Vector3d* additive)
{
    if(addend   == NULL) return EXIT_FAILURE;
    if(additive == NULL) return EXIT_FAILURE;

    addend->x_1 += additive->x_1;
    addend->x_2 += additive->x_2;
    addend->x_3 += additive->x_3;

    return EXIT_SUCCESS;
}

Vector3d Vector3d__add_from(Vector3d* first_addend, Vector3d* second_addend)
{
    if(first_addend  == NULL) return Vector3d__create_empty();
    if(second_addend == NULL) return Vector3d__create_empty();

    return Vector3d__create(first_addend->x_1 + second_addend->x_1,
                            first_addend->x_2 + second_addend->x_2,
                            first_addend->x_3 + second_addend->x_3);
}

double Vector3d__norm(Vector3d* vector)
{
    if(vector == NULL) return 0.0f;

    // Calculate the radicand of the norm.
    double radicand = vector->x_1 * vector->x_1 + 
                      vector->x_2 * vector->x_2 + 
                      vector->x_3 * vector->x_3;

    return sqrt(radicand);
}

#define VECTOR3D__TO_STRING_FORMAT "Vector3d[%.3f, %.3f, %.3f]"
int Vector3d__to_string(char* serialize, Vector3d* vector)
{
    if(serialize == NULL) return EXIT_FAILURE;
    if(vector    == NULL) return EXIT_FAILURE;
    
    sprintf(serialize, VECTOR3D__TO_STRING_FORMAT,
        vector->x_1, vector->x_2, vector->x_3
    );

    return EXIT_SUCCESS;
}

int Vector3d__print(Vector3d* vector)
{
    char string[50];
    if(Vector3d__to_string(string, vector))
        return EXIT_FAILURE;

    printf("%s\n", string);
    return EXIT_SUCCESS;
}