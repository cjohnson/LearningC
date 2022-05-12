#include "vector/vector3i.h"

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