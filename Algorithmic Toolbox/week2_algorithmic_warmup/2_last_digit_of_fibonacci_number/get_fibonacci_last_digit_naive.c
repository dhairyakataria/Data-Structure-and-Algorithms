
#include <stdio.h>

long int get_fibonacci_last_digit_naive(int n) 
{
    if (n <= 1)
        return n;

    long int previous = 0;
    long int current  = 1;
    long int tmp_previous;

    for (int i = 0; i < n - 1; ++i) 
    {
        tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current%10;
}




int main()
{
     int n, result;
    scanf("%d", &n);
    result = get_fibonacci_last_digit_naive(n%60);
    printf("%d\n", result);

    return 0;
}
