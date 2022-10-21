#include "main.h"
/**
 * print_p - Prints an address in memory
 * @p: address in memory to printed
 * Return: number of printed characters
 */

int print_p(va_list p)
{
    int count = 0;
    unsigned int a[16];
    unsigned int i, sum = 0;
    unsigned long n, m = 1152921504606846976;
    char *str = "(nil)";/*NULL*/

    n = va_arg(p, unsigned long);
    if (n == 0)
    {
        for (i = 0; str[i]; i++)
        {
            _putchar(str[i]);
            count++;
        }
        return (count);
    }
    _putchar('0');
    _putchar('x');
    count = 2;

    a[0] = n / m;
    for (i = 1; i < 16; i++)
    {
        m /= 16;
        a[i] = (n / m) % 16;
    }
    for (i = 0; i < 16; i++)
    {
        sum += a[i];
        if (sum || i == 15)
        {
            if (a[i] < 10)
                _putchar('0' + a[i]);
            else
                _putchar('0' + ('a' - ':') + a[i]);
            count++;
        }
    }
    return (count);
}
