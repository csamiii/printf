#include "main.h"
#include <stdlib.h>
#include <stdarg.h>

/**
 * check_format_specifier - checks for a valid format specifier
 * @format:  pointer to a string with all the characters passed
 *
 * Return: pointer to a valid function or NULL
 */

int (*check_format_specifier(const char *format))(va_list)
{
    unsigned int i;
    print_t f_list[] = {
        {"c", print_c},
        {"s", print_s},
        {"i", print_i},
        {"d", print_d},
        {"u", print_u},
        {"b", print_b},
        {"o", print_o},
        {"x", print_x},
        {"X", print_X},
        {"p", print_p},
        {"S", print_S},
        {"r", print_r},
        {"R", print_R},
        {NULL, NULL}};

    for (i = 0; f_list[i].t != NULL; i++)
    {
        if (*(f_list[i].t) == *format)
            break;
    }
    return (f_list[i].f);
}

/**
 * _printf - contains the string and parameters needed to print a formated string
 * @format: points to the string with all the desired characters/arguments
 * @ap: variable that refers to each argument in turn, argument pointer
 * Return: A count of characters to be printed
 */
int _printf(const char *format, ...)
{
    unsigned int i, count = 0;
    va_list ap;
    int (*f)(va_list);

    if (format == NULL)
        return (-1);

    va_start(ap, format);
    while (format[i])
    {
        for (i = 0; format[i] != '%' && format[i]; i++)
        {
            _putchar(format[i]);
            count++;
        }
        if (!format[i])
            return (count);
        f = check_format_specifier(&format[i + 1]);
        if (f != NULL)
        {
            count += f(ap);
            i += 2;
            continue;
        }
        if (!format[i + 1])
            return (-1);
        _putchar(format[i]);
        count++;
        if (format[i + 1] == '%')
            i += 2;
        else
            i++;
    }
    va_end(ap);
    return (count);

}
