#include "holberton.h"

/**
 * RType - A pointer to a function, where we handle the format that
 *         is passed to _printf here we find out the question what
 *         happens if we write% s,% c,% d?
 * @Array_Pointer: An adequate structure where we store the character that is
 *                 assigned the % and where it corresponds to a
 *                 certain function depending on the character.
 * @fmt: Double pointer to pointer that points to the string
 *          passed to _print.
 * Return: Returns a function of type:
 *                    void (*Pointer_To_Function)(Write *, Buffer *, va_list)
 */

void (*RType(To_Funct * Array_Pointer, char **fmt))(Write *, Buffer *, va_list)
{
	if (!(Array_Pointer->Type)
	     || !*(Array_Pointer->Type)
	     || (*(Array_Pointer->Type)     == **fmt)
	     || (*(Array_Pointer->Type + 1) == **fmt))
		return (Array_Pointer->Pointer_Function);
	else
		return (RType(Array_Pointer + 1, fmt));
}

/**
 * Type -  A pointer to a function, where we handle the format that
 *         is passed to _printf here we find out the question what
 *         happens if we write% s,% c,% d?
 * @buffer: Data structure that handles the 1024 buffer.
 * @format: Double pointer to pointer that points to the string passed
 *          to _printf.
 * @write: data structure that contains two function pointers, one to write
 *         to the buffer and the other to print the buffer.
 * @List_Argument: List of arguments passed to the _printf function.
 */


void Type(Write *write, Buffer *buffer, char **format, va_list List_Argument)
{

	To_Funct Array_Pointer[] = {

		{"c", Print_Character},
		{"s", Print_String},
		{"%", Print_Character_Porcentaje},
		{"di", Print_Number},
		{NULL, NULL}

	};
	void (*Pointer_Function)(Write *, Buffer *, va_list);

	Pointer_Function = RType(Array_Pointer, format);

	if (Pointer_Function)
	{
		Pointer_Function(write, buffer, List_Argument);
		(*format)++;  /* Pasamos al siguiente caracter*/
	}
	else
	{
		WRITE_TO_LEETER('%');
		WRITE_TO_LEETER_FORMAT(format);
	}
}
