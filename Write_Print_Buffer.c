#include "Holberton.h"

void Print(Buffer *buffer);

void WRITE(Buffer *buffer, char **format, int Length){

	if ((!(**format)) || (**format == '%')){
		buffer->Length_Total += Length;
	}else
	{
		if (buffer->Pointer_Init == buffer->Pointer_End)
			Print(buffer);

		*(buffer->Pointer_Init) = *((*format)++);
		*(++buffer->Pointer_Init) = '\0';
		buffer->Length++;

		if (buffer->Pointer_Init == buffer->Pointer_End)
			Print(buffer);

		WRITE(buffer, format, ++Length);
	}

}

void Print(Buffer *buffer){

	if (buffer->Length)
	{
		write(1, buffer->Buffer, buffer->Length);

		buffer->Pointer_Init = buffer->Buffer;
		*(buffer->Buffer) = '\0';
		buffer->Length = 0;
	}
	else
		return ;
}
