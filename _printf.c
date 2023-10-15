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
	unsigned int i, s_count;
	unsigned int count = 0;

	va_list args;
	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			writec(format[i]);    /*bado sijadefine function ya kuwrite char*/
		}
		else if (format[i + 1] == 'c')
		{
			writec(va_arg(args, int));   /*see above*/
			i++;
		}
		else if (format[i + 1] == 's')
		{
			s_count = writes(va_arg(args, char *));  /* bado sijadefine function ya kuwrite string*/
			i++;
			count += (s_count - 1);   /* this was a little confusing */
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
