#include "vector/vector3d.h"

int main()
{
    Vector3d vector3d = Vector3d__create(2, 1, 3);
    Vector3d vector3d_empty = Vector3d__create_empty();
    Vector3d copy_of_vector3d = Vector3d__copy(&vector3d);
}