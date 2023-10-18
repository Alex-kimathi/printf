#include "main.h"
/**
 * _printf - a function to produce formatted
 * output to stdout
 *
 * @format: format specifier
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	va_start(args, format);
	if (format == NULL)
		return (-1);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			count++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == '%')
			{
				write(1, format, 1);
				count++;
			}
			else if (*format == 'c')
			{
				char c = va_arg(args, int);

				write(1, &c, 1);
				count++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(args, char *);

				write(1, str, strlen(str));
				count += strlen(str);
			}
			else if (*format == 'd')
			{
				int d = va_arg(args, int);
				if (d < 0)
				{
					d = -d;
					write(1, &d, 1);
				}
			}
		}
		format++;
	}
	va_end(args);
	return (count);
}
