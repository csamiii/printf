#include "main.h"
/**
 * print_o - Prints an unsigned int in octal notation
 * @o: unsigned integer to printed octal notation
 * Return: number of printed digits
 */

int print_o(va_list o)
{
    unsigned int a[11];
    unsigned int i, m = 1073741824 /* (8 ^ 10) */, n, sum = 0;
    int count = 0;

    n = va_arg(o, unsigned int);
    a[0] = n / m;
    for (i= 1; i < 11; i++)
    {
        m /= 8;
        a[i] = (n / m) % 8;
    }
    for (i = 0; i < 11; i++)
    {
        sum += a[i];
        if (sum || i == 10)
        {
            _putchar('0' + a[i]);
            count++;
        }
    }
    return (count);
}
