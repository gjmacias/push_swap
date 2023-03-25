#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

void    print( int *s, int n)
{
    int i;

    i = 0;
    while (i < n)
        printf("%d, ", s[i++]);
    printf("%d, ", s[i++]);
    printf("\n");
}

int atoi(const char *s)
{
    long long int n;
    int i;

    i = 0;
    n = 0;
   while (s[i] >= '0' && s[i] <= '9')
   {
	    n = (n * 10) + (s[i] - '0');
        if (n > INT_MAX)
            return (0);
        i++;
   }
   return ((int) n);
}

void    factorial(int n)
{
    int *i;
    int j;
    int x;

    i = malloc(sizeof(int) * n);
    j = 0;
    x = 0;
    while (j != n)
    {
        i[j++] = ++x;
    }
    print(i, n);
    free(i);
}

int main(int n, char *s[])
{
    if (n == 2)
    {
        factorial(atoi(s[n - 1]));
    }
    else
        printf("parameters nop.");
    return (0);
}