#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * @brief Represents a 3-dimensional vector in space.
 */
struct Vector3i
{
    int x, y, z;
}; typedef struct Vector3i Vector3i;

/**
 * @brief           Creates a new 3-dimensional vector.
 * 
 * @param x         X value of the vector.
 * @param y         Y value of the vector.
 * @param z         Z value of the vector.
 * @return Vector3i The resulting vector.
 */
Vector3i Vector3i__create(int x, int y, int z)
{
    Vector3i vector;
    vector.x = x;
    vector.y = y;
    vector.z = z;

    return vector;
}

/**
 * @brief           Creates a 3-dimensional vector at the origin.
 * 
 * @return Vector3i The resulting vector.
 */
Vector3i Vector3i__create_empty()
{
    Vector3i vector;
    vector.x = 0;
    vector.y = 0;
    vector.z = 0;

    return vector;
}

/**
 * @brief                 Copies the values of an existing vector
 * 
 * @param vector_original The vector to be copied
 * @return Vector3i       The newly created vector
 */
Vector3i Vector3i__copy(Vector3i* vector_original)
{
    if(vector_original == NULL)
        return Vector3i__create_empty();

    return Vector3i__create(
        vector_original->x, 
        vector_original->y, 
        vector_original->z);
}

/**
 * @brief Scales all the elements of a vector by a given scalar.
 * 
 * @param vector The vector reference
 * @param scalar The scalar
 * @return int The exit status of the function
 */
int Vector3i__scale(Vector3i* vector, int scalar)
{
    if(vector == NULL)
        return EXIT_FAILURE;
    
    vector->x *= scalar;
    vector->y *= scalar;
    vector->z *= scalar;

    return EXIT_SUCCESS;
}

/**
 * @brief        Calculate the norm of the vector (double)
 * 
 * @param vector The vector reference
 * @return double The norm of the vector
 */
double Vector3i__norm(Vector3i* vector)
{
    if(vector == NULL) return 0.0f;

    // Calculate the radicand of the norm.
    double radicand = vector->x * vector->x + 
                      vector->y * vector->y + 
                      vector->z * vector->z;

    return sqrt(radicand);
}

/**
 * @brief        Calculate the norm of the vector (float)
 * 
 * @param vector The vector reference
 * @return float The norm of the vector
 */
float Vector3i__normf(Vector3i* vector)
{
    if(vector == NULL) return 0.0f;

    // Calculate the radicand of the norm.
    float radicand = vector->x * vector->x + 
                     vector->y * vector->y + 
                     vector->z * vector->z;

    return sqrtf(radicand);
}

/**
 * @brief           Serializes the vector into a readable string.
 * 
 * @param serialize The result string
 * @param vector    The vector reference
 * @return int      The exit status of the function
 */
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

/**
 * @brief Prints the serialized form of the vector
 * 
 * @param vector The vector reference
 * @return int The exit status of the function
 */
int Vector3i__print(Vector3i* vector)
{
    char string[50];
    if(Vector3i__to_string(string, vector))
        return EXIT_FAILURE;

    printf("%s\n", string);
    return EXIT_SUCCESS;
}

int main()
{
    // Initial creation and printing
    Vector3i vector = Vector3i__create_empty();
    Vector3i__print(&vector);

    // Struct access testing
    printf("Adding 2 to the x position, 3 to the z position...\n");
    vector.x += 2;
    vector.z += 3;
    Vector3i__print(&vector);

    // Copy function testing
    printf("Copied Vector:\n");
    Vector3i copiedVector = Vector3i__copy(&vector);
    Vector3i__print(&copiedVector);

    // Scale testing
    Vector3i__scale(&copiedVector, 245);
    printf("Scaling copied vector. Original Vector:\n");
    Vector3i__print(&vector);
    printf("Copied vector:\n");
    Vector3i__print(&copiedVector);

    // Norm calculations
    printf("\nCalculating float norm...\n");
    printf("Norm = %f\n", Vector3i__normf(&vector));
    printf("\nCalculating double norm...\n");
    printf("Norm = %f\n", Vector3i__norm(&vector));
}