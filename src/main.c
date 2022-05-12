#include "vector/vector3d.h"

int main()
{
    Vector3d v_1 = Vector3d__create(2, 1, 4);
    Vector3d v_2 = Vector3d__create(7, 4, 2);
    int a_1 = 2;
    int a_2 = 4;
    
    // Calculate a_1 * v_1 + a_2 * v_2
    Vector3d__add_linear(a_1, &v_1, a_2, &v_2);
    Vector3d__print(&v_1);
}