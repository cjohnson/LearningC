#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * @brief Represents a 3-dimensional vector in space.
 */
struct Vector3i
{ int x_1, x_2, x_3; }; 
typedef struct Vector3i Vector3i;

/**
 * @brief           Creates a new 3-dimensional vector.
 * 
 * @param x_1       1st value of the vector.
 * @param x_2       2nd value of the vector.
 * @param x_3       3rd value of the vector.
 * @return Vector3i The resulting vector.
 */
Vector3i Vector3i__create(int x_1, int x_2, int x_3);

/**
 * @brief           Creates a 3-dimensional vector at the origin.
 * 
 * @return Vector3i The resulting vector.
 */
Vector3i Vector3i__create_empty();

/**
 * @brief                 Copies the values of an existing vector into a new vector.
 * 
 * @param vector_original The vector to be copied
 * @return Vector3i       The newly created vector
 */
Vector3i Vector3i__copy(Vector3i* vector_original);

/**
 * @brief Scales all the elements of a vector by a given scalar.
 * 
 * @param vector The vector reference
 * @param scalar The scalar
 * @return int The exit status of the function
 */
int Vector3i__scale(Vector3i* vector, int scalar);

/**
 * @brief               Adds two vectors together, and returns the result.
 * 
 * @param first_addend  The first vector in the set of the addition operation
 * @param second_addend The second vector in the set of the addition operation
 * @return Vector3i     The sum vector
 */
Vector3i Vector3i__add(Vector3i* first_addend, Vector3i* second_addend);

/**
 * @brief               Subtracts the first vector (the minuend) from the second (the subtrahend).
 * 
 * @param first_addend  The minuend of the operation
 * @param second_addend The subtrahend of the operation
 * @return Vector3i     The difference vector
 */
Vector3i Vector3i__subtract(Vector3i* minuend, Vector3i* subtrahend);

/**
 * @brief        Calculate the norm of the vector (double)
 * 
 * @param vector The vector reference
 * @return double The norm of the vector
 */
double Vector3i__norm(Vector3i* vector);

/**
 * @brief        Calculate the norm of the vector (float)
 * 
 * @param vector The vector reference
 * @return float The norm of the vector
 */
float Vector3i__normf(Vector3i* vector);

/**
 * @brief           Serializes the vector into a readable string.
 * 
 * @param serialize The result string
 * @param vector    The vector reference
 * @return int      The exit status of the function
 */
int Vector3i__to_string(char* serialize, Vector3i* vector);

/**
 * @brief Prints the serialized form of the vector
 * 
 * @param vector The vector reference
 * @return int The exit status of the function
 */
int Vector3i__print(Vector3i* vector);