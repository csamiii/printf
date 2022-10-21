#include "main.h"
/**
 * print_x - Prints an ASCII char value in
 * lowercase hexadecimal
 * @x: char to print in ASCII
 * Return: number of printed characters
 */

int print_x(va_list x)
{
    unsigned int a[8];
    unsigned int i, m = 268435456 /* (16 ^ 7) */, n, sum = 0;
    char diff;
    int count;

    n = va_arg(x, unsigned int);
    diff = 'a' - ':';
    a[0] = n / m;
    for (i = 1; i < 8; i++)
    {
        m /= 16;
        a[i] = (n / m) % 16;
    }
    for (i = 0; i < 8; i++)
    {
        sum += a[i];
        if (sum || i == 7)
        {
            if (a[i] < 10)
                _putchar('0' + a[i]);
            else
                _putchar('0' + diff + a[i]);
            count++;
        }
    }
    return (count);
}
