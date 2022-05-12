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

    return Vector3i__create(first_addend->x_1 + second_addend->x_1,
                            first_addend->x_2 + second_addend->x_2,
                            first_addend->x_3 + second_addend->x_3);
}

Vector3i Vector3i__lincom(int first_scalar, Vector3i* first_vector, int second_scalar, Vector3i* second_vector)
{
    if(first_vector  == NULL) return Vector3i__create_empty();
    if(second_vector == NULL) return Vector3i__create_empty();

    return Vector3i__create(first_vector->x_1 * first_scalar + second_vector->x_1 * second_scalar,
                            first_vector->x_2 * first_scalar + second_vector->x_2 * second_scalar,
                            first_vector->x_3 * first_scalar + second_vector->x_3 * second_scalar);
}

Vector3i Vector3i__lincom_ext(Vector3i* first_vector, int scalar, Vector3i* second_vector)
{
    return Vector3i__lincom(1, first_vector, scalar, second_vector);
}

int Vector3i__dot(Vector3i* first_vector, Vector3i* second_vector)
{
    int result = 0;
    result += first_vector->x_1 * second_vector->x_1;
    result += first_vector->x_2 * second_vector->x_2;
    result += first_vector->x_3 * second_vector->x_3;

    return result;
}

void Vector3i__orthogonalize(Vector3i* ortho_vector_set[], Vector3i* input_vector_set[], int set_size)
{
    // Checks if the set is already orthogonalized.
    bool orthogonalized = true;
    for(int i = 1; i < set_size; ++i)
    {
        if(Vector3i__dot(input_vector_set[i], input_vector_set[i-1]) != 0)
            orthogonalized = false;
    }

    // Return the same set if the vectors are orthogonal
    if(orthogonalized)
    {
        for(int i = 0; i < set_size; ++i)
            ortho_vector_set[i] = input_vector_set[i];
        return;
    }

    // Perform the Gram-Schmidt procedure
    ortho_vector_set[0] = input_vector_set[0];
    for(int i = 1; i < set_size; ++i)
    {
        ortho_vector_set[i] = input_vector_set[i];
        for(int j = 0; j < i; ++j)
        {
            // Calculate the vector projections
            int numerator_dot_product = Vector3i__dot(ortho_vector_set[j], input_vector_set[i]);
            int denominator_dot_product = Vector3i__dot(ortho_vector_set[j], ortho_vector_set[j]);

            int quotient = numerator_dot_product / denominator_dot_product;
            if(quotient == 0) continue;

            // Remove the projections
            Vector3i temp = Vector3i__copy(ortho_vector_set[j]);
            Vector3i__scale(&temp, quotient);
            
            temp = Vector3i__subtract(input_vector_set[i], &temp);
            ortho_vector_set[i] = &temp;
        }
    }
}

Vector3i Vector3i__subtract(Vector3i* minuend, Vector3i* subtrahend)
{
    if(minuend    == NULL) return Vector3i__create_empty();
    if(subtrahend == NULL) return Vector3i__create_empty();

    return Vector3i__create(minuend->x_1 - subtrahend->x_1,
                            minuend->x_2 - subtrahend->x_2,
                            minuend->x_3 - subtrahend->x_3);
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