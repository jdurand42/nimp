#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

long long  rivering(long long river);

int main()
{
    int r_1;
//    scanf("%d", &r_1);
    r_1 = 91004;
    fprintf(stderr, "%d\n", r_1);
    long long i = r_1 - 1;
    long long r_i;

    while (i > 1)
    {
        r_i = i;
        while (r_i != r_1 && r_i < r_1)
            r_i = rivering(r_i);
        if (r_i == r_1)
        {
            printf("YES\n");
            return (0);
        }
        i -= 2;
    }
    printf("NO\n");

    // Write an action using printf(). DON'T FORGET THE TRAILING \n
    // To debug: fprintf(stderr, "Debug messages...\n");
    return 0;
}

long long   rivering(long long river)
{
    long long buffer = river;

    while (river > 0) // attention
    {
        buffer = buffer + river % 10;
        river /= 10;
    }
    return (buffer);
}
