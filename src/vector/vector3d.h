#pragma once

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * @brief Represents a 3-dimensional vector. (double)
 */
struct Vector3d
{ double x_1, x_2, x_3; };
typedef struct Vector3d Vector3d;

/**
 * @brief           Creates a new 3-dimensional vector.
 * 
 * @param x_1       1st value of the vector.
 * @param x_2       2nd value of the vector.
 * @param x_3       3rd value of the vector.
 * @return Vector3d The resulting vector.
 */
Vector3d Vector3d__create(double x_1, double x_2, double x_3);

/**
 * @brief           Creates a 3-dimensional vector at the origin.
 * 
 * @return Vector3d The resulting vector.
 */
Vector3d Vector3d__create_empty();

/**
 * @brief                 Copies the values of an existing vector into a new vector.
 * 
 * @param vector_original The vector to be copied
 * @return Vector3d       The newly created vector
 */
Vector3d Vector3d__copy(Vector3d* vector_original);

/**
 * @brief                 Copies the values of a vector.
 * 
 * @param vector_original The vector to copy values into
 * @param new_values      The vector whose values are to be copied
 * @return Vector3d       The newly created vector
 */
int Vector3d__copy_from(Vector3d* vector_original, Vector3d* new_values);

/**
 * @brief        Scales all the elements of a vector by a given scalar.
 * 
 * @param vector The vector reference
 * @param scalar The scalar
 * @return int  The exit status of the function
 */
int Vector3d__scale(Vector3d* vector, double scalar);

/**
 * @brief                 Scales all the elements of a vector by a given scalar, then returns the result.
 * 
 * @param input_vector    The vector reference
 * @param scalar          The scalar
 * @return Vector3d       The scaled vector
 */
Vector3d Vector3d__scale_from(Vector3d* input_vector, int scalar);

/**
 * @brief          Adds all of the elements of the additive to the addend, modifying the addend.
 * 
 * @param addend   The vector to be added to
 * @param additive The vector contents to add to the addend
 * @return int     The exit status
 */
int Vector3d__add(Vector3d* addend, Vector3d* additive);

/**
 * @brief                 Compute the result of a sum of scaled vectors (a linear combination)
 * 
 * @param addend_scalar   The scalar to be multiplied by the vector addend
 * @param addend          The vector to be modified
 * @param additive_scalar The scalar to be multiplied by the vector additive
 * @param additive        The vector whose contents will be added to the addend
 * @return int            The exit code
 */
int Vector3d__add_linear(double addend_scalar, Vector3d* addend, double additive_scalar, Vector3d* additive);

/**
 * @brief               Adds all of the elements of the two vectors together, and returns the result.
 * 
 * @param first_addend  The first vector in the set of the addition operation
 * @param second_addend The second vector in the set of the addition operation
 * @return Vector3d     The sum vector
 */
Vector3d Vector3d__add_from(Vector3d* first_addend, Vector3d* second_addend);

/**
 * @brief               Subtracts the first vector (the minuend) from the second (the subtrahend).
 * 
 * @param first_addend  The minuend of the operation
 * @param second_addend The subtrahend of the operation
 * @return Vector3d     The difference vector
 */
Vector3d Vector3i__subtract(Vector3d* minuend, Vector3d* subtrahend);

/**
 * @brief               Finds the dot product of the two given vectors.
 * 
 * @param first_vector  The first vector in the operation
 * @param second_vector The second vector in the operation
 * @return Vector3d     The calculated dot product of the first and second vectors
 */
double Vector3d__dot(Vector3d* first_vector, Vector3d* second_vector);

/**
 * @brief                  Finds an orthogonal set of Vector3d using the Gram-Schmidt Orthogonalization procedure
 * 
 * @param ortho_vector_set The resulting set of orthogonal vectors
 * @param input_vector_set The original set of vectors
 * @param set_size         The size of the sets
 */
void Vector3d__orthogonalize(Vector3d* ortho_vector_set[], Vector3d* input_vector_set[], int set_size);

/**
 * @brief                  Finds an orthonormal set of Vector3d using the Gram-Schmidt Orthogonalization procedure
 * 
 * @param ortho_vector_set The resulting set of orthonormal vectors
 * @param input_vector_set The original set of vectors
 * @param set_size         The size of the sets
 */
void Vector3d__orthonormalize(Vector3d* ortho_vector_set[], Vector3d* input_vector_set[], int set_size);

/**
 * @brief         Calculate the norm of the vector (double)
 * 
 * @param vector  The vector reference
 * @return double The norm of the vector
 */
double Vector3d__norm(Vector3d* vector);

/**
 * @brief           Serializes the vector into a readable string.
 * 
 * @param serialize The result string
 * @param vector    The vector reference
 * @return int      The exit status of the function
 */
int Vector3d__to_string(char* serialize, Vector3d* vector);

/**
 * @brief        Prints the serialized form of the vector
 * 
 * @param vector The vector reference
 * @return int   The exit status of the function
 */
int Vector3d__print(Vector3d* vector);

/**
 * @brief          Prints the serialized form of the vector for each vector in the set
 * 
 * @param set      The vector set
 * @param set_size The size of the vector set
 * @return int     The exit status of the function
 */
int Vector3d__print_set(Vector3d** set, int set_size);