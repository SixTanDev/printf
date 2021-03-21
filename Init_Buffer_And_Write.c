#include "Holberton.h"

void Buffer_Init(Buffer *buffer)
{
	buffer->Pointer_Init = buffer->Buffer;
	buffer->Pointer_End = buffer->Buffer + SIZE_BUFER;
	buffer->Length = buffer->Length_Total = 0;
}

void Write_Init
(Write *write, void (*Function_Pointer_Write)(Buffer *, char **, int), void (*Function_Pointer_Print)(Buffer *)){

	write->Write = Function_Pointer_Write;
	write->Print = Function_Pointer_Print;
}
