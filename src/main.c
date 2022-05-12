#include "vector/vector3d.h"

int main()
{
    Vector3d vector3d = Vector3d__create(2, 1, 3);
    Vector3d vector3d_empty = Vector3d__create_empty();
    Vector3d copy_of_vector3d = Vector3d__copy(&vector3d);

    Vector3d__print(&vector3d);
    Vector3d__print(&vector3d_empty);
    Vector3d__print(&copy_of_vector3d);

    printf("Norm of vector3d = %.3f\n", Vector3d__norm(&vector3d));

    Vector3d__scale(&copy_of_vector3d, 3);
    Vector3d__print(&copy_of_vector3d);

    Vector3d vec = Vector3d__add_from(&vector3d, &copy_of_vector3d);
    Vector3d__print(&vec);
}