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
 * @brief        Scales all the elements of a vector by a given scalar.
 * 
 * @param vector The vector reference
 * @param scalar The scalar
 * @return int   The exit status of the function
 */
int Vector3d__scale(Vector3d* vector, int scalar);

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
 * @brief               Adds all of the elements of the two vectors together, and returns the result.
 * 
 * @param first_addend  The first vector in the set of the addition operation
 * @param second_addend The second vector in the set of the addition operation
 * @return Vector3d     The sum vector
 */
Vector3d Vector3d__add_from(Vector3d* first_addend, Vector3d* second_addend);

/**
 * @brief               Finds the dot product of the two given vectors.
 * 
 * @param first_vector  The first vector in the operation
 * @param second_vector The second vector in the operation
 * @return Vector3d     The calculated dot product of the first and second vectors
 */
double Vector3d__dot(Vector3d* first_vector, Vector3d* second_vector);

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