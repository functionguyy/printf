#include "main.h"

int print_spec_d_match(va_list i)
{
    int n = va_arg(i, int);
    int count = 0, divisor = 1;

    if (n == INT_MIN)
    {
        char min_str[] = "-2147483648";
        for (int i = 0; min_str[i] != '\0'; i++)
        {
            _putchar(min_str[i]);
            count++;
        }
        return count;
    }
    else if (n < 0)
    {
        _putchar('-');
        count++;
        n = -n;
    }

    if (n == 0)
    {
        _putchar('0');
        count++;
        return count;
    }

    /* Find the divisor that gives the first digit of n */
    while (n / divisor >= 10)
    {
        divisor *= 10;
    }

    /* Print each digit of n */
    while (divisor != 0)
    {
        _putchar('0' + (n / divisor));
        count++;
        n %= divisor;
        divisor /= 10;
    }

    return count;
}
