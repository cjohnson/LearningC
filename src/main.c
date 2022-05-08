#include <stdio.h>

main()
{
    int celsius;
    for(int fahr = 0; fahr <= 300; fahr += 20)
    {
        celsius = 5 * (fahr - 32) / 9;
        printf("%d\t%d\n", fahr, celsius);
    }
}