#include "vector/vector3i.h"

int main()
{
    Vector3i first_vector =  Vector3i__create(1, 0, 0);
    Vector3i second_vector = Vector3i__create(3, 2, 5);
    Vector3i third_vector =  Vector3i__create(0, 2, 4);
    Vector3i vectors[] = {first_vector, second_vector, third_vector};

    Vector3i** input_vectors = malloc(sizeof(first_vector) * 3);
    input_vectors[0] = &vectors[0];
    input_vectors[1] = &vectors[1];
    input_vectors[2] = &vectors[2];

    printf("Dot product of the vectors: %d\n", Vector3i__dot(&first_vector, &second_vector));

    Vector3i** ortho_vectors = malloc(sizeof(first_vector) * 3);
    Vector3i__orthogonalize(ortho_vectors, input_vectors, 3);
    for(int i = 0; i < 3; i++)
    {
        // printf("%d\n", i);
        Vector3i__print(ortho_vectors[i]);
    }
}