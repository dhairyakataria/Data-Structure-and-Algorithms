
#include <stdio.h>

long int sum_last_digit_fibonacci_series(int n) 
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
    long int n, result;
    scanf("%ld", &n);
    result = sum_last_digit_fibonacci_series((n%60) + 2);
    if(result==0)
        result = 9;
    else
        result -= 1;
    printf("%ld\n", result);

    return 0;
}
