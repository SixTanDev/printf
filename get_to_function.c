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


void Type(char **format){

	To_Funct Array_Pointer[] = {

		{"c", NULL},
		{"s", NULL},
		{"di", NULL},
		{NULL, NULL}

	};
	(void) (*Pointer_Function)(Write *, Buffer *, va_list);

	Pointer_Function = (RType(Array_Pointe, format));
}
