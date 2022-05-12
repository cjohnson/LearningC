#include "vector/vector3d.h"

int main()
{
    // printf("1");
    Vector3d vector_one = Vector3d__create(300, 2, 3);
    Vector3d vector_two = Vector3d__create(1, -2, -6);
    Vector3d vector_three = Vector3d__create(-2, 3, 5);
    
    // printf("1");
    Vector3d vectors[] = {vector_one, vector_two, vector_three};

    // printf("1");
    Vector3d** ortho_vectors = malloc(sizeof(vector_one) * 3);
    Vector3d** input_vectors = malloc(sizeof(vector_one) * 3);

    // printf("1");
    for(int i = 0; i < 3; ++i)
    {
        input_vectors[i] = &vectors[i];
        ortho_vectors[i] = &vectors[i];
    }

    // printf("1");
    Vector3d__orthonormalize(ortho_vectors, input_vectors, 3);

    Vector3d__print(ortho_vectors[0]);
    Vector3d__print(ortho_vectors[1]);
    Vector3d__print(ortho_vectors[2]);
}