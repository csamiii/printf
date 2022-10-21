#include "main.h"
/**
 * print_unsigned - A function that prints an unsigned integer
 * @u: unsigned integer to be printed
 * Return: number of printed digits
 */

int print_u(va_list u)
{
    unsigned int a[10];
    unsigned int i , m = 1000000000, n, sum = 0;
    int count = 0;

    n = va_arg(u, unsigned int);
    a[0] = n / m;
    for (i = 1; i < 10; i++)
    {
        m /= 10;
        a[i] = (n / m) % 10;
    }
    for (i = 0; i < 10; i++)
    {
        sum += a[i];
        if (sum || i == 9)
        {
            _putchar('0' + a[i]);
            count++;
        }
    }
    return (count);
}
