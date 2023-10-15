#include "main.h"
/**
 * _printf - a function to produce formatted
 * output to stdout
 * @c: handles char
 * @%: handles the sign
 * @s: handles a string
 *
 * @format: format specifier
 * Return: the number of characters printed
 */
/*
int _printf(const char *format, ...)
{
	unsigned int i, s_count;
	unsigned int count = 0;

	va_list args;
	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			writec(format[i]);
		}
		else if (format[i + 1] == 'c')
		{
			writec(va_arg(args, int));
			i++;
		}
		else if (format[i + 1] == 's')
		{
			s_count = writes(va_arg(args, char *));
			i++;
			count += (s_count - 1);
		}
		else if (format[i + 1] == '%')
		{
			writec('%');
		}
		count++;
	}

	va_end(args);
	return (count);
}
*/
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	va_start(args, format);

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
			if (*format == '/0')
				break;
			if (*format == '%')
				write(1, format, 1);
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
				count = count + strlen(str);
			}
		}
		format++;
	}
	va_end(args);
	return (count);
}
