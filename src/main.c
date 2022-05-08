#include <stdio.h>

int main()
{
    float celsius;
    for(float fahr = 0.0; fahr <= 300.0; fahr += 20.0)
    {
        celsius = (5.0/9.0) * (fahr - 32.0);
        printf("%3.0f %6.1f\n", fahr, celsius);
    }
}