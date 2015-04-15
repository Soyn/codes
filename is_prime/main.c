#include <stdio.h>
#include <stdlib.h>
int Is_prime(int x);
int main()
{
    printf("%d",is_prime(9));
    return 0;
}
int is_prime(int x)
{
    int i;
    for(i = 2; i < x; ++i)
    {
        if(x % i)
        {
            return 0;
        }
    }
    return 1;
}
