
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
    long int n, result_1, result_2;
    scanf("%ld", &n);
    result_1 = get_fibonacci_last_digit_naive(n%60);
    result_2 = get_fibonacci_last_digit_naive((n+1)%60);
    printf("%d\n", (result_1*result_2)%10);

    return 0;
}
