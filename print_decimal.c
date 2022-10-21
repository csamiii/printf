#include "main.h"
/**
 * print_d - Prints a decimal base 10
 * @d: base 10 integer to be printed
 * Return: number of printed digits
 */

int print_d(va_list d)
{
    int a[10];
    int j, m = 1000000000, n = va_arg(d, int), sum, count = 0;

    a[0] = n / m;
    for (j = 1; j < 10; j++)
    {
        m /= 10;
        a[j] = (n / m) % 10;
    }
    if (n < 0)
    {
        _putchar('-');
        count++;
        for (j = 0; j < 10; j++)
            a[j] *= -1;
    }
    for (j = 0, sum = 0; j < 10; j++)
    {
        sum += a[j];
        if (sum != 0 || j == 9)
        {
            _putchar('0' + a[j]);
            count++;
        }
    }
    return (count);
}
