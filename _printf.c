#include "holberton.h"

/**
 * Isspace - checks if there is a space between the% and the
 *          character that follows it.
 * @format: Double pointer to pointer that points to the string passed
 *          to _printf.
 * @space: Total number of spaces.
 * Return: Total number of spaces.
 */

int Isspace(char **format, int space)
{

	if (!(**format) || (**format != ' '))
	{
		return (space);
	}
	else
	{
		(*format)++;
		return (Isspace(format, ++space));
	}
}


/**
 * _Printf - Esta función me recorrerá el format y me analizará el carácter
 *          Porcetaje.  (Esta función es recursiva).
 * @buffer: Data structure that handles the 1024 buffer.
 * @format: Double pointer to pointer that points to the string passed
 *          to _printf.
 * @write: data structure that contains two function pointers, one to write
 *         to the buffer and the other to print the buffer.
 * @List_Argument: List of arguments passed to the _printf function.
 *
 * Return: Total number of Character.
 */


int _Printf(Write *write, Buffer *buffer, char **format, va_list List_Argument)
{
	if (!(**format))
	{
		return (buffer->Length_Total);
	}
	else
	{
		write->Write(buffer, format, 0);

		if (**format == '%')
		{
			int Space = 0;

			++(*format);

/* verificamos si hay espacios entre el % y el Type=(c,d,i,s...)*/
			Space = Isspace(format, 0);

			if (!(**format))
			{
/* Regresa el format a apuntar al carater % */
/* Macro entontrada en Holberton.h*/
				(*format) -= (++Space);
				WRITE_TO_LEETER_FORMAT(format);
			}
			else
				Type(write, buffer, format, List_Argument);

		}
		return (_Printf(write, buffer, format, List_Argument));
	}
}

/**
 * Error_Format - Validate if the format was written in this way
 *                "%    " or "%"
 * @format: pointer to format .
 * Return: 0 if the format is "%" or "%   ", 1 otherwase.
 */

int Error_Format(char *format)
{
	if (!(format) || !(*format))
		return (0);
	else if (((*format) != '%' || (*(format + 1) == '%')) &&
		 (*format) != ' ')
		return (1);
	else
		return (Error_Format(++format));
}

/**
 * _printf - This function will initialize me the proper data structure
 *          For handling the buffer and data structure
 *          that will write and print what's in the buffer.
 * @format: Double pointer to pointer that points to the string passed
 *          _print
 * Return: Total number of Character.
 */

int _printf(const char *format, ...)
{
/* Inicializamos variables */

	Write write;
	va_list Lista_Arguments;
	Buffer buffer;

/* Inicializamos las funciones de write y el Buffer */

	Write_Init(&write, WRITE, Print);
	Buffer_Init(&buffer);

	va_start(Lista_Arguments, format);
	/* 0: si format es igual a "%   " or "%" */
	if (Error_Format((char *)format))
		_Printf(&write, &buffer, (char **)&format, Lista_Arguments);
	else
		buffer.Length_Total = -1;
	va_end(Lista_Arguments);

	write.Print(&buffer);
	return (buffer.Length_Total);
}
