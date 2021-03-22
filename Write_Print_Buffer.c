#include "holberton.h"

void Print(Buffer *buffer);

/**
 * WRITE - Function that enters characters in the buffer.
 * @buffer: Data structure that handles the 1024 buffer.
 * @format: Double pointer to pointer that points to the string passed
 *          to _printf.
 * @Length: The total length written to the buffer by the function.
 */

void WRITE(Buffer *buffer, char **format, int Length)
{

	if ((!(**format)) || (**format == '%'))
	{
		buffer->Length_Total += Length;
	}
	else
	{
		if (buffer->Pointer_Init == buffer->Pointer_End)
			Print(buffer);

		*(buffer->Pointer_Init) = *((*format)++);
		*(++buffer->Pointer_Init) = '\0';

		if (buffer->Pointer_Init == buffer->Pointer_End)
			Print(buffer);

		WRITE(buffer, format, ++Length);
	}

}

/**
 * Print - This function prints what is in the buffer structure using
 *         a single write function
 * @buffer: Data structure that handles the 1024 buffer.
 */

void Print(Buffer *buffer)
{

	if (buffer->Pointer_Init - buffer->Buffer)
	{
		write(1, buffer->Buffer, buffer->Pointer_Init - buffer->Buffer);

		buffer->Pointer_Init = buffer->Buffer;
		*(buffer->Buffer) = '\0';
	}
	else
		return;
}
