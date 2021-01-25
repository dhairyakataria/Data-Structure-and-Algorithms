
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
    long int n, m, result1, result2;
    scanf("%ld %ld", &m, &n);
    result1 = sum_last_digit_fibonacci_series((m%60) + 1);
    result2 = sum_last_digit_fibonacci_series((n%60) + 2);
    if(result2<result1)
        result2 += 10;
    printf("%ld\n", result2-result1);

    return 0;
}
