#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>

void    print( int *s, int n)
{
    int i;

    i = 0;
    while (i < n)
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

int    *make_malloc(int n)
{
        int *i;
        i = malloc(sizeof(int) * (n + 1));
        return (i);

}

void    fill(int *i, int n)
{
    int x;

    x = -1;
    while(++x < n)
        i[x] = x + 1;
    i[x] = 0;
}

void rotate(int *a, int n)
{
    int tmp;
    int i;

    i = 0;
    tmp = a[i];
    while (i < n)
    {
        a[i] = a[i + 1];
        i++;
    }
    a[i] = tmp;
}
void rrotate(int *a, int n)
{
    int tmp;

    tmp = a[n];
    while (n > 0)
    {
        a[n] = a[n - 1];
        n--;
    }
    a[n] = tmp;
}

void recursive( int *i, int n, const int k, int *proves)
{
    int x;
    int y;
    
    y = 0;
    if (n != 0)
    {
        x = y;
        recursive(i, n - 1, k, proves);
        while (y < n - 1)
        {
            //printf("maker r: position; i[%d], num rotating;%d\n",(k - n), n);
            rotate (&i[(k - n)], n - 1);
            recursive(i, n - 1, k, proves);
            y++;
        }
        while (x < n - 1)
        {
            //printf("make rr: position; i[%d], num rotating;%d\n",(k - n), n);
            rrotate(&i[(k - n)], n - 1);
            x++;
        }
    }
    else
    {
        print(i, k);
        *proves = *proves + 1;
    }
}

void factorial(int n)
{
    int *i;
    int proves;
    
    proves = 0;
    i = make_malloc(n);
    fill(i, n);
    recursive(i, n,(const int)n, &proves);
    printf("proves: %d\n", proves);
    free(i);
}

int main(int n, char *s[])
{
    int i;

    i = atoi(s[n - 1]);
    if (n == 2)
    {
        factorial(i);
    }
    else
        printf("parameters nop.");
    return (0);
}