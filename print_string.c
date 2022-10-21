#include "main.h"

/**
 * print_s - Prints a collection of characters
 * @s: string to be print
 * Return: i
 */
int print_s(va_list s)
{
    char *str = va_arg(s, char*);
    int i;

    if (str == NULL)
        str = "";
    for (i = 0; str[i]; i++)
    {
        _putchar(str[i]);
    }
    return (i);
}
