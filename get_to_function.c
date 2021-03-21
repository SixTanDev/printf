#include "Holbeton.h"

void (*RType(To_Funct *Array_Pointer, char **format))(Write *, Buffer *, va_list)
{
	if (  !*(Array_Pointer->Type)
	   || (*(Array_Pointer->Type)     == **format)
	   || (*(Arrat_Pointer->Type + 1) == **format))
		return (Array_Pointer->Pointer_Function);
	else
		return (RType(Array_Pointer + 1, format));
}


void Type(Write *write, Buffer *buffer, char **format, va_list List_Argument){

	To_Funct Array_Pointer[] = {

		{"c", Print_Character},
		{"s", Print_String},
		{"di", NULL},
		{"%", Print_Character_Porcentaje},
		{NULL, NULL}

	};
	(void) (*Pointer_Function)(Write *, Buffer *, va_list);

	Pointer_Function = (RType(Array_Pointe, format));
	Pointer_Function(write, buffer, List_Argument);
}
