#include "main.h"

/**
 * print_i - Prints an integer in base 10
 * @i: integer to be print in base 10
 *
 * Return: Number of digits to be printed
 */
int print_i(va_list i)
{
    int b[10];
    int j, m = 1000000000, n = va_arg(i, int), sum, count = 0;
    b[0] = n / m;
    for (j = 1; j < 10; j++)
    {
        m /= 10;
        b[j] = (n / m) % 10;
    }
    if (n < 0)
    {
        _putchar('-');
        count++;
        for (j = 0; j < 10; j++)
            b[j] *= -1;
    }
    for (j = 0, sum = 0; j < 10; j++)
    {
        sum += b[j];
        if (sum != 0 || j == 9)
        {
            _putchar('0' + b[j]);
            count++;
        }
    }
    return (count);
}
