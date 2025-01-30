#include <stdarg.h>
#include <unistd.h>

void ft_putchar(char c, int *count)
{
	write(1,&c, 1);
	(*count)++;
}

void ft_putstr(char *str, int *count)
{
	if (!str)
		str = "(null)";
	while (*str)
		ft_putchar(*str++, count);
}

void ft_putnbr(int number, int *count)
{
	char *symbols = "0123456789";
	long n = number;
	if (n < 0) {
		ft_putchar('-', count);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr(n / 10, count);
	ft_putchar(symbols[n % 10], count);
}

void ft_puthex(unsigned int number, int *count) {
	char *symbols = "0123456789abcdef";
	if (number >= 16)
		ft_puthex(number / 16, count);
	ft_putchar(symbols[number % 16], count);
}

int ft_printf(const char *format, ...)
{
    int count = 0;
    va_list arguments;

    va_start(arguments, format);
    while (*format)
    {
    	if (*format == '%')
    	{
    		format++;
    		if (*format == 's')
    			ft_putstr(va_arg(arguments, char *), &count);
    		else if (*format == 'd')
    			ft_putnbr(va_arg(arguments, int), &count);
    		else if (*format == 'x')
    			ft_puthex(va_arg(arguments, unsigned int), &count);
    	}
    	else
			ft_putchar(*format, &count);

		format++;
    }
    va_end(arguments);
    return count;
}