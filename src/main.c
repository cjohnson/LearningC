#include <stdio.h>
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

#define VECTOR3I__TO_STRING_FORMAT "Vector at [%d, %d, %d]"
/**
 * @brief           Serializes the vector into a readable string.
 * 
 * @param serialize The result string
 * @param vector    The vector reference
 * @return int      The exit status of the function (1 = failure, 0 = success)
 */
int Vector3i__to_string(char* serialize, Vector3i* vector)
{
    if(serialize == NULL) return 1;
    if(vector == NULL)      return 1;
    
    sprintf(serialize, VECTOR3I__TO_STRING_FORMAT,
        vector->x, vector->y, vector->z
    );

    return 0;
}

int main()
{
    Vector3i vector = Vector3i__create(0, 0, 0);

    char serialize[50];
    if(Vector3i__to_string(serialize, &vector))
        fprintf(stderr, "Failure!");
    printf("%s\n", serialize);

    printf("Adding 2 to the x position, 3 to the z position...\n");
    vector.x += 2;
    vector.z += 3;

    if(Vector3i__to_string(serialize, &vector))
        fprintf(stderr, "Failure!");
    printf("%s\n", serialize);

    printf("\nCalculating float norm...\n");
    printf("Norm = %f\n", Vector3i__normf(&vector));

    printf("\nCalculating double norm...\n");
    printf("Norm = %f\n", Vector3i__norm(&vector));
}