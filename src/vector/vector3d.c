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
    vector.x_1 = 0.0;
    vector.x_2 = 0.0;
    vector.x_3 = 0.0;

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

int Vector3d__copy_from(Vector3d* vector_original, Vector3d* new_values)
{
    if(vector_original == NULL) return EXIT_FAILURE;
    if(new_values      == NULL) return EXIT_FAILURE;

    vector_original->x_1 = new_values->x_1;
    vector_original->x_2 = new_values->x_2;
    vector_original->x_3 = new_values->x_3;
}

int Vector3d__scale(Vector3d* vector, double scalar)
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

int Vector3d__add_linear(double addend_scalar, Vector3d* addend, double additive_scalar, Vector3d* additive)
{
    if(Vector3d__scale(addend, addend_scalar))
        return EXIT_FAILURE;
    Vector3d additive_final = Vector3d__scale_from(additive, additive_scalar);

    if(Vector3d__add(addend, &additive_final))
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}

Vector3d Vector3d__subtract(Vector3d* minuend, Vector3d* subtrahend)
{
    if(minuend    == NULL) return Vector3d__create_empty();
    if(subtrahend == NULL) return Vector3d__create_empty();

    return Vector3d__create(minuend->x_1 - subtrahend->x_1,
                            minuend->x_2 - subtrahend->x_2,
                            minuend->x_3 - subtrahend->x_3);
}

double Vector3d__dot(Vector3d* first_vector, Vector3d* second_vector)
{
    int result = 0.0;
    result += first_vector->x_1 * second_vector->x_1;
    result += first_vector->x_2 * second_vector->x_2;
    result += first_vector->x_3 * second_vector->x_3;

    return result;
}

void Vector3d__orthogonalize(Vector3d* ortho_vector_set[], Vector3d* input_vector_set[], int set_size)
{
    // Checks if the set is already orthogonalized.
    bool orthogonalized = true;
    for(int i = 1; i < set_size; ++i)
    {
        if(Vector3d__dot(input_vector_set[i], input_vector_set[i-1]) != 0)
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

    double numerator_dot_product;
    double denominator_dot_product;
    double quotient;
    Vector3d projected_vector;
    for(int i = 1; i < set_size; ++i)
    {
        ortho_vector_set[i] = input_vector_set[i];
        for(int j = 0; j < i; ++j)
        {
            // Calculate the vector projections    
            numerator_dot_product = Vector3d__dot(ortho_vector_set[j], input_vector_set[i]);
            denominator_dot_product = Vector3d__dot(ortho_vector_set[j], ortho_vector_set[j]);

            quotient = numerator_dot_product / denominator_dot_product; 
            if(quotient == 0.0) continue;

            // Remove the projections
            projected_vector = Vector3d__copy(ortho_vector_set[j]);
            Vector3d__scale(&projected_vector, quotient);
            
            projected_vector = Vector3d__subtract(ortho_vector_set[i], &projected_vector);
            Vector3d__copy_from(ortho_vector_set[i], &projected_vector);
        }
    }
}

void Vector3d__orthonormalize(Vector3d* ortho_vector_set[], Vector3d* input_vector_set[], int set_size)
{
    Vector3d__orthogonalize(ortho_vector_set, input_vector_set, set_size);

    double norm;
    for(int i = 0; i < set_size; ++i)
    {
        norm = Vector3d__norm(ortho_vector_set[i]);
        Vector3d__scale(ortho_vector_set[i], 1 / norm);
    }
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

int Vector3d__print_set(Vector3d** set, int set_size)
{
    for(int i = 0; i < set_size; ++i)
    {
        if(Vector3d__print(set[i]))
            return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}