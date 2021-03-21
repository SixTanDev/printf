#include "Holberton.h"

/*
 * Isspace: Verifica si hay espacios o no.
 */

int Isspace(char **format, int space){

	if (!(**format) || (**format != ' '))
		return space;
	else{
		(*format)++;
		return (Isspace(format, ++space));
	}
}


/*
 * _Printf: Esta función me recorrerá el format y me analizará el carácter
 *          Porcetaje.  (Esta función es recursiva).
 *
 */

int _Printf
(Write *write, Buffer *buffer, char **format, va_list List_Argument)
{
	if (!(*format) || !(**format))
		return (buffer->Length_Total);
	else
	{
		write->Write(buffer, format, 0);
		if (**format == '%')
		{
			int Space = 0;

			++(*format);
			Space = Isspace(format, 0); /* verificamos si hay espacios entre el % y el Type=(c,d,i,s...)*/

			if (!(**format) || (**format))
			{
				(*format) -= (++Space);          /* Regresa el format a apuntar al carater % */
				WRITE_TO_LEETER_FORMAT(format);  /* Macro entontrada en Holberton.h*/

			}
		}
		return (_Printf(write, buffer, format, List_Argument));
	}
}

/*
 * _printf: Esta función me inicializará la estructura de datos adecuada
 *          Para el manejo del buffer y la estructura de datos
 *          que escribirá y imprimirá lo que hay en el bufer.
 */

int _printf(char *format, ...)
{
/* Inicializamos variables */


	Write write;
	va_list Lista_Arguments;
	Buffer buffer;
/* Inicializamos las funciones de write y el Buffer */

	Write_Init(&write, WRITE, Print);
	Buffer_Init(&buffer);

	va_start(Lista_Arguments, format);
	_Printf(&write, &buffer, &format, Lista_Arguments);
	va_end(Lista_Arguments);

	write.Print(&buffer);

	return (buffer.Length_Total);
}
