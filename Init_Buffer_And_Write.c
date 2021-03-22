#include "holberton.h"

/**
 * Buffer_Init - The structure buffer was initializer.
 * @buffer: Data structure that handles the 1024 buffer.
 */

void Buffer_Init(Buffer *buffer)
{
	buffer->Pointer_Init = buffer->Buffer;
	buffer->Pointer_End = buffer->Buffer + SIZE_BUFER;
	buffer->Length = buffer->Length_Total = 0;
}

/**
 * Write_Init - The structure write was initializer.
 * @write: data structure that contains two function pointers, one to write
 *         to the buffer and the other to print the buffer.
 * @Ptr_Write: Pointer to function.
 * @Ptr_Print: Pointer to funciotn
 */

void Write_Init(Write *write, void (*Ptr_Write)(Buffer *, char **, int), void (*Ptr_Print)(Buffer *))
{
	write->Write = Ptr_Write;
	write->Print = Ptr_Print;
}
