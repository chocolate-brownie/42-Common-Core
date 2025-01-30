#include <stdarg.h>
#include <unistd.h>

void handle_string(char *str, int *count)
{
    if (!str)
        str = "(null)";
    while (*str)
    {
        write(1, str, 1);
        (*count)++;
        str++;
    }
}

void handle_decimal(int n, int *count)
{
    char    *symbols;
    long    num;

    symbols = "0123456789";
    num = n;
    if (num < 0)
    {
        write(1, "-", 1);
        (*count)++;
        num = -num;
    }
    if (num >= 10)
        handle_decimal(num / 10, count);
    write(1, &symbols[num % 10], 1);
    (*count)++;
}

void handle_hex(unsigned int n, int *count)
{
    char    *symbols;

    symbols = "0123456789abcdef";
    if (n >= 16)
        handle_hex(n / 16, count);
    write(1, &symbols[n % 16], 1);
    (*count)++;
}

int ft_printf(const char *format, ...)
{
    va_list args;
    int     count;

    count = 0;
    va_start(args, format);
    while (*format)
    {
        if (*format == '%')
        {
            format++;
            if (*format == 's')
                handle_string(va_arg(args, char *), &count);
            else if (*format == 'd')
                handle_decimal(va_arg(args, int), &count);
            else if (*format == 'x')
                handle_hex(va_arg(args, unsigned int), &count);
        }
        else
        {
            write(1, format, 1);
            count++;
        }
        format++;
    }
    va_end(args);
    return (count);
}
