#include "Holberton.h"

void Write_String(Write *write,Buffer *buffer, char *String)
{
	if (*String)
	{
		if (buffer->Pointer_Init >= buffer->Pointer_End)
			write->Print(buffer);

		*(buffer->Pointer_Init) = *(String)++;
		*(++buffer->Pointer_Init) = '\0';
		(buffer->Length)++;
		(buffer->Length_Total)++;

		if (buffer->Pointer_Init >= buffer->Pointer_End)
			write->Print(buffer);

		Write_String(write, buffer, String);
	}

	return ;
}


void Print_String(Write *write, Buffer *buffer, va_list List_Argument)
{

	char *String = va_arg(List_Argument, char *);
	write = NULL;

	if (String && *String)
		Write_String(write, buffer, String);
	else
		Write_String(write, buffer, "(null)");
}

void Print_Character_Porcentaje(Write *write, Buffer *buffer, va_list List_Argument)
{
	(void )List_Argument;

	WRITE_TO_LEETER('%');
}

void Print_Character_Character(Write *write, Buffer *buffer, va_list List_Argument)
{
	char Solve_Character = (char)va_arg(List_Argument, int);

	if (Solve_Character)
		WRITE_TO_LEETER(Solve_Character);
}
