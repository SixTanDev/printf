#include "holberton.h"

/**
 * Write_String - Function that enters characters in the buffer.
 * @buffer: Data structure that handles the 1024 buffer.
 * @write: data structure that contains two function pointers, one to write
 *         to the buffer and the other to print the buffer.
 * @String: The character string that is entered into the buffer.
 */

void Write_String(Write *write, Buffer *buffer, char *String)
{
	if (*String)
	{
		if (buffer->Pointer_Init >= buffer->Pointer_End)
			write->Print(buffer);

		*(buffer->Pointer_Init) = *(String++);
		*(++buffer->Pointer_Init) = '\0';
		(buffer->Length)++;
		(buffer->Length_Total)++;

		if (buffer->Pointer_Init >= buffer->Pointer_End)
			write->Print(buffer);

		Write_String(write, buffer, String);
	}
}

/**
 * Print_String - Function that enters characters in the buffer
 *                when the argument list is passed a string.
 * @buffer: Data structure that handles the 1024 buffer.
 * @write: data structure that contains two function pointers, one to
 *         write to the buffer and the other to print the buffer.
 * @List_Argument: List of arguments passed to the _printf function.
 */

void Print_String(Write *write, Buffer *buffer, va_list List_Argument)
{
	char *String = va_arg(List_Argument, char *);

	if (String && *String)
		Write_String(write, buffer, String);
	else if (!String)
		Write_String(write, buffer, "(null)");
}

/**
 * Print_Character_Porcentaje - Function that enters characters in the buffer.
 *                              when the argument list is passed a Porcentaje.
 * @buffer: Data structure that handles the 1024 buffer.
 * @write: data structure that contains two function pointers, one to
 *         write to the buffer and the other to print the buffer.
 * @List_Arg: List of arguments passed to the _printf function.
 */

void Print_Character_Porcentaje(Write *write, Buffer *buffer, va_list List_Arg)
{
	(void)List_Arg;

	(void)write;

	WRITE_TO_LEETER('%');
}

/**
 * Print_Character_Character - Function that enters characters in the buffer.
 *                              when the argument list is passed a Character.
 * @buffer: Data structure that handles the 1024 buffer.
 * @write: data structure that contains two function pointers, one to write
 *         to the buffer and the other to print the buffer.
 * @List_Arg: List of arguments passed to the _printf function.
 */

void Print_Character_Character(Write *write, Buffer *buffer, va_list List_Arg)
{
	char Solve_Character = (char)va_arg(List_Arg, int);

	(void)write;

	if (Solve_Character)
	{
		WRITE_TO_LEETER(Solve_Character);
	}
	else
	{
		(buffer->Length_Total) += 2;
	}
}
